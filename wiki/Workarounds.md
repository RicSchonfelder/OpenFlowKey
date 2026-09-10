> Nota: idioma oficial do OpenFlowKey é português do Brasil.

## Índice
- [Não foi possível conectar ao servidor](#Unable-to-connect-to-server)
- [Windows: configurações somente leitura após atualização](#Windows-readonly-settings-after-upgrade)
- [macOS: cursor com lag](#macOS-laggy-cursor)
- [macOS: permissões de Acessibilidade](#macOS-accessibility-permissions)
- [macOS: permissões de Monitoramento de Entrada](#macOS-input-monitoring-permissions)
- [macOS: Não foi possível instalar via brew](#macOS-unable-to-install-via-brew)
- [macOS: Não funciona após atualização](#macOS-Not-working-after-upgrade)
- [macOS: Bloqueio ao acordar se o servidor morreu](#macOS-Lockout-on-wakeup-if-server-died)
- [GNOME está sem ícones na bandeja](#GNOME-is-missing-tray-icons)
- [Incompatibilidade de método de entrada](#Input-method-mismatch)
- [Teclados alemães](#German-keyboards)
- [Tecla AltGr](#AltGr-key)
- [Remover permissão Xdg Remote Desktop](#Remove-Xdg-Remote-Desktop-permission)

# Não foi possível conectar ao servidor

Há algumas soluções que parecem funcionar (às vezes)

1. Verifique o firewall para garantir que a porta usada está aberta, `24800` é o padrão
1. Se esta for a execução inicial do OpenFlowKey, feche o aplicativo e execute-o novamente. 
1. Conecte-se ao servidor usando seu endereço IP e não o hostname
1. Desative o TLS, isso funciona para alguns, mas não é o ideal
1. Regenere a chave TLS
1. Altere o tamanho da chave TLS para `4096`
1. Para servidores Windows: o daemon (serviço em segundo plano) é usado por padrão. Alguns usuários relatam que usar isso quebra o modo servidor no Windows. Tente desativar o daemon (Configurar Servidor -> Avançado). (O daemon é usado para permitir que clientes interajam com o UAC e a tela de login)

# Windows: configurações somente leitura após atualização

Remova `C:\ProgramData\OpenFlowKey` ou ajuste suas permissões para que seu usuário possa ler os arquivos neste caminho. 

# macOS: Cursor com lag

## Problema
Usar Wi-Fi em um cliente macOS causa lag no cursor do OpenFlowKey.

## Solução alternativa
Execute este comando no Terminal

`sudo ifconfig awdl0 down`

Em seguida digite `ifconfig` para conferir o status na seção awdl0, deve estar como `status: inactive`.

# macOS: Permissões de Acessibilidade
(por [Trouffman](https://github.com/Trouffman))

Para macOS, você precisa permitir o processo OpenFlowKey. 

1. Execute: `xattr -c /Applications/OpenFlowKey.app`
1. Vá em: Ajustes do Sistema -> Privacidade e Segurança -> Acessibilidade
2. Abra o Finder e vá em Aplicativos, clique com o botão direito em 'OpenFlowKey' -> Mostrar Conteúdo do Pacote

![image](https://github.com/user-attachments/assets/7f0dce4d-ea18-480b-9420-540538a227be)

3. Vá em: Contents -> MacOS
4. Arraste e solte o arquivo `OpenFlowKey` na janela de configurações de Acessibilidade (aberta no Passo 1)
5. Habilite ambos "OpenFlowKey" e "OpenFlowKey" 

![image](https://github.com/user-attachments/assets/081f156a-e702-457c-922e-1fddf3648a49)
* Diferente desta imagem, a versão mais recente tem OpenFlowKey para ambos os nomes, um com ícone e outro como aplicação de terminal
* Se o OpenFlowKey já estiver na lista, remova-o e adicione novamente como descrito acima. Se não conseguir remover, remova o OpenFlowKey de /Applications e reinicie o Mac, isso deve removê-lo da lista. 

# macOS: Permissões de Monitoramento de Entrada

Para macOS, para enviar teclas aos clientes você precisa dar acesso de `monitoramento de entrada` ao processo OpenFlowKey
 
1. Vá em: Ajustes do Sistema -> Privacidade e Segurança -> Monitoramento de Entrada
1. Clique no + e encontre o OpenFlowKey.app (ou arraste e solte openflowkey.app na lista) 

Se você atualizou o OpenFlowKey, pode ser necessário remover a versão anterior e adicionar a nova manualmente.

# macOS: Não foi possível instalar via brew

Se você estiver enfrentando problemas ao tentar instalar o openflowkey (ou openflowkey-dev) via brew, execute `brew doctor`, verifique os avisos e veja se resolvê-los permite que a instalação seja concluída ([#9649](https://github.com/openflowkey/openflowkey/issues/9649))

# macOS: Não funciona após atualização

Se você instalou manualmente, pode ser necessário redefinir a quarentena do app: `xattr -c <caminho>/OpenFlowKey.app`

As configurações de Acessibilidade e Monitoramento de Entrada no macOS às vezes precisam ser removidas e adicionadas novamente ao atualizar. Se não conseguir remover a permissão, certifique-se de que o aplicativo não está instalado e reinicie a máquina. Reiniciar parece remover aplicativos não mais instalados das permissões. Depois de remover o aplicativo, ele deve solicitar permissão novamente ao ser executado e se adicionar corretamente desta vez.

Tente redefinir as permissões
```
sudo tccutil reset Accessibility org.openflowkey.openflowkey
```

então execute o openflowkey, ele deve pedir mais uma vez e depois iniciar.

# macOS: Bloqueio ao acordar se o servidor morreu

Alguns usuários do OpenFlowKey relatam um problema onde a máquina controladora pode ficar bloqueada quando o servidor (macOS) dorme enquanto o cursor está em um cliente (https://github.com/openflowkey/openflowkey/issues/8652). Para contornar, tente a solução do tópico instalando 

Isso requer instalar o [sleepwatcher](https://formulae.brew.sh/formula/sleepwatcher)

> Agora tenho o seguinte script `~/.wakeup` para lidar com essa situação. Ele finalizará o OpenFlowKey ao acordar o laptop...

>

Versões < 1.24.0
``` 
# OpenFlowKey resque
pgrep -x openflowkey-server && { pkill -9 -i -x openflowkey-server && while pgrep -x openflowkey-server > /dev/null; do sleep 0.1; done; }
#
```
Versões >= 1.24.0
``` 
# OpenFlowKey resque
pgrep -x openflowkey-core && { pkill -9 -i -x openflowkey-core && while pgrep -x openflowkey-core > /dev/null; do sleep 0.1; done; }
#
```

# Incompatibilidade de método de entrada

## Problema

Quando você intencionalmente deseja usar layouts de teclado diferentes no cliente e no servidor, pode ocorrer incompatibilidade de layout.

## Solução

Vá em Preferências e desmarque a opção: Usar idioma do teclado do servidor neste computador (modo cliente)

# GNOME está sem ícones na bandeja
## Problema 

Nenhum ícone da bandeja visível no GNOME

## Solução 
Instale a [Extensão de Suporte AppIndicator](https://extensions.gnome.org/extension/615/appindicator-support/)


# Teclados alemães
## Problema

Servidor Alemão -> Windows 10 -> layout de teclado alemão

Cliente Alemão -> Manjaro Linux -> layout de teclado alemão

## Solução alternativa

Se o cliente trocar z e y e não conseguir digitar letras alemãs corretamente (öäüß), digite "setxkbmap de" no terminal, agora funciona corretamente.

Se não funcionar em sessão i3 ou KDE com .xinitrc. Execute isso no login do X:

```
cat setxkbmap.sh
#!/bin/bash
setxkbmap de
exit
```


# Tecla AltGr

O suporte a AltGr é limitado no OpenFlowKey. Alguns usuários têm sucesso ao remapear a tecla Alt para AltGr. Você precisará usar um arquivo de configuração para isso, não é suportado na GUI. Aqui estão as instruções:

Comece exportando sua configuração atual, usando Arquivo -> Salvar Configuração Como.

Edite usando seu editor de texto favorito e encontre uma seção chamada Screens. Normalmente ela se parece com isto:

 section: screens
   server:
      option1 = value
      option2 = value
      etc
   client:
      option1 = value
      option2 = value
      etc

O que queremos fazer é adicionar a opção "alt=altgr" na seção do cliente, assim:

 section: screens
   server:
      option1 = value
      option2 = value
      etc
   client:
      option1 = value
      option2 = value
      etc
      alt=altgr

Certifique-se de salvar este arquivo em um local seguro, onde o OpenFlowKey possa encontrá-lo sem ser alterado, e aponte o OpenFlowKey para este arquivo usando a opção "Usar configuração existente".

Algumas pessoas têm melhores resultados fazendo o inverso, usando altgr=alt. Tente isso se continuar com problemas no exemplo acima.

Para versões recentes do OpenFlowKey, pelo menos sucesso parcial foi relatado usando

      altgr = shift

para os clientes na seção Screen do arquivo de configuração do OpenFlowKey (mesmo lugar acima).

## Modificar altgr no linux

Ao executar no Linux você pode definir como o sistema define o altgr. 

Você pode usar `setxkbmap -option [OPTION]` com uma das opções abaixo. Uma vez que encontrar uma configuração que goste, pode adicioná-la ao seu perfil de usuário ou executar o comando em um script ao iniciar. 

 |  Option                  | Descrição |
 |:-----------------        |:------------|
 | lv3:switch               | Right Ctrl  |
 | lv3:menu_switch          | Menu        |
 | lv3:win_switch           | Qualquer tecla Win |
 | lv3:lwin_switch          | Left Win    |
 | lv3:rwin_switch          | Right Win   |
 | lv3:alt_switch           | Qualquer tecla Alt |
 | lv3:lalt_switch          | Left Alt    |
 | lv3:ralt_switch          | Right Alt   |
 | lv3:ralt_switch_multikey | Right Alt, Shift+Right Alt é Compose |
 | lv3:enter_switch         | Enter no teclado numérico |
 | lv3:caps_switch          | Caps Lock |
 | lv3:bksl_switch          | Backslash |
 | lv3:lsgt_switch          | Less/Greater |

Exemplo de arquivo autostart 

Este exemplo vem de https://github.com/openflowkey/openflowkey/issues/4411#issuecomment-3210586777

Salvo como `~/.config/autostart/keyboard-options.desktop`
```
[Desktop Entry]
Type=Application
Name=Keyboard Options
Exec=sh -c 'sleep 5 && setxkbmap -option lv3:rwin_switch'
Hidden=false
NoDisplay=false
X-GNOME-Autostart-enabled=true
```

> Isso adiciona um arquivo keyboard-options.desktop com o conteúdo que garante que o comando seja executado na inicialização. Pode ser visualizado e ajustado em 'Preferências de Aplicativos de Inicialização' também.
O sleep pode ser ajustado lá. Recomendo mantê-lo, pois se executado muito cedo pode ser sobrescrito. 


# Remover permissão Xdg Remote Desktop
 
Para remover o token persistente, remova o valor `xdgRestoreToken` do arquivo de configurações do OpenFlowKey. (~/.config/OpenFlowKey/OpenFlowKey.conf)
