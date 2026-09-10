> Nota: idioma oficial do OpenFlowKey é português do Brasil.

> [!WARNING]
> **WIP:** Isto encapsula principalmente nossas ideias, mas precisa de mais trabalho.

> [!NOTE]
> **TODO:** Adicionar dicas e truques para ajudar devs a se adaptarem a esta filosofia.

Aqui está nossa filosofia geral sobre configuração do projeto (CI e ambiente de desenvolvimento).

> "Quanto mais você tenta forçar as coisas, mais você prejudica seu projeto." -- Chris (@sithlord48)

# Não tente espelhar a CI

Acreditamos que é um erro tentar espelhar a CI no ambiente local de desenvolvimento, porque quanto mais você tenta replicar a CI localmente, mais você compromete a configuração do seu ambiente; ela se torna mais complexa e propensa a bugs.

É errado impor nossas configurações de ambiente local de desenvolvimento a outras pessoas. De certa forma, isso é quase tão ruim quanto forçar todos da equipe a usar a mesma IDE. A CI existe para forçar consistência na base de código mais adiante no fluxo de trabalho do desenvolvedor. Tentar se antecipar a isso causa frustração para os devs.

# Sem scripts

Por que não mantemos scripts de build: Cada script de build é como um mini-programa com seus próprios bugs. Scripts parecem a escolha certa porque são fáceis de escrever, mas na verdade, muito pouco do tempo gasto é na escrita inicial e você passará uma eternidade mantendo-os.

Escrever um script para evitar escrever documentação sai pela culatra porque, eventualmente, você terá que escrever documentação sobre o script e todas as coisas que podem dar errado com ele.

# Sem presets

Por que não queremos manter um arquivo `CMakePresets.json`: Um arquivo de presets do CMake parece algo bom à primeira vista, mas na verdade promove preguiça. O Qt Creator, por exemplo, faz parecer que você precisa selecionar um preset (mesmo sendo opcional) e então os desenvolvedores provavelmente farão isso em vez de entender quais configurações devem definir.

# Mantenha a documentação

É melhor para o novo contribuidor descobrir por conta própria do que esconder etapas dele. Não porque seja um rito de passagem, mas porque se ele tiver que fazer as etapas, entenderá melhor como o projeto se encaixa. Se um dev não dedicar tempo para seguir as etapas de configuração do ambiente de build, que tipo de valor ele realmente agregará?
