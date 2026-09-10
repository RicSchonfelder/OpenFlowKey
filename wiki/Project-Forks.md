> Nota: idioma oficial do OpenFlowKey é português do Brasil.

> [!TIP]
> Veja também: [[Relationship with Synergy]]

Existem vários forks, derivados e projetos downstream baseados no projeto original Synergy.

- [Histórico (resumo)](#history-summary)
- [Lista de Forks](#fork-list)
- [Comparação (alto nível)](#comparison-high-level)
- [Diferenças Técnicas](#technical-differences)

# Histórico (resumo)

- 2001: Synergy foi [[criado|History]] por Chris Schoeneman
- 2018: Synergy foi forkado para Barrier
- 2021: Barrier foi forkado para Input Leap
- 2024: OpenFlowKey tornou-se upstream de Synergy, Input Leap e Barrier

Veja também: [[Histórico completo|History]]

## Lista de Forks

Preciso em out/2024.

| Projeto | Base | Início | Tipo | Status |
| --- | --- | --- | --- | --- |
| OpenFlowKey | Synergy v1.15 | 2024 | Upstream | Ativo |
| Synergy (>v1.15) | OpenFlowKey | 2024 | Downstream | Ativo |
| Synergy (v3.x) | Synergy v1.x | 2023 | Downstream | Ativo |
| Input Leap | Barrier v2.4 | 2021 | Fork | Semi-ativo |
| Barrier | Synergy v1.9 | 2018 | Fork | Substituído* |
| Synergy (<=v1.15) | - | 2001 | Original | Substituído |

\* Em out/2024, o último commit no Barrier foi `653e4ba` (há 2 anos). A visão geral é que é um projeto inativo substituído pelo Input Leap. Postmortem do Barrier: [Por que o Barrier falhou?](https://symless.com/synergy/news/why-did-barrier-fail)

## Comparação (alto nível)

Comparando apenas projetos ativos.

Preciso em out/2024.

| | OpenFlowKey | Input Leap | Synergy (v1.x) | Synergy (v3.x) |
| --- | --- | --- | --- | --- |
| Licença | GPLv2 | GPLv2 | GPLv2 | Proprietária |
| Estabilidade | Leading edge | Legado? | Estável | Estável |
| Sistemas legados | Não | Sim | Sim | Não |
| Guiado pela comunidade | Sim | Sim | Não | Não |
| Financiamento | Patrocinado | Nenhum | Clientes | Clientes |
| Código de cliente | Não | Não | Sim* | Sim* |
| Tecnologia da GUI | Qt | Qt | Qt | Electron |
| Autodescoberta | Não | Sim** | Não | Sim** |
| Protocolo Synergy | Sim | Não | Sim | Sim |
| Protocolo Barrier | Sim | Sim | Não | Não |

\* Código de cliente no Synergy 1 inclui código para permitir que clientes insiram uma chave de licença. O Synergy 3 adiciona uma pequena camada de código proprietário em um binário separado não vinculado para clientes que querem uma experiência de configuração mais fácil e outros recursos que não são de interesse da comunidade OpenFlowKey, mas são de interesse dos clientes Synergy.

\** Input Leap (e Barrier) usam a autodescoberta legada do Synergy (Bonjour) que foi removida do Synergy devido a problemas de estabilidade. O OpenFlowKey não pretende desenvolver um recurso de autodescoberta. O Synergy 3 usa mDNS para autodescoberta.

## Diferenças Técnicas

Existem algumas diferenças técnicas entre OpenFlowKey e Input Leap. Não acreditamos que isso torne um melhor que o outro; são simplesmente abordagens técnicas diferentes que são importantes de estudar e entender. As diferenças são frequentemente impulsionadas pela preferência da comunidade e pela filosofia do projeto. As comunidades de cada projeto são compostas tanto por programadores quanto por contribuidores não programadores.

Preciso em jul/2025.

| | OpenFlowKey | Input Leap |
| --- | --- | --- |
| Revisões de código | Obrigatórias | Às vezes |
| Dependências | [`FetchContent`](https://cmake.org/cmake/help/latest/module/FetchContent.html) e [`vcpkg`](https://vcpkg.io) | [Submódulos Git](https://git-scm.com/book/en/v2/Git-Tools-Submodules) |
| Suporte Qt (mínimo) | Qt 6 | Qt 5 |
| Depende de [`libei`](https://gitlab.freedesktop.org/libinput/libei) | Obrigatório | Opcional |
| Depende de [`libportal`](https://github.com/flatpak/libportal) | Obrigatório | Opcional |
| Suporte ARM64 | Linux, macOS, Windows | apenas macOS |

Veja também:
- [[History]]
- [[Relationship with Synergy]]
