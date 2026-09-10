> Nota: idioma oficial do OpenFlowKey é português do Brasil.

## Metas de Curto Prazo:
Queremos concluir estas no futuro próximo

1. Modernização e Limpeza de Código: grande parte da nossa base de código é muito antiga e precisa ser atualizada, caminhos de código não utilizados devem ser removidos e o uso de métodos antigos deve ser atualizado. Nossa base de código requer C++20 e devemos usar o máximo desses recursos que pudermos.
1. Migrar código específico de plataforma para usar Qt sempre que possível
    - QtDus no lugar de libportal para portais
    - Classes Qt no lugar das nossas criadas dentro do projeto
    - Mesclar nosso loop de eventos com o do Qt

## Metas de Longo Prazo:
 1. Separar o código em um conjunto de bibliotecas comuns que outros possam usar para garantir compatibilidade e nosso próprio código que torna o openflowkey especial. Outros projetos, talvez compositores, usariam isso para adicionar essas funcionalidades em um nível mais baixo ou, por exemplo, um gerenciador de display poderia vincular os itens necessários para permitir conexão a um servidor antes mesmo do login. OpenFlowKey e forks idealmente também usariam e desenvolveriam isso juntos.
