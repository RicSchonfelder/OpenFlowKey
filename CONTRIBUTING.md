# Contribuindo — OpenFlowKey

> **Idioma oficial: Português do Brasil.** Escreva issues e PRs em PT-BR. IA é bem-vinda — declare o uso.

## IA permitida (diferente do OpenFlowKey)

O OpenFlowKey pune/bane uso desonesto de IA e exige template rígido. Aqui **IA é incentivada**:

- ✅ PRs total ou parcialmente gerados por IA (Copilot, Claude, opencode, ChatGPT, etc.) são aceitos
- ✅ Declare no PR: `Assistido por IA: <ferramenta> + revisão humana`
- ✅ Autor humano é responsável por testar, licenciar (GPL-2.0 + OpenSSL) e revisar
- ❌ Não envie PRs de baixa qualidade / spam automático — serão fechados
- ❌ Não cole blocos gigantes de texto de IA sem revisão

## Como começar
- Escolha uma issue (não atribuímos — comente que vai trabalhar)
- Leia `wiki/Guia-de-Hacking.md` (`Hacking-Guide.md`) e `wiki/Construindo.md`
- Build: `cmake -B build && cmake --build build && ctest --test-dir build`
- Formatação: `clang-format` deve passar (CI bloqueia se falhar)

## Regras de código
Ver `wiki/Estilo-de-Codigo.md`:
1. `clang-format` obrigatório
2. Novos arquivos: cabeçalho SPDX `GPL-2.0-only WITH LicenseRef-OpenSSL-Exception` ou entrada no `REUSE.toml`
3. Nomenclatura: `camelCase` funções, `m_` membros, `s_` estáticos, `openflowkey::` → `openflowkey::` (em migração)
4. Qt: use `Q_SIGNALS`/`Q_SLOTS`/`Q_EMIT`, não `signals`/`slots`/`emit`
5. Testes: injeção `Deps`, padrão AAA
6. Não deixe exceções escaparem para Qt — use `qFatal()`

## Pull Requests
- Use o template `.github/pull_request_template.md` (flexível — pode adaptar)
- Descreva o que foi feito, como testou, e se usou IA
- CI deve passar (lint, REUSE, testes)

## Comunidade
- Discussions no GitHub (em PT-BR)
- Matrix/IRC do OpenFlowKey ainda referenciados na wiki — em migração para canais OpenFlowKey

## Outras formas de contribuir
Documentação, tradução, testes, design, triagem de issues, divulgação.
