> Nota: idioma oficial do OpenFlowKey é português do Brasil.

Regras para revisar, criar ou modificar um pull request.

Veja também: [[Hacking Guide]]

### 1. Use o modo 'Draft' até seu PR estar pronto para ser integrado

PRs abertos serão integrados se aprovados. Se o PR ainda não estiver pronto para ser integrado (ex.: bloqueado por outro PR ou WIP), use o modo rascunho para sinalizar aos outros que o PR ainda não está pronto.

### 2. Use 'Blocked by' no topo para indicar bloqueios

Se outro PR precisar ser integrado primeiro, use o termo "Blocked by" no topo do PR para indicar que outro PR bloqueia o atual e precisa ser integrado primeiro. Não confie apenas nisso para bloquear a integração de um PR, pois pode facilmente passar despercebido; você também deve colocá-lo como rascunho.

### 3. Faça rebase em solicitações abertas (não faça merge da `master`)

Rebase mantém o histórico de commits limpo e linear, facilitando o rastreamento de alterações e evitando commits de merge desnecessários que poluem o histórico.

### 4. Nunca corrija commits de PR com novos commits (use `--amend`)

Usar `git commit --amend` permite atualizar o commit original com o código corrigido, mantendo o histórico mais limpo e conciso. Isso evita ter múltiplos commits como "fix typo" ou "fix previous commit".

### 5. Faça rebase, não faça squash ou merge

Squash permite commits casuais em um PR, o que não queremos.

### 6. Como lidar com conteúdo de baixa qualidade gerado por IA (AI slop)

Se a _descrição_ do PR for gerada por LLM, copie/cole:
```
Your PR description reads like a predictive text matrix that lost its context window. 
We require manually written, carbon-based PR descriptions, not generated token mush. 
Please read the following resources:
- [Our hacking guide](https://github.com/openflowkey/openflowkey/wiki/Hacking-Guide)
- [RFC 406i (RAGS)](https://406.fail)
```

Para quando o _diff de código_ do PR for gerado por LLM, copie/cole:
```
Your PR code diff reads like a predictive text matrix that lost its context window. 
We require manual, carbon-based testing and actual logical continuity, not automated guessing games. 
Please read the following resources:
- [Our hacking guide](https://github.com/openflowkey/openflowkey/wiki/Hacking-Guide)
- [RFC 406i (RAGS)](https://406.fail)
```
