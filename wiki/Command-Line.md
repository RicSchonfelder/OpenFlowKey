> Nota: idioma oficial do OpenFlowKey é português do Brasil.

Alguns usuários preferem usar a linha de comando para executar o OpenFlowKey em vez de usar a configuração automática.

Informações gerais
-------------------

Os binários do OpenFlowKey geralmente aceitam os mesmos parâmetros nas 3
plataformas.

Veja [Text-Config](https://github.com/openflowkey/openflowkey/wiki/Server-Text-Config) para informações sobre como criar um arquivo de configuração. Se você
tem outro sistema no qual pode usar a interface gráfica, considere
configurar seu sistema nessa interface e depois exportar o arquivo de configuração
com Arquivo --> Salvar Configuração Como e copiá-lo para o sistema
onde você precisa. O mesmo arquivo de configuração funcionará em qualquer plataforma.

Abra um prompt de comando e entre no diretório de instalação do OpenFlowKey.

| SO | Comando |
| ------- | --------------------------------------------- |
| Windows | `cd "C:\Program Files\OpenFlowKey"`               |
| macOS   | `cd /Applications/OpenFlowKey.app/Contents/MacOS/` |
| Linux   | `cd /usr/bin`                                 |

Execute o núcleo do OpenFlowKey em modo cliente, apontando para o Servidor OpenFlowKey.

| SO | Comando |
| ------- | ------------------------------------- |
| Windows | `openflowkey-core client [IP do servidor]`   |
| macOS   | `./openflowkey-core client [IP do servidor]` |
| Linux   | `./openflowkey-core client [IP do servidor]` |

Execute o núcleo do OpenFlowKey em modo servidor, apontando para o arquivo de configuração.

| SO | Comando |
| ------- | -------------------------------------------------- |
| Windows | `openflowkey-core server -s [caminho para o arquivo de configuração]`   |
| macOS   | `./openflowkey-core server -s [caminho para o arquivo de configuração]` |
| Linux   | `./openflowkey-core server -s [caminho para o arquivo de configuração]` |

Opções de linha de comando
--------------------

  [Text Config]: Text_Config "wikilink"

### Opções para `openflowkey-core`

```
❯ openflowkey-core --help
openflowkey-core: 1.25.0.23 (7e278b62)
Usage: openflowkey-core coremode [options]
Keyboard and mouse sharing utility

Options:
  -h, --help                   Display Help on the command line
  -v, --version                Display version information
  --new-instance               Skip the check for a running instance, always
                               makes a new instance
  -s, --settings <configFile>  override configuration file to use

Arguments:
  coremode                     The mode to start in either: server or client
```
