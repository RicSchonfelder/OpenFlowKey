> Nota: idioma oficial do OpenFlowKey é português do Brasil.

# Guia para tradutores

Este é um guia geral para traduzir o OpenFlowKey. Aqueles que desejam atualizar as traduções dentro do aplicativo devem instalar o Qt Linguist. Para tradutores que não têm o Qt (ferramentas de desenvolvimento) instalado, é possível instalar uma versão standalone do linguist.

 - No Linux você pode obtê-lo pelo gerenciador de pacotes da sua distro
 - No Mac OS você pode instalar com brew
 - Usuários Windows podem baixar um binário da versão Qt6 do linguist [aqui](https://github.com/thurask/Qt-Linguist/)

Nem todos os itens que precisam de tradução estão em arquivos ts. Alguns arquivos distribuídos podem ter traduções incluídas diretamente neles, veja a seção [Traduzindo arquivos não-código](#translating-non-code-files) para mais informações sobre esses tipos (pode não ser uma lista completa no momento)

## Adicionando uma nova tradução para o OpenFlowKey 

### Adicione a tradução à lista em `translations/CMakeLists.txt`
  - Procure por `set (${CMAKE_PROJECT_NAME}_TRS` em `translations/CMakeLists.txt`. Adicione seu novo item na lista após ele. Esta variável controla quais arquivos ts são gerados.
  - Os nomes dos arquivos de idioma devem ser `${CMAKE_PROJECT_NAME}_LANG.ts` onde LANG é o nome ISO639 do seu idioma (en, es, fr, it, ko, pt etc). Para português do Brasil e chinês você deve incluir também o código do país, ou seja (pt_BR, zh_CN e zh_TW)
  - O Lang também será usado para tentar implantar um arquivo de tradução Qt correspondente (no Windows / macOS) 
  - Se estivéssemos adicionando chinês (China) e italiano, adicionaríamos as seguintes linhas ao arquivo cmake 
    - `${CMAKE_PROJECT_NAME}_zh_CN.ts` (Chinês (China))
    - `${CMAKE_PROJECT_NAME}_it.ts` (Italiano)

```
set (${CMAKE_PROJECT_NAME}_TRS
  ${CMAKE_PROJECT_NAME}_es.ts  # Spanish
  ${CMAKE_PROJECT_NAME}_it.ts  # Italian
  ${CMAKE_PROJECT_NAME}_zh_CN.ts # Chinese (China)
)
```
### Gerar e definir o nome localizado do idioma.
 1. Execute o CMake e compile o projeto para gerar os novos arquivos TS no diretório translations
 1. Após gerar um novo arquivo de idioma, você DEVE traduzir o "LocalizedName" na seção I18N antes de usar a tradução.

### Atualizar testes de I18N

 Atualize os `I18NTests` para incluir o novo idioma em seu `m_langMap`. Este mapa é usado como verificação básica de sanidade; sua nova entrada será 
um mapa do "nome nativo" e do nome 639, ex: para italiano `{QStringLiteral("Italiano"), QStringLiteral("it")}` 
## Atualizando arquivos TS existentes

### Notas de tradução

 - As fontes de tradução são atualizadas quando o projeto é compilado.
 - Para atualizar as traduções em um arquivo TS você deve usar o Qt Linguist. Consulte o [Guia do Tradutor Qt](https://doc.qt.io/qt-6/linguist-translators.html) para informações gerais sobre o uso do Qt Linguist.  

### Traduzindo placeholders e aceleradores
#### Placeholder numérico

O placeholder `%n` é substituído por um número. Ao traduzir formas plurais, usar `%n` na string traduzida é opcional. `%n` será substituído por um número em tempo de execução.

Por exemplo, a string de entrada `you have %n message(s)` 

A forma singular seria `you have a message` com a forma plural `you have %n messages`

#### Placeholders de string

O placeholder `%number>0` (ou seja `%1`, `%2`, ...) será substituído por uma string em tempo de execução. Os comentários das strings devem informar o que cada um será substituído. Ao traduzir, a ordem desses placeholders pode ser alterada desde que todos os placeholders usados existam na string traduzida. 

Por exemplo, a string de entrada `There is a %1 in the %2`  (%1 é um Nome de animal, %2 é um Lugar)
 
Poderia ser traduzida como `You look %2 and can see the %1` 

#### Aceleradores e atalhos

Atalhos `Ctrl+X` devem ser traduzidos. O modificador `&` é usado para definir um acelerador. Por exemplo &Close terá o C acelerado (ou seja Alt+C selecionará o item). Ajuste-os ao traduzir para que façam sentido no idioma alvo.

### Testando traduções

Você pode testar arquivos de tradução novos e atualizados sem recompilar ou reiniciar o OpenFlowKey. Para testar suas novas traduções você precisa fazer `release` no Qt Linguist. Isso criará um arquivo `*.qm` que precisará ser colocado no diretório de traduções do OpenFlowKey 

`C:\Program Files\OpenFlowKey\translations` no Windows

`OpenFlowKey.app/Contents/Macos/translations/` no pacote Mac

`<installPrefix>/share/openflowkey/translations` no Linux

O `<installPrefix>` no Linux geralmente é 
 - `/usr` para a maioria dos pacotes instalados pelo sistema
 - `/var/app/org.openflowkey.OpenFlowKey/data` Flatpak, instalado no sistema
 - `~/.var/app/org.openflowkey.OpenFlowKey/data` Flatpak, instalado por usuário

Após copiar o novo arquivo, você deverá ver o idioma na próxima vez que entrar na tela de configurações. 

## Traduzindo arquivos não-código

Além dos arquivos ts, vários outros arquivos no repositório suportam traduções diretas no arquivo

### Arquivos desktop

traduções podem ser adicionadas ao arquivo desktop `deploy/linux/org.openflowkey.openflowkey.desktop`

você pode adicionar ao arquivo desktop entradas `Name[langcode]` e `Description[langcode]`

ex para espanhol adicione

Name[es]= Spanish Name of OpenFlowKey
Description[es]=Spanish Description of OpenFlowKey

Mais informações https://specifications.freedesktop.org/desktop-entry-spec/latest/localized-keys.html

### Traduzindo dados appstream

nos dados appstream também podem ser adicionadas traduções em `deploy/linux/org.openflowkey.openflowkey.metainfo.xml`

você pode adicionar 
`xml:lang="es"` para criar novas descrições, palavras-chave 

Mais informações https://freedesktop.org/software/appstream/docs/chap-Metadata.html#tag-description
