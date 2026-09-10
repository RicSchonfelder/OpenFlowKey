> Nota: idioma oficial do OpenFlowKey é português do Brasil.

> [!WARNING]
> WIP: Este artigo em andamento ainda não foi finalizado.

Você DEVE usar clang-format: `20.1.0`

Inspirado no doc de estilo de código do KDE: [Clang-format automatic code formatting](https://community.kde.org/Policies/Frameworks_Coding_Style#Clang-format_automatic_code_formatting)

Para desenvolvedores novos no Clang-Format, pode haver tentação de lutar contra ele. No entanto, é muito mais produtivo aceitá-lo e lidar com suas peculiaridades, pois os benefícios de usá-lo superam em muito os custos.

**Prós:**
- Você não precisa se preocupar com estilo de código enquanto desenvolve, reduzindo carga cognitiva.
- Reduz debates sobre preferências subjetivas de estilo em revisões de código.
- Economiza tempo automatizando tarefas de formatação que de outra forma seriam feitas manualmente.
- Garante formatação consistente em toda a base de código, facilitando o trabalho em conjunto.
- Ajuda na refatoração de código mantendo a formatação limpa durante as mudanças.
- Pode ser facilmente integrado em pipelines de CI/CD para verificações automáticas.

**Contras:**
- Pode fazer coisas de formas que você não espera, como quebrar linhas em lugares que podem tornar o código menos legível.
- Desenvolvedores podem sentir perda de controle sobre certas preferências ou nuances de estilo.
- Algumas decisões de formatação, como alinhamento ou posicionamento de chaves, podem conflitar com preferências pessoais ou da equipe.

As dicas e truques a seguir podem ajudar com os contras acima.

# Usar formatação ao salvar

A maioria das IDEs hoje tem recurso de formatar ao salvar.
- VS Code: Use `xaver.clang-format` e `"editor.formatOnSave": true,`
- Kate: Veja abaixo (Configure -> External Tools -> Clang Format Full File)

![image](https://github.com/user-attachments/assets/cd9f7559-7785-4790-864b-8838342a946f)

# Quebras de linha

Use um comentário no final da linha para forçar uma quebra de linha.

Alguns desenvolvedores podem ter dificuldade para analisar mentalmente argumentos de função quando não estão posicionados deliberadamente:
```
  LOG_DEBUG1(
      "say hello version %s %d.%d", protocolName.c_str(), helloBackMajor,
      helloBackMinor);
```

Pode ser um pouco mais fácil para alguns desenvolvedores entender se forçarem uma quebra com `//` no final:
```
  LOG_DEBUG1(
      "say hello version %s %d.%d", //
      protocolName.c_str(), helloBackMajor, helloBackMinor);
```

# Sobrescrevendo ordenação de `#include`

Separe seus includes em grupos para forçar a ordenação. Isso pode ser útil quando há interdependências acidentais (ou problemáticas) entre cabeçalhos.

```
#include "client/Client.h"

#include "net/IDataSocket.h"
#include "net/ISocketFactory.h"
#include "net/SecureSocket.h"
#include "net/TCPSocket.h"

#include <format>
#include <fstream>
#include <iterator>
#include <stream>
```

# Formatando enumerações

Adicione uma vírgula à direita para dizer ao Clang-Format que você quer enums e listas de inicialização em linhas separadas.

Sem:
```
enum HelloWorld { kFoo, kBar };
```

Com vírgula à direita:
```
enum HelloWorld {
  kFoo,
  kBar,
};
```

# Último recurso, desative

```
// clang-format off
Some fragile or from third parties imported code...
// clang-format on
```

## Hook de pre-commit do Git
Você pode usar o script abaixo como um hook de pre-commit para formatar os arquivos que você alterou.

Copie o conteúdo abaixo para um arquivo `.git/hooks/pre-commit` e torne-o executável
Quando você fizer um commit, o clang-format será executado nos arquivos alterados no seu commit. Certifique-se de fazer `--amend` em quaisquer alterações no seu commit. Tenha cuidado especial durante rebase. Usar `git rebase --continue` não executará o hook de pre-commit

```
#!/bin/bash

# Get list of staged files
staged_files=$(git diff --cached --name-only --diff-filter=ACM)

# Filter for C/C++/Objective-C files
files_to_format=$(echo "$staged_files" | grep -E '\.(c|cpp|cxx|h|hpp|m|mm)$')

# Check if there are files to format
if [ -n "$files_to_format" ]; then
  # Run clang-format on the files
  clang-format -i $files_to_format

  # Add the formatted files back to the staging area
  git add $files_to_format
fi
```
