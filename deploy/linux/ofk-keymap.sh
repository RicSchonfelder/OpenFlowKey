#!/bin/bash
# SPDX-FileCopyrightText: 2026 OpenFlowKey Developers
# SPDX-License-Identifier: GPL-2.0-only WITH LicenseRef-OpenSSL-Exception
#
# ofk-keymap.sh - garante que o mapa de teclado do device CORE/XTEST do X seja
# o layout declarado pelo sistema (ex.: br-abnt2) e nao o default "us" do Xorg.
#
# Por que: no X11 o Xorg aplica /etc/default/keyboard apenas aos devices fisicos
# de teclado; o device CORE ("Virtual core keyboard") e o "Virtual core XTEST
# keyboard" ficam com o layout default "us". O cliente OpenFlowKey le o mapa do
# CORE/XTEST para traduzir keysym -> keycode e injeta as teclas via XTest, isto
# e, no device XTEST. Sem teclas mortas nesse mapa, acentuacao e simbolos
# (a, a, c, ~, ^, ', ", /, ?) nao saem no cliente.
#
# Uso:
#   ./ofk-keymap.sh
#   DISPLAY=:0 XAUTHORITY=~/.Xauthority ./ofk-keymap.sh
#
# Variaveis:
#   OFK_CLIENT_UNIT  unidade systemd --user do cliente a reiniciar quando o
#                    layout for corrigido (default: openflowkey.service).
#                    Use vazio (OFK_CLIENT_UNIT=) para nao reiniciar nada.
#
# Requer: xmodmap e setxkbmap (pacote x11-xserver-utils) e um servidor X ativo.
# Rode no login (autostart) e/ou num timer do systemd para auto-cura.

set -u

export DISPLAY="${DISPLAY:-:0}"
export XAUTHORITY="${XAUTHORITY:-$HOME/.Xauthority}"
client_unit="${OFK_CLIENT_UNIT-openflowkey.service}"

if ! command -v xmodmap >/dev/null 2>&1; then
    echo "ofk-keymap: xmodmap nao encontrado (instale x11-xserver-utils)" >&2
    exit 2
fi

# 1) Criterio funcional: o mapa do CORE precisa ter teclas mortas.
if xmodmap -pke 2>/dev/null | grep -qw dead_acute; then
    exit 0
fi

# 2) Layout declarado pelo sistema (fonte unica: /etc/default/keyboard).
model=$(sed -n 's/^XKBMODEL="\(.*\)"/\1/p' /etc/default/keyboard 2>/dev/null)
layout=$(sed -n 's/^XKBLAYOUT="\(.*\)"/\1/p' /etc/default/keyboard 2>/dev/null)
variant=$(sed -n 's/^XKBVARIANT="\(.*\)"/\1/p' /etc/default/keyboard 2>/dev/null)
[ -n "$model" ] || model=pc105
[ -n "$layout" ] || layout=us

echo "ofk-keymap: CORE sem teclas mortas; aplicando ${model}/${layout} ao CORE/XTEST" >&2
setxkbmap -model "$model" -layout "$layout" -variant "$variant" || exit 1
sleep 1

# 3) Se corrigiu, reinicia o cliente: ele tem o mapa antigo em cache.
if ! xmodmap -pke 2>/dev/null | grep -qw dead_acute; then
    echo "ofk-keymap: o layout aplicado nao tem teclas mortas" >&2
    exit 1
fi

if [ -n "$client_unit" ] && systemctl --user is-enabled "$client_unit" >/dev/null 2>&1; then
    echo "ofk-keymap: reiniciando ${client_unit}" >&2
    systemctl --user restart "$client_unit" || true
fi
