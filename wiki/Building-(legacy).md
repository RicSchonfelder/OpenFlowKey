> Nota: idioma oficial do OpenFlowKey é português do Brasil.

Este guia foi substituído por: [[Building]]

# Guia de Compilação Legado

- [Início Rápido](#quick-start)
- [Ferramentas](#tools)
- [Dependências](#dependencies)
- [Configuração](#configure)
- [Empacotamento](#packaging)
- [Desenvolvimento](#development)

## Início Rápido

**1. Dependências:**

*Linux, macOS ou derivado de BSD:*
```
./scripts/install_deps.sh
```

*Windows:*
```
python scripts/install_deps.py
```

**2. Configuração:**

*Linux, macOS ou derivado de BSD:*
```
cmake -B build
```

*Windows:*
```
cmake -B build --preset=windows-release
```

**3. Compilação:**
```
cmake --build build -j8
```

**4. Teste:**
```
./build/bin/unittests
./build/bin/integtests
```

**5. Execução**
```
./build/bin/openflowkey
```

## Ferramentas

Sugerimos usar [VS Code](https://code.visualstudio.com/) com nossas extensões recomendadas de workspace (`.vscode/extensions.json`), especialmente a extensão [CMake Tools](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cmake-tools) (`ms-vscode.cmake-tools`).

Para modificar a aparência da interface, recomendamos usar o Qt Creator. Ele pode ser instalado de duas formas:

1. [Pacote Qt Creator](https://github.com/qt-creator/qt-creator/releases) do projeto no GitHub (recomendado)
2. [Qt Online Installer](https://www.qt.io/download-open-source) (não recomendado pois é bastante extenso)

Não recomendamos usar seu gerenciador de pacotes favorito, porque muitas vezes é mais difícil instalar a mesma versão em todos os computadores (o que é importante).

Se você optar por usar o Qt Online Installer, então precisará instalar apenas o Qt Creator (e não o Qt em si, pois essa dependência é gerenciada pelo script de dependências).

## Dependências

Problemas ao executar o script de dependências (`python scripts/install_deps.py`)

### No Windows: Maioria dos problemas

Desenvolvimento no Windows é difícil por causa de variáveis de ambiente e cache.

Se você tiver um problema, tente estes passos primeiro:

1. Delete o diretório `build`
2. Reinicie sua IDE ou Terminal
3. Reinstale o Visual Studio Community Edition

### No Linux: `ERROR: File "setup.py" not found.`

Isso acontece em distros Linux mais antigas como o Ubuntu 20, pois vêm com uma versão mais antiga do Python. Tente atualizar o `pip` para resolver.

```
pip install --upgrade pip
```

### Não existe o comando `python3`

Você precisará instalar o Python se não o tiver instalado.

Exemplos:
- Windows: `winget install Python.Python.3.12`
- macOS: `brew install python`

Se você já o tem instalado, pode ser necessário usar `python3` (em vez de `python`).

Dica: Se você precisa que o comando `python` execute o Python 3, pode usar `python-is-python3` no Linux ou criar um symlink/alias.

### No Windows: Travado em `Starting package install`

O instalador do Visual Studio demora um pouco. Se isso levar mais de 5-10 minutos, o instalador pode estar travado. Encerre o comando, remova completamente o Visual Studio, reinicie o computador e tente novamente.

### No Windows: Visual Studio está instalado mas as ferramentas VC++ não estão

Se as Build Tools do Visual Studio já estiverem instaladas, pode não ser possível para o script modificar a instalação existente. Você precisará modificar manualmente a instalação do Visual Studio e adicionar a carga de trabalho C++. Se não funcionar, remova completamente o Visual Studio e execute novamente o script de dependências.

### No Linux: Erro relacionado a `pip` ou `venv`

Em algumas distros Linux, `pip` e `venv` não vêm incluídos com o Python por padrão. O script de dependências tentará resolver isso, mas se falhar você precisará instalá-los para usar o script de dependências.

Se você ainda estiver tendo problemas para executar o script de dependências, pode obter o comando de pacotes do arquivo `config.yml` e executá-lo manualmente.

### Instalação do Qt: `ERROR: Failed to download checksum ... Check your internet connection`

Siga o guia em [verificação de certificado SSL](https://requests.readthedocs.io/en/latest/user/advanced/#ssl-cert-verification) e a variável de ambiente:
```
set REQUESTS_CA_BUNDLE=path/to/pem
```

## Configuração

Problemas ao executar `cmake` no modo de configuração.

### No Windows: Maioria dos problemas

Desenvolvimento no Windows é difícil por causa de variáveis de ambiente e cache.

Se você tiver um problema, tente estes passos primeiro:

1. Delete o diretório `build`
2. Reinicie sua IDE ou Terminal
3. Reinstale o Visual Studio Community Edition

### Erro: `cmake : The term 'cmake' is not recognized`

O script de dependências deve definir a variável de ambiente `PATH` no Windows e macOS, mas você pode precisar fazer isso manualmente se ainda estiver com problemas.

No Windows, você provavelmente precisará executar `refreshenv` ou reiniciar sua IDE para usar os novos valores da variável de ambiente.

### O mesmo erro de `cmake` persiste mesmo após tentar as soluções

O CMake armazena a configuração em cache mas não invalida o cache quando o ambiente muda. Delete o diretório `build` e execute novamente a etapa de configuração para criar uma configuração limpa.

Por exemplo, um erro comum do CMake resolvido removendo o diretório `build` é: `The C compiler [...] is not able to compile a simple test program`

### CMake não consegue encontrar o Qt: `CMake Warning at src/gui/CMakeLists.txt`

No Windows e macOS, o script de dependências deve definir as variáveis de ambiente `CMAKE_PREFIX_PATH` com o caminho do Qt, por exemplo:
- Windows: `C:\Qt\6.7.2\msvc2019_64`
- macOS: `$(brew --prefix qt@6)`

Isso normalmente não é necessário no Linux.

No Windows, você provavelmente precisará executar `refreshenv` ou reiniciar sua IDE para usar os novos valores das variáveis de ambiente.

Após mudanças nas variáveis de ambiente, pode ser necessário deletar o diretório `build` e executar novamente a etapa de configuração para criar uma configuração limpa.

### Erro no Windows: `The CXX compiler identification is unknown`

Este erro pode ocorrer por alguns motivos assumindo que as ferramentas C++ do Visual Studio estejam instaladas corretamente.

Se o comando de configuração do CMake foi executado antes do Visual Studio ser instalado corretamente, a configuração em cache do CMake pode estar incorreta. Delete o diretório `build` e execute novamente a etapa de configuração para criar uma configuração limpa.

Se você estiver usando VS Code, a forma mais fácil de corrigir é usar a extensão recomendada [CMake Tools](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cmake-tools) que configura automaticamente o ambiente das ferramentas de desenvolvedor do Visual Studio para você.

Ao executar o comando de configuração do CMake a partir de um terminal comum, muito provavelmente você não está executando no ambiente de ferramentas de desenvolvedor do Visual Studio (ou seja, `vcvarsall.bat` não foi executado). A Microsoft fornece uma entrada no menu iniciar para um terminal especial que chamam de 'Developer PowerShell for VS 2022'.

Alternativamente, se você estiver usando VS Code mas não quiser usar a extensão CMake Tools, poderia adicionar o terminal 'Developer PowerShell for VS 2022' ao `settings.json`:
```
  "terminal.integrated.profiles.windows": {
    "Developer PowerShell for VS 2022": {
      "source": "PowerShell",
      "icon": "terminal-powershell",
      "args": [
        "-NoExit",
        "-Command",
        "$vsWhere = \"${Env:ProgramFiles(x86)}\\Microsoft Visual Studio\\Installer\\vswhere.exe\"; $vsInstallationPath = & $vsWhere -products * -latest -property installationPath; & \"${vsInstallationPath}\\Common7\\Tools\\Launch-VsDevShell.ps1\" -Arch amd64 -SkipAutomaticLocation"
      ]
    }
  }
```

### Erro no Linux: `gcovr not found! Aborting`

Ao compilar com `-DENABLE_COVERAGE=ON`, o gcovr é necessário. Isso não é satisfeito pelo script de dependências, pois não é uma dependência normal. Poderíamos instalar isso com o gerenciador de pacotes do SO (ex. `apt`), mas geralmente é uma versão mais antiga que é instalada. Para instalar a versão mais recente, você poderia usar pipx:
```
sudo apt install pipx
pipx install gcovr
```

### Erro no Windows: `Could not find a configuration file for package "Qt6" that is compatible`

Isso pode ser porque a arquitetura errada está sendo usada para compilar. Em vez de usar o padrão `Developer command prompt for VS 2022`, tente usar `x86_64 Cross Tools Command Prompt for VS 2022`.

Se você estiver usando VS Code, a forma mais fácil de corrigir é usar a extensão recomendada [CMake Tools](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cmake-tools) que configura automaticamente o ambiente das ferramentas de desenvolvedor do Visual Studio para você.

## Empacotamento

### Erro no Windows: `LGHT0103: The system cannot find the file`

Se você vir este erro, provavelmente está compilando em modo debug:

`C:\path\to\openflowkey\build\installer\Product.wxs(117): error LGHT0103: The system cannot find the file 'D:/path/to/openflowkey/build/bin\Qt6Core.dll'.`

Recompile o projeto em modo release. Para isso, você pode usar o preset CMake `windows-release`.

## Desenvolvimento

### Arquivos `.ui` do Qt mudam radicalmente entre computadores

Versões diferentes do Qt Creator salvam arquivos `.ui` de forma diferente. Para garantir o máximo de consistência possível entre cada SO, use a mesma versão do Qt Creator no Windows, macOS e Linux. Isso garante que arquivos `.ui` sejam pelo menos salvos da mesma forma, o que pode ajudar a prevenir _alguns_ problemas de renderização. No entanto, isso não corrigirá problemas de renderização em tempo de execução no app compilado para Linux, já que ele será compilado com uma versão muito mais antiga do Qt.

### A interface parece diferente comparada à prévia do Qt Creator

Desenvolvimento Qt com arquivos `.ui` é complicado devido às dependências de pacotes do Linux. Temos controle limitado sobre a versão do Qt disponível em cada distro. No Windows e macOS, podemos empacotar as DLLs específicas do Qt, dando-nos mais controle sobre a versão do Qt com a qual o app é renderizado. Infelizmente, temos que contornar problemas estranhos de renderização no Linux por causa das versões do Qt disponíveis nos repositórios de pacotes.

### VS Code usa `clang-format` ou `cmake-format` errado

Você deve usar a mesma versão do `clang-format` em todos os seus computadores e deve usar a versão mais recente.

```
pipx install clang-format cmakelang
pipx inject clang-format pyyaml
pipx inject cmakelang pyyaml
```

Por alguma razão `clang-format` e `cmakelang` não tentam resolver a dependência `pyyaml`, que nem sempre está disponível (dependendo da versão do Python que você tem), então às vezes você precisará usar `pipx inject` para satisfazer essa dependência.
