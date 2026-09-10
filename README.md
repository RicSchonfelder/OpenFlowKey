# OpenFlowKey

> **Idioma oficial: Português do Brasil.** Toda documentação, wiki e issues devem ser em PT-BR. Contribuições em outros idiomas são traduzidas.

Mouse e teclado compartilhados entre Windows, macOS e Linux — fork do [OpenFlowKey](https://github.com/openflowkey/openflowkey) / Barrier com **contribuições de IA liberadas**.

`Flow + Key` = teclas fluindo entre máquinas sem barreira.

## Por que OpenFlowKey?
- ✅ **IA permitida e incentivada** — PRs gerados por IA são bem-vindos (ver `CONTRIBUTING.md`), diferente do OpenFlowKey que restringe/bane
- 🔄 Compatível com protocolo OpenFlowKey/Barrier 1.6
- 🇧🇷 Documentação e wiki 100% em português (`wiki/` e `docs/wiki/` — 44 páginas)
- 🛠️ Build simples multi-plataforma

## Documentação
- Wiki: `wiki/` e `docs/wiki/` (ex.: `wiki/Code-Style.md`)
- `CONTRIBUTING.md` — como contribuir com ou sem IA
- `docs/Configuration.md`, `docs/HelpMain.md`

## Estilo de Código
Ver `wiki/Estilo-de-Codigo.md` (original `Code-Style.md`) — clang-format obrigatório, REUSE, convenções Qt.

## Build rápido
```sh
cmake -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build -j
./build/bin/openflowkey
# compat: ./build/bin/openflowkey ainda funciona até rebrand completo do binário
```

## Origem
Base: OpenFlowKey v1.26 (2026-09-06) clonado em `_upstream/` + wiki `openflowkey/openflowkey.wiki`. Rebrand em progresso: `openflowkey` → `openflowkey`.

## Licença
GPL-2.0-only WITH LicenseRef-OpenSSL-Exception. Ver `LICENSE` e `REUSE.toml`.
