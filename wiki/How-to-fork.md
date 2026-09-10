> Nota: idioma oficial do OpenFlowKey é português do Brasil.

# Com GitHub

Fazer seu próprio fork do OpenFlowKey é fácil: [Fazer fork de um repositório](https://docs.github.com/en/pull-requests/collaborating-with-pull-requests/working-with-forks/fork-a-repo)

Depois de fazer mudanças, por favor considere [[contributing]] abrindo um PR (pull request).

# Workflows

Se você quiser executar o workflow de CI no seu fork do OpenFlowKey, precisará habilitar actions para seu fork (desativado por padrão).

O empacotamento está desativado por padrão, mas você pode habilitá-lo [adicionando uma variável](https://docs.github.com/en/actions/writing-workflows/choosing-what-your-workflow-does/store-information-in-variables): CI_ENABLE_PACKAGING com o valor 	rue

O workflow de CI está configurado para executar:
- quando você atualiza um PR (on: pull_request)
- quando iniciado manualmente ([on: workflow_dispatch](https://github.blog/changelog/2020-07-06-github-actions-manual-triggers-with-workflow_dispatch/))
- nightly em um agendamento cron (on: schedule)

# Marca

Você não precisa usar o logo do OpenFlowKey ou chamar seu fork de OpenFlowKey. Você pode chamá-lo como quiser. Forks notáveis derivados do OpenFlowKey são [Barrier](https://github.com/debauchee/barrier) e [Input Leap](https://github.com/input-leap/input-leap).

Por favor lembre-se que o logo do OpenFlowKey é uma marca registrada.

# Crédito

Embora você certamente não precise, achamos que trabalhos derivados deveriam creditar os autores originais. Agradeceríamos uma menção, mesmo se você não fizer fork diretamente do OpenFlowKey (ex. se você fizer fork de um fork).
