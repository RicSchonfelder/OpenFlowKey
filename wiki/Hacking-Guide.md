> Nota: idioma oficial do OpenFlowKey é português do Brasil.

> [!IMPORTANT]
> PRs de baixa qualidade serão fechados imediatamente. <br/>
> Não participamos do gittensor, PRs serão refeitos ou fechados. <br/>
> Ser desonesto sobre o uso de IA nas contribuições resultará em banimento do projeto. <br/>
> Todos os PRs DEVEM usar [Nosso Modelo de Pull Request](https://github.com/openflowkey/openflowkey/blob/master/.github/pull_request_template.md); qualquer PR que não usar o modelo será fechado.

## Commits e PRs

Por favor [crie um novo PR](https://docs.github.com/en/pull-requests/collaborating-with-pull-requests/proposing-changes-to-your-work-with-pull-requests/creating-a-pull-request) (pull request) se quiser fazer uma alteração.

### 0. Você é responsável pelo código que commita.
 
Não faça commit de código que você não entende e/ou não consegue explicar aos outros por que foi escrito daquela forma. Espera-se que você entenda o código que está propondo e a lógica por trás dele.

### 1. Mantenha descrições de PR curtas e não escreva com IA

Por favor não use LLM/IA para escrever descrições de PR para você. LLMs geram muros de texto verboso e ilegível que não trazem insight destilado. Descrições de PR geradas por IA serão ignoradas. Se o problema que você está resolvendo for complexo, você pode adicionar comentários e detalhes como apêndice, mas não comece por ele. Todos os pull requests devem usar o modelo de pull request.

### 2. Prefixe sua mensagem de commit com um tipo de commit

Use estes prefixos em mensagens de commit, eles serão usados para gerar changelogs no lançamento.

- `fix: `  ou `fix(foo): `**_deve_** ser usado se o commit **_corrige_** um problema conhecido ou se **_corrige_** um bug.
- `feat: ` ou `feat(foo): ` **_deve_** ser usado para o commit que introduz uma nova funcionalidade.
- `refactor: ` ou `refactor(foo): ` **_deve_** ser usado quando código existente é retrabalhado sem mudar funcionalidade.
- `build: `: ou `build(foo): `**_deve_** ser usado para mudanças em arquivos de projeto (CMake) ou de build.
- `doc: ` **_deve_** ser usado se o commit altera apenas documentação, ou seja, readme ou outro markdown, ou documento gerado por doxygen
- `package: ` **_deve_** ser usado para commits que alteram arquivos de pacote (ou seja, apenas wix ou cpack)
- `ci: ` ou `ci(foo): `**_deve_** ser usado para commits que modificam CI.
- `i18n: (LANG)` **_deve_** ser usado para correções isoladas de tradução. Substitua LANG pelo nome iso639 do idioma (exemplo: en, zh_CN, ru, it). Altere apenas um idioma por commit. **_não use_** se a string de origem estiver mudando; use apenas se uma tradução estiver sendo atualizada sem mudança nas strings de origem.
- `chore: ` ou `chore(foo): `**_deve_** ser usado quando código não utilizado for removido ou um arquivo for renomeado.
- Além de um dos tipos acima, você TAMBÉM deve adicionar um rodapé com `BREAKING CHANGES:...` se seu commit quebra algo.
- Não adicione tags de co-autoria para modelos LLM.

#### Exemplo de uma boa mensagem de commit
```
fix: Crash on startup 

   fixes: #4444
   fixes: #4323
   Additional commit info can be helpful 
```

### 3. PRs não são squashados, então faça cada commit de forma sensata

- Em tempo de revisão, use `git commit --amend` para corrigir um commit anterior em vez de criar um commit de acompanhamento.
  Veja: [[PR Review]]
- Cada commit deve compilar; sem commits quebrados.
- Cada commit deve ter o [Code Style](Code-Style) correto.
- Cada commit faz uma coisa, como corrigir um bug, renomear um método, adicionar uma pequena funcionalidade.
- Uma funcionalidade pode ser feita de vários commits se necessário. Cada commit ainda deve compilar por conta própria e deve avançar em direção à funcionalidade.


### 4. PRs abertos devem ser testados e devem compilar

Antes de pedir a um mantenedor para revisar seu PR, você deve mantê-lo em modo rascunho. Antes de mudar para aberto, você deve:
- Ao criar o PR SEMPRE use nosso modelo de PR
- Para novas funcionalidades, a funcionalidade deve ser testada e estar funcionando
- Para correções de bugs, você deve estar confiante de que a correção funciona
- O código deve compilar no Linux, macOS e Windows

Uma vez que todas as condições acima sejam atendidas, então defina seu PR como aberto e solicite revisão de um mantenedor. Se você não tiver acesso a um SO (ex.: macOS), por favor nos informe se pode não compilar com sucesso naquele SO antes de aprovarmos e executarmos os workflows.

### 5. Atualize as informações de licença dos arquivos

Para permanecer em conformidade com REUSE é importante que contribuidores adicionem informações de licença adequadas ao criar novos arquivos ou editar existentes.

 - Todos os arquivos **_devem_** incluir informações de direitos autorais. (No arquivo ou no REUSE.toml)
 - Direitos autorais **_devem_** estar em ordem do mais novo para o mais antigo
 - Você **_deve_** realizar uma das ações abaixo quando tiver feito alterações não triviais no arquivo. Substitua ano e info
    - Adicione `(C) ANO Seu Nome <seuemail>` à lista de detentores de direitos autorais.
    - Use `(C) ANO OpenFlowKey Developers` se não quiser adicionar seu nome.
    - Atualize o ano dos direitos autorais se já estiver na lista. Anos precisam ser
       - `20XX` Alterações pelo Autor apenas naquele ano
       - `200X - 20XX` Alterações todos os anos neste intervalo
       - `20XX, 20XY` Alterações nestes anos não consecutivos

A forma mais básica para arquivos de código é
```
/*
 * OpenFlowKey -- mouse and keyboard sharing utility
 * SPDX-FileCopyrightText: (C) YEAR OpenFlowKey Developers
 * SPDX-License-Identifier: GPL-2.0-only WITH LicenseRef-OpenSSL-Exception
 */
```

Arquivos que não lidam bem com comentários (ui, arquivos parseados, ícones, etc) **_devem_** ser adicionados ao arquivo REUSE.toml na raiz do projeto.

Nossas licenças "Gerais" para nossos arquivos são:
 - CMake e scripts relacionados a build/empacotamento `MIT`. Pois esses arquivos precisam ser acessíveis sem restrição.
 - Arquivos fonte `GPL-2.0-only WITH LicenseRef-OpenSSL-Exception`
 - Nossos ícones são `GPL-2.0-only` (não precisam linkar openssl)

Veja https://github.com/openflowkey/openflowkey/wiki/Code-Style#copyright para mais detalhes sobre a formatação

As seguintes alterações são consideradas triviais
 - Mover arquivos de um caminho para outro
 - Remover variáveis não utilizadas
 - Alterar espaçamento ou indentação
 - Mover uma função para um novo arquivo com pouca ou nenhuma alteração

### 6. Atualize a documentação

Como a documentação pode ficar desatualizada rapidamente, devemos fazer o melhor para mantê-la atualizada.

 - Você **_deve_** atualizar a documentação dentro do mesmo Pull Request onde você invalida o conteúdo do documento.
 - Isso **_deve_** incluir Criar ou atualizar [comentários Doxygen](https://www.doxygen.nl/manual/docblocks.html) para métodos.
 - Isso **_deveria_** incluir também atualizar quaisquer páginas relevantes da wiki.

### 7. Sem caixa alta irritada em comentários/logs

Caixa alta irritada corrói SNR (relação sinal-ruído). Não grite em seus comentários ou mensagens de log. Esta regra se aplica a:
- Código do programa
- Configuração de build
- Documentação

O que é importante para um desenvolvedor geralmente não é tão importante para outro. Priorizar sua mensagem sobre a de todos os outros não é colaborativo. Se você quer encontrar algo, use uma ferramenta de busca textual. Seja respeitoso com outros desenvolvedores e não cause distrações desnecessárias.

Exemplo:
```
# This is a polite and respectful comment.
# THIS IS A SHOUTY AND DISTRACTING COMMENT

message(STATUS "This is a polite and respectful log line.")
message(STATUS "THIS IS AN SHOUTY AND DISTRACTING LOG LINE")
```

### 8. Não adicione comentários redundantes

Código deve ser autodocumentado. Nos casos em que não conseguimos tornar o código autodocumentado e o código é difícil de entender, um comentário pode ser adicionado, mas ele _deve explicar o porquê_ de estarmos fazendo algo e _nunca o quê_ o código está fazendo.

Comentários "apodrecem" com o tempo; eles se afastam da intenção original do código e se tornam enganosos.

Temos visto recentemente um aumento em comentários no código por causa de IA. Isso ocorre porque dados de treinamento de IA são baseados em projetos "hello world" (ex.: escritos para ou por estudantes) que precisam 'explicar seu funcionamento'. Isso não tem lugar em código profissional e poluir código com comentários na verdade torna o código mais difícil de entender.

### 9. Garanta que seu PR esteja pronto para revisão

Não revisamos PRs em "Rascunho". Quando seu PR estiver pronto para revisão deve ser marcado como pronto para revisão. Uma vez que a revisão aconteceu e se houver comentários de revisão, um mantenedor colocará seu PR novamente como rascunho. Depois de resolver os comentários da revisão (acrescentando aos seus commits existentes) você pode marcar o PR como pronto para revisão novamente e nós o reavaliaremos.
