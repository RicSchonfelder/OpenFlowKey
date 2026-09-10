> Nota: idioma oficial do OpenFlowKey é português do Brasil.

# Status de backports de forks

|  |    |
|--|:--:|
| 🚫 | Não pode ser aplicado |
| ☑️ | Portado ou já feito |
| ❔ | Não adicionado, talvez possa ser útil |
| ❓ | Não se sabe se foi adicionado, precisa ser verificado |
| 🔥 | Não portado mas deveria ser |
| 🚧 | Port aberto |

| STATUS | Descrição | PR do FORK | Nosso PR / Notas |
|:--------:|:-------|:------|:--|
|🔥| Corrigir loop infinito em conexões TCP rápidas | https://github.com/debauchee/barrier/pull/557/files| Requer barrier#411 primeiro|
|🔥| Tipo EventTarget no lugar de void* para eventos | https://github.com/input-leap/input-leap/pull/1587 | |
|🔥| smart pointers | https://github.com/input-leap/input-leap/pull/1574 https://github.com/input-leap/input-leap/pull/1578 https://github.com/input-leap/input-leap/pull/1588 ||
|🔥| EventData não-POD | https://github.com/input-leap/input-leap/pull/1555 ||
|🚫| Reverter tornar sucesso de conexão um "note" | https://github.com/debauchee/barrier/pull/738| |
|🚫| Comentário de Log de Status da GUI sobre CLOG_PRINT, devemos verificar se temos esse problema | https://github.com/debauchee/barrier/pull/739| |
|🚫| Propriedade explícita de memória em SocketMultiPlexer | https://github.com/debauchee/barrier/pull/411 |https://github.com/openflowkey/openflowkey/pull/8680  Precisa de mais trabalho para C++17 |
|❔| Correção PreserveFocus| https://github.com/debauchee/barrier/pull/178 | |
|❔| apenas cliente ativo pode capturar área de transferência | https://github.com/input-leap/input-leap/pull/1434 |  |
|❔| noexcept | https://github.com/debauchee/barrier/pull/718 | Isso pode ter sido feito em vários PRs |
|❓| Suporte a teclas Sun | https://github.com/debauchee/barrier/pull/790 | |
|❓| Suporte a Kan, Eisu_toggle e Muhenkan| https://github.com/debauchee/barrier/pull/832 | |
|❓| Usar página de código ANSI para multibyteString | https://github.com/debauchee/barrier/pull/979 | Pode não ser necessário já que agora usamos QStrings |
|☑️| Correção de rolagem horizontal (hscroll) | https://github.com/debauchee/barrier/pull/391 | https://github.com/openflowkey/openflowkey/pull/9438 |
|☑️| Adicionar regra de configuração de hotkey para `,` e `;` | https://github.com/debauchee/barrier/pull/916 | https://github.com/openflowkey/openflowkey/pull/9353 |
|☑️| Remover gerenciamento de timer do IEventQueueBuffer | https://github.com/input-leap/input-leap/pull/1592 | https://github.com/openflowkey/openflowkey/pull/9313 |
|☑️| Limpeza de dados de evento | https://github.com/input-leap/input-leap/pull/1554 |https://github.com/openflowkey/openflowkey/pull/9150 |
|☑️| Corrigir pico de CPU no Win 10 | https://github.com/debauchee/barrier/pull/656| https://github.com/openflowkey/openflowkey/pull/9116 |
|☑️| Simplificar caminho de código com muitas remoções de ifdef | https://github.com/input-leap/input-leap/pull/1491 | https://github.com/openflowkey/openflowkey/pull/9102 Não inclui partes xorg |
|☑️| remover defines não utilizados | https://github.com/debauchee/barrier/pull/981 | https://github.com/openflowkey/openflowkey/pull/8684 |
|☑️| Adicionada função nextScreen | https://github.com/debauchee/barrier/pull/703 | https://github.com/openflowkey/openflowkey/pull/8904 |
|☑️| Suporte a IPv6 | https://github.com/debauchee/barrier/pull/19 |  |
|☑️| Correção de rolagem (osx) | https://github.com/debauchee/barrier/pull/64 | |
|☑️| Correção de rolagem (x11) | https://github.com/debauchee/barrier/pull/68 | |
|☑️| Corrigir Data fromUtf8| https://github.com/debauchee/barrier/pull/121 | https://github.com/openflowkey/openflowkey/pull/6617
|☑️| Correção de modificadores (OSX)| https://github.com/debauchee/barrier/pull/210 | |
|☑️| GUI: Renomear "apply" => "restart" | https://github.com/debauchee/barrier/pull/292 | https://github.com/openflowkey/openflowkey/pull/8650 |
|☑️| erros de arquivo de configuração do macOS |https://github.com/debauchee/barrier/pull/336| |
|☑️| Corrigir aspas internacionais | https://github.com/debauchee/barrier/pull/359 | |
|☑️| Corrigir vazamento de SSL ao encerrar | https://github.com/debauchee/barrier/pull/408 | |
|☑️| Elevar XSocketAddressInUse para Erro | https://github.com/debauchee/barrier/pull/655 |
|☑️| Corrigir RetryTimer | https://github.com/debauchee/barrier/pull/409 | https://github.com/openflowkey/openflowkey/pull/6077 |
|☑️| Corrigir MouseDrift | https://github.com/debauchee/barrier/pull/424 | https://github.com/openflowkey/openflowkey/pull/6469 |
|☑️| usar std::string | https://github.com/debauchee/barrier/pull/709 | https://github.com/openflowkey/openflowkey/pull/8048|
|☑️| usar std::string | https://github.com/debauchee/barrier/pull/710 | https://github.com/openflowkey/openflowkey/pull/8048|
|☑️| usar std::string | https://github.com/debauchee/barrier/pull/711 | https://github.com/openflowkey/openflowkey/pull/8048|
|☑️| usar std::string | https://github.com/debauchee/barrier/pull/713 | https://github.com/openflowkey/openflowkey/pull/8048|
|☑️| usar std::string | https://github.com/debauchee/barrier/pull/714 | https://github.com/openflowkey/openflowkey/pull/8048|
|☑️| usar std::string | https://github.com/debauchee/barrier/pull/715 | https://github.com/openflowkey/openflowkey/pull/8048|
|☑️| usar std::string | https://github.com/debauchee/barrier/pull/716 | https://github.com/openflowkey/openflowkey/pull/8048|
|☑️| usar std::string | https://github.com/debauchee/barrier/pull/717 | https://github.com/openflowkey/openflowkey/pull/8048|
|☑️| usar std::string | https://github.com/debauchee/barrier/pull/718 | https://github.com/openflowkey/openflowkey/pull/8048|
|☑️| Tornar sucesso de conexão um "note" |https://github.com/debauchee/barrier/pull/725| |
|☑️| Gagueira de evento XWindow | https://github.com/debauchee/barrier/pull/679 | https://github.com/openflowkey/openflowkey/issues/6693|
|☑️| enum class para itens de config | https://github.com/debauchee/barrier/pull/708| |
|☑️| Incluir informações de versão no exe do Windows | https://github.com/debauchee/barrier/pull/978 | |
|☑️| Limpeza de tipos S,U int para tamanhos int std | https://github.com/debauchee/barrier/pull/1349 | |
|☑️| Habilitar crypto por padrão | https://github.com/debauchee/barrier/pull/1342 | |
|☑️| Suporte a SHA256 | https://github.com/debauchee/barrier/pull/1343 |https://github.com/openflowkey/openflowkey/pull/8152 |
|☑️| Corrigir CVE-2021-42072, CVE-2024-42073 | https://github.com/debauchee/barrier/pull/1351 |https://github.com/openflowkey/openflowkey/pull/7931 |
|☑️| Corrigir CVE-2021-42074 | https://github.com/debauchee/barrier/pull/1351 |https://github.com/openflowkey/openflowkey/pull/7982 |
|☑️| Corrigir CVE-2021-42075 | https://github.com/debauchee/barrier/pull/1350 |https://github.com/openflowkey/openflowkey/pull/7981 |
|☑️| Corrigir CVE-2021-42076 | https://github.com/debauchee/barrier/pull/1347 |https://github.com/openflowkey/openflowkey/pull/7984 |
|☑️| usar std::getenv | https://github.com/debauchee/barrier/pull/847/ | Não pode ser portado diretamente mas deveria fazer similar, https://github.com/openflowkey/openflowkey/pull/8678 |
|☑️| remover opção --no-xinitthreads | https://github.com/input-leap/input-leap/pull/1503  and https://github.com/input-leap/input-leap/pull/1504 | https://github.com/openflowkey/openflowkey/pull/8679 |
|☑️| TcpSocket lida com RW ao mesmo tempo | https://github.com/debauchee/barrier/pull/211 | https://github.com/openflowkey/openflowkey/pull/8675 |
|☑️| Mais std::mutex | https://github.com/debauchee/barrier/pull/410 | https://github.com/openflowkey/openflowkey/pull/8674 |
|☑️| Usar std::this_thread::sleep para substituir ARCH_SLEEP | https://github.com/input-leap/input-leap/pull/1462 && https://github.com/input-leap/input-leap/pull/1499| https://github.com/openflowkey/openflowkey/pull/8677 |
|☑️| Usar itens std::chrono para substituir ARCH_TIME | https://github.com/input-leap/input-leap/pull/1464 | https://github.com/openflowkey/openflowkey/pull/8637 |
|☑️| std::function | https://github.com/input-leap/input-leap/pull/1552 |https://github.com/openflowkey/openflowkey/pull/8697 |
