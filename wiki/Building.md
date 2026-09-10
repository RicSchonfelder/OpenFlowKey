> Nota: idioma oficial do OpenFlowKey é português do Brasil.

> [!WARNING]
> **WIP:** Estas instruções estão em andamento. [[Building (legacy)]]

OpenFlowKey é um software livre e de código aberto, e qualquer pessoa é bem-vinda para compilá-lo,
executá-lo, modificá-lo, fazer fork, redistribuir como parte de seu próprio app, etc.

- [Primeiros Passos](#getting-started)
- [Dependências](#dependencies)
- [Configuração](#configure)
- [Compilação](#build)

# Primeiros Passos

Antes de começarmos a compilar, precisamos configurar o ambiente de desenvolvimento.



## Windows

 Começar no Windows requer que você primeiro tenha as seguintes ferramentas instaladas e no seu `PATH`
   1. [Visual Studio Community](https://visualstudio.microsoft.com/vs/community/) ou [Visual Studio 2022](https://visualstudio.microsoft.com/vs/)
      - Instale pelo menos os seguintes componentes do VS:
         - MSVC v143 - VS 2022 C++ x64 / x86 build tools
         - Um Windows SDK, por exemplo estou usando `Windows 10 SDK (10.0.18362.0)`
   1. [cmake](https://cmake.org/download/) - CMake v3.24 ou superior é necessário
   1. [ninja](https://github.com/ninja-build/ninja/releases)
   1. [git](https://github.com/git-for-windows/git/releases)
   1. [vcpkg](https://learn.microsoft.com/en-us/vcpkg/get_started/get-started) - Recomendado para gerenciamento de dependências:
      - Clone o `vcpkg` em `C:\vcpkg` (nomes podem ficar longos e o Windows tem limite de caminho)
      - Depois de ter o `vcpkg.exe` em `C:\vcpkg`, execute `vcpkg integrate install`
      - Anote o "toolchain" que ele informa para usar com o CMake; precisaremos dele para configurar.
      - Certifique-se de adicionar `%VCPKG_ROOT%` à sua variável de ambiente `PATH`.

   1. [WiX](https://github.com/wixtoolset/wix/releases)

 Dica: A configuração inicial usando vcpkg pode demorar um pouco, pois ele fará checkout e compilará todas as dependências — esta é a forma mais fácil de configurar o projeto no Windows. Se você não quiser compilar uma dependência (ou nenhuma delas), você deve
  1. Editar o arquivo `vcpkg.config` para remover os itens que você instalará manualmente. Isso deve acontecer antes de tentar configurar o projeto. OU ao configurar o projeto sem CMAKE_TOOLCHAIN_FILE definido para o toolchain do vcpkg.
  1. Instalar o item manualmente e garantir que o cmake consiga encontrá-lo, geralmente isso envolve adicionar o caminho onde o arquivo *.cmake do projeto está localizado ao seu PATH
  1. No caso do Qt, também adicione o caminho das ferramentas do Qt ao seu PATH

## macOS
 Para começar no macOS você precisará ter as seguintes ferramentas
  1. [XCode](https://apps.apple.com/us/app/xcode/id497799835) - App Store
    - Você deve abri-lo após instalar e instalar o SDK para a versão do macOS que você possui.
  1. [Homebrew](https://www.brew.sh)
  1. Git
  1. CMake 3.24
  1. Qt 6

Dica: Depois de instalar o `brew`, execute este comando
```
brew install git cmake
```

## Linux

Você deve ter pelo menos os itens básicos para compilar código C++:
   - gcc ou clang
   - cmake 3.24+
   - git
   - ferramenta de build ninja (recomendado)

Use seu gerenciador de pacotes para instalá-los.

# Dependências

OpenFlowKey requer o seguinte para compilar:
 - CMake 3.24+
 - Qt 6.7+
 - OpenSSL 3.0
 - Google Test**
 - libportal 0.9.1+ (apenas Linux)
 - libei 1.3+ (apenas Linux)

** Essas dependências serão baixadas automaticamente em tempo de compilação se não forem encontradas no seu sistema; Google Test só é necessário para compilar os testes.

## Windows

Se você instalou o `vcpkg` ao usar Qt Creator ou Visual Studio Code ele deve detectar automaticamente suas informações do vcpkg. Se não detectar, você precisará [definir seu `CMAKE_TOOLCHAIN_FILE`](https://learn.microsoft.com/en-us/vcpkg/get_started/get-started?pivots=shell-powershell#4---build-and-run-the-project). Uma vez que o `vcpkg` tenha sido configurado, ele baixará e compilará as dependências necessárias quando você executar o comando de configuração. Levará um tempo para compilar tudo na primeira vez, o que é normal.

Os seguintes itens serão instalados pelo vcpkg: `qt`, `openssl` e `gtest`.

## macOS

  1. Qt 6.7+ <br/>
    - Se você planeja apenas executar a compilação no seu sistema local, pode usar a versão do Qt do `brew` (`brew install qt`)
    - Se você quiser distribuir suas compilações, precisa obter o Qt pelo [Qt Online Installer](https://doc.qt.io/qt-6/qt-online-installation.html)
  1. openssl 3.0+
  1. googletest (opcional)

## Linux
  Se sua distro tiver pacotes `dev` ou `devel`, certifique-se de instalá-los.
  - libei 1.3
  - libportal 0.8
  - qt 6.7+
  - google test (opcional)

**Debian/Ubuntu:**
```
  apt install cmake build-essential ninja-build \
              xorg-dev libx11-dev libxtst-dev libssl-dev \
              libglib2.0-dev libxkbfile-dev qt6-base-dev qt6-tools-dev \
              libgtk-3-dev libgtest-dev libgmock-dev libei-dev libportal-dev
```

**Fedora:**
```
  dnf install cmake make ninja-build gcc-c++ rpm-build \
              openssl-devel glib2-devel libXtst-devel libxkbfile-devel \
              qt6-qtbase-devel qt6-qttools-devel gtk3-devel \
              gtest-devel gmock-devel libei-devel libportal-devel
```

**RHEL**
```
  dnf install epel-release
  dnf config-manager --set-enabled crb
  dnf install cmake make ninja-build gcc-c++ rpm-build \
              openssl-devel glib2-devel libXtst-devel libxkbfile-devel \
              qt6-qtbase-devel qt6-qttools-devel gtk3-devel \
              gtest-devel gmock-devel libei-devel libportal-devel

```

**SUSE/openSUSE:**
```
  zypper install cmake make ninja gcc-c++ rpm-build libopenssl-devel \
                 glib2-devel libXtst-devel libxkbfile-devel qt6-base-devel \
                 qt6-tools-devel qt6-linguist-devel gtk3-devel googletest-devel \
                 googlemock-devel libei-devel libportal-devel
```

**Arch Linux:**
```
  pacman -S base-devel cmake ninja gcc openssl \
            glib2 libxtst libxkbfile gtest libei libportal \
            qt6-base qt6-tools qt6-translations qt6-declarative gtk3
```

**FreeBSD:**
```
  pkg install cmake ninja gmake gcc12 openssl glib \
              libX11 libXtst libxkbfile qt6-base qt6-tools \
              gtk3 googletest pkgconf libei libportal
```


# Configuração

Opções do CMake:

|         Opção           |            Descrição                  |   Valor Padrão    | Requisitos adicionais |
:-------------------------:|:---------------------------------------:|:------------------:|:-----------------------:|
| BUILD_USER_DOCS          | Compilar Documentação do Usuário                | DOXYGEN_FOUND      | `Doxygen` |
| BUILD_DEV_DOCS           | Compilar Documentação de desenvolvedor           | OFF                | `Doxygen` |
| BUILD_INSTALLER          | Compilar instaladores/pacotes               | ON                 | |
| BUILD_TESTS              | Compilar testes unitários e testes legados       | ON                 | `gtest`|
| BUILD_X11_SUPPORT        | Compilar backend X11 (apenas linux e bsd)   | ON                 | x11 , xlibs |
| ENABLE_COVERAGE          | Habilitar cobertura de testes                    | OFF                | `gcov` |
| SKIP_BUILD_TESTS         | Pular execução de testes em tempo de compilação     | OFF                | |
| VCPKG_QT                 | Compilar Qt com vcpkg (apenas windows)        | OFF                | |
| CLEAN_TRS                | Remover strings obsoletas de arquivos tr   | OFF                | |
| APPLE_CODESIGN_DEV       | Certificado Apple codesign para desenvolvimento   | Não Definido            | |

Para configurar, use o CMake.

> [!TIP]
> Você poderia criar um arquivo [`CMakeUserPresets.json`](https://gist.github.com/nbolton/1a6c59b576528f20f76ae2e3fd0c72d5).

**Exemplo de comando de configuração:**
```
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
```

# Compilação

**Exemplo de comando de compilação:**
```
cmake --build build -j8
```

# Problemas Comuns

## Erro: `qt.qpa.plugin: Could not find the Qt platform plugin "windows" in ""`

Tentativa de correção: https://github.com/openflowkey/openflowkey/pull/8057

Crie um arquivo `qt.conf` em `bin`:
```
[Paths]
Plugins = C:\vcpkg...debug\Qt6\plugins
```

## Ícone ausente ou simbólico não recolorindo no linux

Os ícones devem ser instalados para funcionar corretamente no linux

copie `deploy/linux/org.openflowkey.openflowkey.png` -> `/usr/share/icons/hicolor/512x512/apps/org.openflowkey.openflowkey.png`

copie `src/apps/res/icons/openflowkey-light/apps/64/org.openflowkey.openflowkey-symbolic.svg` -> `/usr/share/icons/hicolor/symbolic/apps/org.openflowkey.openflowkey-symbolic.svg`

você pode precisar atualizar o cache de ícones com um comando como `gtk-update-icon-cache` após copiá-los

## Auto-assinatura para desenvolvimento local no macOS

> [!IMPORTANT]
> Requer PR #9089

1. Instale o Xcode
2. Vá em Ajustes -> Contas
3. Adicione sua conta (requer um ID Apple Developer gratuito)
4. Gerenciar certificados -> Adicionar -> Apple Development
5. Para obter seu ID, execute: `security find-identity -v -p codesigning login.keychain-db`
6. Passe o ID para o CMake, ex. `-DAPPLE_CODESIGN_DEV=Apple Development: bob@exmaple.com (KLGSJHLFXY)` `.` pode ser usado como id se você tiver apenas um configurado
7. Configure e compile
8. Para verificar, execute: `codesign -d -r- build/bin/OpenFlowKey.app`
