> Nota: idioma oficial do OpenFlowKey é português do Brasil.

Crie um novo PR com um único commit:
1. Mensagem do commit: "Release [versão]"
   - Não use prefixo de estilo conventional commit
1. Defina a versão em `CMakeLists.txt`
2. Atualize `deploy/linux/org.openflowkey.openflowkey.metainfo.xml`
   - Acesse [Releases](https://github.com/openflowkey/openflowkey/releases) e compare a versão continuous com o último lançamento
   - Escreva manualmente uma lista resumida de bullet points com base nos commits
   - Público-alvo do arquivo metainfo são usuários Linux (resuma itens de Windows/macOS)
   - Adicione um novo lançamento à seção `releases` do arquivo metainfo
   - Formato da data: YYYY-MM-DD
3. Após o merge do PR, crie a tag do lançamento
   - Sempre use tag anotada como no exemplo abaixo
   - A tag deve corresponder ao major, minor e patch do `CMakeLists.txt`
   - Exemplo:
     - `git tag -a v1.2.3 -m "v1.2.3"`
     - `git push origin v1.2.3`
4. Acompanhe o CI para garantir que o lançamento foi compilado
   - Runners podem falhar intermitentemente (execute novamente os falhos)
   - Quando concluir, verifique a página do [último lançamento](https://github.com/openflowkey/openflowkey/releases/latest)
5. Agora aproveite e pegue uma bebida bem gelada 🍺
