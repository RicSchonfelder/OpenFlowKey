> Nota: idioma oficial do OpenFlowKey é português do Brasil.

> [!Important]
> Se você está enfrentando um problema, sempre teste a versão [continuous](https://github.com/openflowkey/openflowkey/releases/tag/continuous). <br/>
> Muitos bugs são corrigidos entre lançamentos e o seu pode ser um deles.

> [!Note] 
> Ao fornecer informações de versão, sempre use o botão copiar na janela Sobre.<br/>
> Isso incluirá a versão, além do Tipo de SO, Versão do SO, Arquitetura do Processador e tipo de sessão
 
### Se você encontrou um problema não corrigido pela versão continuous

  Verifique as [issues](https://github.com/openflowkey/openflowkey/issues?q=is%3Aissue) existentes para ver se alguém já reportou o problema que você está enfrentando. Ao pesquisar, inclua issues fechadas, pois pode ser uma regressão, o problema já ter sido resolvido ou um mal-entendido.

Se já existir uma issue igual ou similar, não é necessário comentar, a menos que seu comentário traga novas informações para ajudar a resolver o bug. Um exemplo de comentário útil seria informar que sua plataforma é diferente da do autor, caso a issue seja relatada como específica de uma plataforma. Gostaríamos de manter os comentários objetivos e sem poluição, pois algumas issues podem levar tempo e muita discussão para serem resolvidas. Na maioria dos casos, você deve apenas dar :+1: na descrição da issue.

### Criando novas issues

  Em caso de dúvida, comece [fazendo uma pergunta](https://github.com/openflowkey/openflowkey/discussions/new?category=q-a)

  1. Ative o nível de log em debug para capturar o log na próxima vez que o problema ocorrer.
  1. Crie uma [Nova Issue](https://github.com/openflowkey/openflowkey/issues/new/choose)
  1. Ao reportar problemas, certifique-se de incluir a versão inicialmente testada, bem como a versão continuous usada no teste. Use o botão copiar da janela Sobre para obter essas informações.
  1. Inclua logs ao reportar 
  1. Use as tags `<details> <summary><h3>TÍTULO</h3></summary BLOCO LONGO DE TEXTO</details>` para envolver logs e outros blocos extensos, de modo que fiquem recolhíveis
  1. Preencha o formulário de bug completamente; quando relevante, inclua informações sobre servidor e clientes


### Regras para mantenedores ao abrir ou triar uma nova issue.

Veja também: [Hacking Guide](https://github.com/openflowkey/openflowkey/wiki/Hacking-Guide)

1. Se a issue for específica de um SO, use a tag do SO ([`windows`](https://github.com/openflowkey/openflowkey/labels/windows), [`macos`](https://github.com/openflowkey/openflowkey/labels/macos), `linux`)
1. Mova a issue para fora de [[triage|Triaging issues]]
1. Remova o rótulo [`stale`](https://github.com/openflowkey/openflowkey/labels/stale) se a issue tiver nova atividade (e reabra a issue se estiver fechada)
