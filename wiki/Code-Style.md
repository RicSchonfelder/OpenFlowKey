> Nota: idioma oficial do OpenFlowKey é português do Brasil.

# Formatação
Nossa formatação de código é aplicada via CI.

> [!TIP]
> Veja nosso guia: [[Clang‐Format Tips & Tricks]]

# Direitos Autorais

OpenFlowKey é compatível com REUSE e exige que o lint do REUSE passe para compilar.
Novos arquivos devem incluir informações de licença, seja em um comentário no topo do arquivo ou no arquivo REUSE.toml

Exemplos:
```
/*
 * OpenFlowKey -- mouse and keyboard sharing utility
 * SPDX-FileCopyrightText: (C) xxxx OpenFlowKey Developers
 * SPDX-License-Identifier: GPL-2.0-only WITH LicenseRef-OpenSSL-Exception
 */
```

```
/*
 * OpenFlowKey -- mouse and keyboard sharing utility
 * SPDX-FileCopyrightText: (C) xxxx - xxxx MY name <myemail>
 * SPDX-License-Identifier: GPL-2.0-only WITH LicenseRef-OpenSSL-Exception
 */
```

```
/*
 * OpenFlowKey -- mouse and keyboard sharing utility
 * SPDX-FileCopyrightText: (C) xxxx - xxxx OpenFlowKey Developers
 * SPDX-License-Identifier: GPL-2.0-only WITH LicenseRef-OpenSSL-Exception
 */
```
mais informações: https://spdx.dev/learn/handling-license-info/

# Nomenclatura
1. Nomes de funções devem ser em `camelCase` (tanto para funções membro de classe quanto para funções livres)
1. Namespaces devem ser todos em letras minúsculas e começar com `openflowkey`, ex. `openflowkey::gui`
1. Variáveis membro devem ter prefixo `m_helloWorld`
1. Variáveis estáticas devem ter prefixo `s_`, ex. `s_helloWorld`
1. Ponteiros devem começar com `p` minúsculo, ex. `m_pHelloWorld`
1. Getters _não devem_ ter prefixo `get`, ex. `helloWorld()`
1. Setters devem ter prefixo `set`, ex. `setHelloWorld(...)`
1. Valores de enum e constantes devem ser em PascalCase, ex. `HelloWorld` (antes enums começavam com `k`)
1. Nomes de arquivos de classe devem ser em PascalCase, ex. `HelloWorld.cpp`
1. Arquivos com muitas classes ou funções devem ser em snake_case, ex. `hello_world.cpp`
1. Nomes de testes unitários devem seguir o padrão função-entrada-saída, ex. `helloWorld_fooIn_barOut`
1. A palavra "deps" deve ser usada para significar "dependencies"

## Palavras-chave Qt
1. Você deve usar `Q_SIGNALS` no lugar de `signals`
1. Você deve usar `Q_SLOTS` no lugar de `slots`
1. Você deve usar `Q_EMIT` no lugar de `emit`

## Nomenclatura Qt
1. Controles Qt NÃO devem usar `p` para indicar que são ponteiro.
1. Controles Qt DEVEM ser nomeados `<tipo><Descricao>` (`lblShortName`)
                                                     OU `<tipo>_<descricaoLonga>`  (`lbl_longerNamesMayUseThisStyle`)
1. Sinais Qt devem indicar que algo aconteceu, ex. `nameChanged`

### Regras Específicas de Formulários UI
1. Membros de formulários UI NÃO devem usar o prefixo `m_` (ou seja, lblError e NÃO m_lblError)
1. Não use as convenções de autoconexão (`on_foo_bar`) ou `onFooBar`.
1. Formulários UI devem sempre estar no namespace `Ui`
    1. Sempre use `ui{std::make_unique<Ui::Type>()}` para criar a instância de ui
    1. O Formulário UI DEVE ser um membro privado da classe que o utiliza
    1. O nome da variável DEVE ser `ui`
1. Formulários UI nunca devem ter conexões internas
1. Ao editar arquivos ui tenha cuidado extra para não alterar acidentalmente
    1. tamanhos de itens
    1. o item atual em widgets baseados em contêiner.

### Esquema de Prefixos de Tipos Qt
  - `label`  QLabels que são rótulos estáticos
  - `lbl`      QLabels que você vai alterar programaticamente
  - `rb`      QRadioButton
  - `cb`      QCheckBox
  - `combo`  QComboBox
  -  `btn`    Botões (Tool ou Push)
  -  `action`  QAction
  - Outros nomeie sem o Q

# Organização

1. Arquivos `.cpp` devem ser ordenados:
    - Direitos autorais
    - Cabeçalhos
    - `using`
    - Constantes
    - Funções livres
    - Membros de classe
1. Cabeçalhos devem ser ordenados em grupos separados de:
    - Arquivo de cabeçalho do arquivo `.cpp`
    - Para Qt, o arquivo `.ui`
    - Arquivos de cabeçalho do projeto
    - Bibliotecas de terceiros e cabeçalhos do sistema
1. Getters devem ser agrupados juntos
1. Setters devem ser agrupados juntos
1. Getters e setters não devem ser pareados

# Testes unitários

1. Use injeção de dependência via construtor (ex. `std::function` ou uma struct `Deps`)
1. O corpo de um teste unitário deve seguir o padrão AAA (arrange-act-assert), ex.:
    ```
    auto foo = "hello";
    auto bar = "world";

    auto baz = combine(foo, bar);

    EXPECT_EQ(baz, "hello world");
    ```
1. Um teste unitário deve testar apenas um cenário e uma expectativa
    - Separe cenários de teste em funções de teste distintas

# Exceções

1. Não permita que exceções se propaguem para o Qt (em vez disso, use `qFatal()`)
   - Lembre-se: `qFatal` no Windows para builds de debug, em vez disso reportará _CRT_ERROR para conectar seu debugger ao app
1. Use exceções para situações excepcionais (coisas que não deveriam acontecer)
1. Não use exceções para validação (ex. se um valor de entrada do usuário for inesperado)

# Logs

1. Use `DEBUG` para mensagens de debug que não ocorrem com frequência.
1. Use `DEBUG1` para debug de mensagens de alta frequência.
1. Use `DEBUG2` para mensagens de debug de frequência muito alta (ex. sistema de eventos).
1. Omita nomes de funções das strings de log (é impraticável mantê-los consistentes a longo prazo).
1. Use letras minúsculas para nossas linhas de log, em vez de capitalização de frase.
1. Termine mensagens de log com dados numéricos se possível.
1. Envolva strings inseridas com aspas simples.
1. Não termine mensagens de log com ponto final.
1. Uma vírgula pode ser usada para tornar a linha de log mais fácil de ler.
