# Teclado: acentuação e símbolos não saem no cliente (Linux)

## Sintoma

Do servidor para um **cliente Linux**, as letras e os dígitos saem normalmente,
mas **acentuação** (á, ã, é, ó…), **ç**, **~**, **^**, **'**, **"** e às vezes
**/** e **?** não aparecem — nada é digitado ou sai o caractere errado.

O mouse e o restante do teclado funcionam: não é problema de conexão, de
fingerprint TLS nem de versão. Falha só o *conteúdo* de certos caracteres.

## Causa

No X11, o Xorg aplica o layout de `/etc/default/keyboard` (ex.: `br`/`abnt2`)
**apenas aos devices físicos** de teclado. O device **CORE** (`Virtual core
keyboard`) e o **`Virtual core XTEST keyboard`** ficam com o layout default
**`us`** do Xorg.

O cliente OpenFlowKey no Linux depende desse mapa em dois momentos:

1. **Tradução** — lê o mapa do CORE/XTEST (`XkbGetMap(XkbUseCoreKbd)` ou
   `XGetKeyboardMapping`) para converter o keysym recebido do servidor no
   keycode local;
2. **Injeção** — envia as teclas com **XTest**, ou seja, no device **XTEST**.

Sem as teclas mortas (`dead_acute`, `dead_tilde`, `dead_grave`,
`dead_diaeresis`) e sem `ccedilla` nesse mapa, o mapeamento desses caracteres
falha. O teclado físico do cliente continua correto porque usa o mapa do
próprio device — daí o sintoma ser "só do servidor para o cliente".

No log do cliente aparecem estas linhas, que **são informativas** (o servidor
`us intl` é idioma `en`, o cliente `br` é `pt`):

```
INFO: local layouts: pt
INFO: remote layouts: en
WARNING: server layouts missing on this computer: en
WARNING: current server layout is not installed on client
```

A tradução continua a funcionar desde que o mapa do CORE tenha os keysyms
necessários. O que denuncia o problema é o **mapa do CORE/XTEST** estar em
`English (US)` (ou em qualquer layout sem as teclas mortas).

## Diagnóstico

```bash
export DISPLAY=:0 XAUTHORITY=~/.Xauthority

xkbcomp :0 -       | grep -m1 'name\[group1\]'   # CORE
xkbcomp -i 5 :0 -  | grep -m1 'name\[group1\]'   # Virtual core XTEST keyboard
xkbcomp -i 12 :0 - | grep -m1 'name\[group1\]'   # teclado físico (id via xinput list)
```

Se o CORE e o XTEST mostrarem `English (US)` enquanto o teclado físico mostra o
layout correto (ex.: `Portuguese (Brazil)`), é este problema.

## Correção

Aplicar ao CORE o layout declarado — `setxkbmap` sem argumentos usa a
propriedade XKB do servidor, que vem de `/etc/default/keyboard`; o device XTEST
acompanha:

```bash
setxkbmap                                        # ou: setxkbmap -model abnt2 -layout br
systemctl --user restart openflowkey.service     # o cliente reconstrói o mapa
```

## Correção permanente

O script `deploy/linux/ofk-keymap.sh` faz isso de forma idempotente: só age se o
CORE não tiver teclas mortas, aplica o layout de `/etc/default/keyboard` e
reinicia o cliente quando corrige (o cliente guarda o mapa em cache).

```bash
install -Dm755 deploy/linux/ofk-keymap.sh ~/.local/bin/ofk-keymap.sh
OFK_CLIENT_UNIT=openflowkey.service ~/.local/bin/ofk-keymap.sh
```

Autostart no login — `~/.config/autostart/ofk-keymap.desktop`:

```ini
[Desktop Entry]
Type=Application
Name=OpenFlowKey: layout do teclado (core/XTEST)
Comment=Garante teclas mortas (acentos, c, ~) no mapa X usado pelo cliente
Exec=sh -c 'sleep 5; exec %h/.local/bin/ofk-keymap.sh'
Terminal=false
X-GNOME-Autostart-enabled=true
```

Timer do systemd (auto-cura) — `~/.config/systemd/user/ofk-keymap.service`:

```ini
[Unit]
Description=OpenFlowKey: garantir layout do teclado no CORE/XTEST
After=graphical-session.target

[Service]
Type=oneshot
Environment=DISPLAY=:0
Environment=XAUTHORITY=%h/.Xauthority
ExecStart=%h/.local/bin/ofk-keymap.sh
```

`~/.config/systemd/user/ofk-keymap.timer`:

```ini
[Unit]
Description=Verifica o layout do teclado do OpenFlowKey

[Timer]
OnStartupSec=45
OnUnitActiveSec=60

[Install]
WantedBy=timers.target
```

```bash
systemctl --user daemon-reload
systemctl --user enable --now ofk-keymap.timer
systemctl --user list-timers ofk-keymap.timer
```

## Teste fim-a-fim

Dá para conferir o que o cliente injeta sem depender do teclado físico do
servidor: captura-se os eventos no cliente com `xev` e injeta-se as teclas no
servidor com o ponteiro sobre a tela do cliente.

```bash
# no cliente
export DISPLAY=:0 XAUTHORITY=~/.Xauthority
nohup xev -geometry 420x300+60+60 >/tmp/xev.out 2>&1 &
xdotool search --name "Event Tester" windowactivate --sync

# no servidor (ponteiro já sobre a tela do cliente)
for k in slash shift+slash dead_acute a dead_tilde a ccedilla; do
    xdotool key --clearmodifiers "$k"
done

# no cliente: esperado slash, question, dead_acute seguido de aacute,
# dead_tilde seguido de atilde e ccedilla
grep keysym /tmp/xev.out | tail -20
```

## Notas

- Outros sistemas podem não sofrer disto: no macOS, por exemplo, o layout do
  cliente costuma ser estável, e a mesma combinação de servidor funciona.
- Layouts diferentes entre servidor e cliente não são problema *por si*: o que
  importa é o mapa do **CORE/XTEST do cliente** conter os keysyms que o servidor
  envia. Avisos de "layout do servidor não instalado" são apenas informativos.
- Ao mudar o mapa do CORE com `setxkbmap` (ou qualquer ferramenta XKB), o
  cliente precisa reconstruir o mapa — daí o reinício do serviço na correção.
