# Configuração da GUI

 O OpenFlowKey determina automaticamente onde salvar configurações e outros arquivos.

## Caminhos de busca

O OpenFlowKey procura configurações em vários locais dependendo do sistema operacional.
A ordem de busca por um arquivo de configuração depende do sistema operacional

### Linux

  1. `<XDG_CONFIG_HOME>/OpenFlowKey/OpenFlowKey.conf`
  2. `~/.config/OpenFlowKey/OpenFlowKey.conf`
  3. `/etc/OpenFlowKey/OpenFlowKey.conf`
 
Um novo arquivo de configurações será criado no caminho do usuário se nenhum for encontrado.
O caminho do arquivo de configurações será usado como base para todos os outros arquivos de configuração.

### macOS
 
  1. `~/Library/OpenFlowKey/OpenFlowKey.conf`
  2. `/Library/OpenFlowKey/OpenFlowKey.conf`
 
Um novo arquivo de configurações será criado no caminho do usuário se nenhum for encontrado.
O caminho do arquivo de configurações será usado como base para todos os outros arquivos de configuração.

### Windows

  1. `<install-path>/settings/OpenFlowKey.conf`
  2. Windows Registry `HKCU\Software\OpenFlowKey\OpenFlowKey`

O Windows salvará no diretório de instalação se as configurações forem carregadas de lá. Caso contrário, salva outros arquivos em: `C:\ProgramData\OpenFlowKey\`

Ao usar configurações do diretório de instalação, o modo serviço não estará disponível.

## Chaves Válidas da GUI

O arquivo de configuração da GUI contém várias seções.
Cada seção é formatada da mesma forma.
Pares opção-valor só são gravados se o valor não for o padrão.

```
[section]
option=value
```

### Cliente

Esta seção contém opções usadas no modo cliente. 
Ela começa com `[client]`

| Option                    |    Valid Values    | Description |
|:--------------------------|:------------------:|:-----------|
| dynamicConnectionInterval | `true` or `false`  | Usa tempos dinâmicos de reconexão based on number of previously failed attempts [default: false] |
| languageSync              | `true` or `false`  | Sincroniza com o idioma do servidor [default: true] |
| remoteHost                | `IP` or `hostname` | O(s) host(s) remoto(s) para conectar. Use a comma separated list when you want to try several hosts |
| yScrollScale              | Double 0.1 - 10.0  | Rolagem vertical do mouse será escalada by this amount on the client [default: 1.0] |
| xScrollScale              | Double 0.1 - 10.0  | Rolagem horizontal do mouse será escalada by this amount on the client [default: 1.0] |
| invertYScroll             | `true` or `false`  | Inverte rolagem vertical on this client [default: false] |
| invertXScroll             | `true` or `false`  | Inverte rolagem horizontal on this client [default: false] |

### Núcleo (Core)

Esta seção contém opções gerais e começa com `[core]`

|Option         | Valid Values|Description|
|:--------------|:-----------:|:-----------|
| coreMode      | `0` or `1` or `2` | The mode to start in 0: None, 1: Client, 2: Server [default: 0]|
| display       |  int              | The XWindow display to use [default: autodetected] |
| interface     | IP Address        | Preferred IP to use for network communication. By default the server board casts on any available address |
| lastVersion   | M.m.p.t           | The version last run used for checking for updates |
| port          | port #            | Port to use when connecting [default: 24800 |
| preventSleep  | `true` or `false` | Prevent sleep when OpenFlowKey is active [default: false] |
| processMode   | `1` or `0`        | The mode we use to start the process Service or Desktop |
| computerName  | string            | Name used to identify the computer [default: machine's hostname] |
| useHooks      | `true` or `false` | If Windows uses hooks or not [default: true] |
| language      | 639 language      | The language to display the GUI in [default: en] |
| enableEnterCommand | `true` or `false` | Should the enter command be triggered when the screen is entered [defaut: false] |
| enterCommand  | command | A command to run when the screen is entered. |
| enableExitCommand | `true` or `false` | Should the exit command be triggered when the screen is exited [defaut: false] |
| exitCommand  | command | A command to run when the screen is exited. |

### Daemon

Esta seção contém opções usadas pelo daemon no Windows e começa com `[daemon]`

|Option | Valid Values|Description|
|:----------|:-----------:|:-----------|
| command   | Filename          | The filename of the binary the daemon. This binary exists in the same path as the openflowkey GUI |
| elevate   | `true` or `false` | Elevate the daemon app [default: true unless portable mode ] |
| logFile   | Filepath          | Filepath of the daemon log |
| logLevel  | valid log Level,  | Log Level  |

### GUI

Esta seção contém opções usadas pela GUI e começa com `[gui]`

|Option                          | Valid Values      |Description|
|:-------------------------------|:-----------------:|:-----------|
| autoHide                       | `true` or `false` | When true the app will hide itself on start up [default: false] |
| enableUpdateCheck              | `true` or `false` | When true check the update URL to see if a new version was released on start up [default: false] |
| closeReminder                  | `true` or `false` | Used to track if we have shown the reminder that when you close the app it remain running in the background  [default: true]|
| closeToTray                    | `true` or `false` | When `true` the gui will run in the systemTray when its closed [default: true] |
| logExpanded                    | `true` or `false` | Should the log section of the GUI be opened [default: false] |
| symbolicTrayIcon               | `true` or `false` | When true use the monocolor (symbolic) icon false uses a colorful icon for the tray [default: true] |
| showGenericClientFailureDialog | `true` or `false` | When `true` client connection errors will not show popup error messages [default: true] |
| shownFirstConnectedMessage     | `true` or `false` | When `true` GUI has shown the user the message for connecting the first time [default: false] |
| shownServerFirstStartMessage   | `true` or `false` | When `true` GUI has shown the user the OpenFlowKey server is now running message [default: false] |
| shownVerionInTitle             | `true` or `false` | When `true` GUI will include the version in the window title [default: false] |
| startCoreWithGui               | `true` or `false` | When true the Core will be started with the GUI. It is set to the Core's state on exit. |
| updateCheckUrl                 | URL               | The URL to use when checking for a new version number, it should return a version [default: https://api.openflowkey.org/version]|

### Log

Esta seção contém opções de log da aplicação e começa com `[log]`

|Option    |    Valid Values   |Description|
|:---------|:-----------------:|:-----------|
| file     | Filepath          | The file to write the log into |
| level    | Valid log level   | Log level to use |
| toFile   | `true` or `false` | When true the log will be written to the value of the `file` option |
| guiDebug | `true` or `false` | When true the log will show the Gui's internal debug messages |

### Segurança

Esta seção contém opções de segurança e começa com `[security]`

|Option                 |   Valid Values    |Description|
|:----------------------|:-----------------:|:-----------|
| checkPeerFingerprints | `true` or `false` | When true peers will have their fingerprints confirmed by the user and stored [default: true] |
| certificate           | Filepath          | Path to the certificate to use to encrypt messages.|
| keySize               | `2048` OR `4096`  | Size of the TLS key to use [default: 2048]| 
| tlsEnabled            | `true` or `false` | Are we using TLS encryption when communicating [default: true].|

### Servidor

Esta seção contém opções usadas no modo servidor e começa com `[server]`

|Option              |    Valid Values   |Description|
|:-------------------|:-----------------:|:-----------|
| clipboardSize      | int > 0           | OpenFlowKey will send a maximum of `N` megabytes of clipboard data to another computer when the mouse transitions to that computer.|
| defaultLockToComputerState| `true` or `false` | When this is true the cursor is locked to the new computer when switching (default: false)|
| disableLockToComputer| `true` or `false` | If false pressing scroll lock will toggle your cursor to be locked to current computer. (default: false) |
| enableClipboard    | `true` or `false` | When `true` the clipboard will be shared with all clients If set to ''true'' then clipboard shared and the ''clipboardSharingSize'' setting will be used. If set to false, then clipboard sharing will be disabled and the the ''clipboardSharingSize'' setting will be ignored.|
| enableHeartbeat    | `true` or `false` | Send a heartbeat to connected clients; this has been replaced by internal keep alive (default: false)|
| enableSwitchDelay  | `true` or `false` | Switching will be delayed by the set value (default: false)|
| enableSwitchDoubleTap  | `true` or `false` | Enables the doubletap to switch method (default: false)|
| externalConfig     | `true` or `false` | When true use the external config path |
| externalConfigFile | Filepath          | Path the server config file if it does not exist the GUI will it generated based on the `internalConfig` section.|
| gridHeight         | int               | Height of the server's intenal grid used for the computer layout (default: 3)|
| gridWidth          | int               | Width of the server's intenal grid used for the computer layout (default: 5) |
| heartbeat          | int               | The server will expect each client to send a message no less than every `N` milliseconds. If no message arrives from a client within `3N` seconds the server forces that client to disconnect. If openflowkey fails to detect clients disconnecting while the server is sleeping or vice versa, try using this option.|
| protocol           | `barrier` or `synergy` | The protocol to use when saying hello to clients. Can be set to barrier or synergy. If not set barrier is used as the default |
|relativeMouseMoves  | `true` or `false` | If set to ''true'' then secondary computers move the mouse using relative rather than absolute mouse moves when and only when the cursor is locked to the computer (by ''Scroll Lock'' or a configured hot key). This is intended to make OpenFlowKey work better with certain games. If set to ''false'' or not set then all mouse moves are absolute.|
| switchDelay        | int               | OpenFlowKey won't switch computers when the mouse reaches edge of a computer unless it stays on the edge for `N` milliseconds. This helps prevent unintentional switching when working near an edge. (default: 250)|
| switchDoubleTap    | int               | OpenFlowKey won't switch computers when the mouse reaches the edge of a computer unless it's moved away from the edge and then back to the edge within `N` milliseconds. With the option you have to quickly tap the edge twice to switch. This helps prevent unintentional switching when working near the edge.|
|win32KeepForeground | `true` or `false` | If set to ''true'' (the default), OpenFlowKey will grab the foreground focus on a Windows server (thereby putting all other windows in the background) upon switching to a client. If set to ''false'', it will leave the currently foreground window in the foreground. OpenFlowKey grabs the focus to avoid issues with other apps interfering with OpenFlowKey's ability to read the hardware inputs. |

 - You can use both the ''switchDelay'' and ''switchDoubleTap'' options at the same time. OpenFlowKey will switch when either requirement is satisfied.

### Configurações de Tela

Cada tela terá uma seção onde sua configuração é armazenada; se a tela foi nomeada "foo" a seção será chamada `[screen_foo]`

|Option              |    Valid Values    |Description|
|:-------------------|:------------------:|:-----------|
| aliases            | Comma separated list of hostnames | Names here will be used as alternatives for the computer. Names must be valid hostnames. |


### InternalConfig

Esta seção contém opções usadas no modo servidor e começa com `[internalConfig]`
bloco de um arquivo de configuração de servidor como visto abaixo. Esta seção é usada pela GUI para gerar a configuração do servidor

```
[internalConfig]
hotkeys\1\actions\1\activeOnRelease=false
hotkeys\1\actions\1\hasScreens=true
hotkeys\1\actions\1\keys\1\key=83
hotkeys\1\actions\1\keys\size=1
hotkeys\1\actions\1\lockCursorToScreen=0
hotkeys\1\actions\1\restartServer=false
hotkeys\1\actions\1\switchInDirection=0
hotkeys\1\actions\1\switchScreenName=void
hotkeys\1\actions\1\type=0
hotkeys\1\actions\1\typeScreenNames\size=0
hotkeys\1\actions\size=1
hotkeys\1\keys\1\key=83
hotkeys\1\keys\size=1
hotkeys\size=1
screens\1\name=
screens\10\fixArray\1\fix=false
screens\10\fixArray\2\fix=false
screens\10\fixArray\3\fix=false
screens\10\fixArray\4\fix=false
screens\10\fixArray\size=4
screens\10\modifierArray\1\modifier=0
screens\10\modifierArray\2\modifier=1
screens\10\modifierArray\3\modifier=2
screens\10\modifierArray\4\modifier=3
screens\10\modifierArray\5\modifier=4
screens\10\modifierArray\6\modifier=5
screens\10\modifierArray\size=6
screens\10\name=null
screens\10\switchCornerArray\1\switchCorner=false
screens\10\switchCornerArray\2\switchCorner=false
screens\10\switchCornerArray\3\switchCorner=false
screens\10\switchCornerArray\4\switchCorner=false
screens\10\switchCornerArray\size=4
screens\10\switchCornerSize=0
screens\11\name=
screens\12\name=
screens\13\name=
screens\14\name=
screens\15\name=
screens\2\name=
screens\3\name=
screens\4\name=
screens\5\name=
screens\6\name=
screens\7\fixArray\1\fix=false
screens\7\fixArray\2\fix=false
screens\7\fixArray\3\fix=false
screens\7\fixArray\4\fix=false
screens\7\fixArray\size=4
screens\7\modifierArray\1\modifier=0
screens\7\modifierArray\2\modifier=1
screens\7\modifierArray\3\modifier=2
screens\7\modifierArray\4\modifier=3
screens\7\modifierArray\5\modifier=4
screens\7\modifierArray\6\modifier=5
screens\7\modifierArray\size=6
screens\7\name=void
screens\7\switchCornerArray\1\switchCorner=false
screens\7\switchCornerArray\2\switchCorner=false
screens\7\switchCornerArray\3\switchCorner=false
screens\7\switchCornerArray\4\switchCorner=false
screens\7\switchCornerArray\size=4
screens\7\switchCornerSize=0
screens\8\fixArray\1\fix=false
screens\8\fixArray\2\fix=false
screens\8\fixArray\3\fix=false
screens\8\fixArray\4\fix=false
screens\8\fixArray\size=4
screens\8\modifierArray\1\modifier=0
screens\8\modifierArray\2\modifier=1
screens\8\modifierArray\3\modifier=2
screens\8\modifierArray\4\modifier=3
screens\8\modifierArray\5\modifier=4
screens\8\modifierArray\6\modifier=5
screens\8\modifierArray\size=6
screens\8\name=chris-Precision-5570
screens\8\switchCornerArray\1\switchCorner=false
screens\8\switchCornerArray\2\switchCorner=false
screens\8\switchCornerArray\3\switchCorner=false
screens\8\switchCornerArray\4\switchCorner=false
screens\8\switchCornerArray\size=4
screens\8\switchCornerSize=0
screens\9\fixArray\1\fix=false
screens\9\fixArray\2\fix=false
screens\9\fixArray\3\fix=false
screens\9\fixArray\4\fix=false
screens\9\fixArray\size=4
screens\9\modifierArray\1\modifier=0
screens\9\modifierArray\2\modifier=1
screens\9\modifierArray\3\modifier=2
screens\9\modifierArray\4\modifier=3
screens\9\modifierArray\5\modifier=4
screens\9\modifierArray\6\modifier=5
screens\9\modifierArray\size=6
screens\9\name=abyss.lan
screens\9\switchCornerArray\1\switchCorner=false
screens\9\switchCornerArray\2\switchCorner=false
screens\9\switchCornerArray\3\switchCorner=false
screens\9\switchCornerArray\4\switchCorner=false
screens\9\switchCornerArray\size=4
screens\9\switchCornerSize=0
screens\size=15
```


# Configuração do Servidor

The `openflowkey-server` command accepts the `-c` or `--config` option, which takes one argument,
the path to a server configuration file. When using the GUI the `internalConfig` section of the GUI settings will be exported as the server configuration.
O arquivo de configuração é texto puro e sensível a maiúsculas. O arquivo é dividido em seções, cada uma com a forma:
```
section: ''name''
	''arg'' = ''value''
end
```

Comentários são introduzidos por ''#'' e continuam até o fim da linha. ''name'' must be one of the following:

* ''screens''
* ''links''
* ''options''

O arquivo é analisado de cima para baixo e nomes não podem ser usados antes they've been defined in the `screens` or as an alias in the general config. So the `links` must appear after the `screens`.

### A seção screens

''args'' é uma lista de nomes de computadores, um por linha, cada um seguido por dois pontos. Names are arbitrary strings but they must be unique. The hostname of each computer is recommended. (This is the computer's network name on win32 and the name reported by the program hostname on Unix and OS X. Note that OS X may append .local to the name you gave your computer; e.g. somehost.local.) There must be a computer name for the server and each client. Each computer can specify a number of options. Options have the form name = value and are listed one per line after the computer name.

```
section: screens
	moe:
	larry:
		halfDuplexCapsLock = true
		halfDuplexNumLock = true
	curly:
		meta = alt
end
```

This declares three computers named ''moe'', ''larry'', and ''curly''. Computer ''larry'' has half-duplex ''Caps Lock'' and ''Num Lock'' keys (see below) and computer ''curly'' converts the ''Meta'' modifier key to the ''Alt'' modifier key.

#### opções de tela

Um computador pode ter as seguintes opções:

|Option | Valid Values| Description|
|:----------|:-----------:|:-----------|
|halfDuplexCapsLock| `true` or `false` | This computer has a ''Caps Lock'' key that doesn't report a press and a release event when the user presses it but instead reports a press event when it's turned on and a release event when it's turned off. If ''Caps Lock'' acts strangely on all computers then you may need to set this option to true on the server. If it acts strangely on one computer then that computer may need the option set to true.|
|halfDuplexNumLock | `true` or `false` | This computer has a ''Num Lock'' key that doesn't report a press and a release event when the user presses it but instead reports a press event when it's turned on and a release event when it's turned off. If ''Num Lock'' acts strangely on all computers then you may need to set this option to true on the server. If it acts strangely on one computer then that computer may need the option set to true.|
|halfDuplexScrollLock| `true` or `false`| This computer has a ''Scroll Lock'' key that doesn't report a press and a release event when the user presses it but instead reports a press event when it's turned on and a release event when it's turned off. If ''Scroll Lock'' acts strangely on all computers then you may need to set this option to true on the server. If it acts strangely on one computer then that computer may need the option set to true.|
|xtestIsXineramaUnaware| `true` or `false`| This option works around a bug in the XTest extension when used in combination with Xinerama. It affects X11 clients only. Not all versions of the XTest extension are aware of the Xinerama extension. As a result, they do not move the mouse correctly when using multiple Xinerama screens. This option is currently ''true'' by default. If you know your XTest extension is Xinerama aware then set this option to ''false''.|
|preserveFocus| `true` or `false` | When true don't drop focus when switching computers|
|switchCorners | none top-left top-right bottom-left bottom-right left right top bottom all | OpenFlowKey won't switch computers when the mouse reaches the edge of the computer if it's in a listed corner. The size of all corners is given by the `switchCornerSize` option. The first name in the list is one of the above names and defines the initial set of corners. Subsequent names are prefixed with + or - to add the corner to or remove the corner from the set, respectively. For example: `all -left +top-left` starts will all corners, removes the left corners (top and bottom) then adds the top-left back in, resulting in the top-left, bottom-left and bottom-right corners.|
|switchCornerSize | integer (N) | Sets the size of all corners in pixels. The cursor must be within `N` pixels of the corner to be considered to be in the corner.|
|shift | shift ctrl alt meta super none | Map the server's shift modifer to different key on a client computer|
|ctrl  | shift ctrl alt meta super none | Map the server's ctrl modifer to different key on a client computer|
|alt | shift ctrl alt meta super none | Map the server's alt modifer to different key on a client computer|
|meta|  shift ctrl alt meta super none | Map the server's meta modifer to different key on a client computer|
|super|  shift ctrl alt meta super none | Map the server's super modifer to different key on a client computer|

### seção links

''args'' é uma lista de nomes de computadores como na seção ''screens'', exceto que cada computador é seguido por uma lista de links, um por linha. Cada link tem a forma:
```
 {left|right|up|down}[<range>] = name[<range>]
```

Um link indica qual computador é adjacente na direção dada.

Cada lado de um link pode especificar um intervalo que define uma porção de uma borda. A range on the direction is the portion of edge you can leave from while a range on the computer is the portion of edge you'll enter into. Ranges are optional and default to the entire edge. All ranges on a particular direction of a particular computer must not overlap.

A ''range'' is written as <code>(start,end)</code>. Both ''start'' and ''end'' are percentages in the range 0 to 100, inclusive. The start must be less than the end. 0 is the left or top of an edge and 100 is the right or bottom. 

```
section: links
	moe:
		right        = larry
		up(50,100)   = curly(0,50)
	larry:
		left         = moe
		up(0,50)     = curly(50,100)
	curly:
		down(0,50)   = moe
		down(50,100) = larry(0,50)
end
```

This indicates that computer ''larry'' is to the right of computer ''moe'' (so moving the cursor off the right edge of ''moe'' would make it appear at the left edge of ''larry''), the left half of curly is above the right half of ''moe'', ''moe'' is to the left of ''larry'' (edges are not necessarily symmetric so you have to provide both directions), the right half of curly is above the left half of ''larry'', all of ''moe'' is below the left half of ''curly'', and the left half of ''larry'' is below the right half of ''curly''.

Note that links do not have to be symmetrical; for instance, here the edge between ''moe'' and ''curly'' maps to different ranges depending on if you're going up or down. In fact links don't have to be bidirectional. You can configure the right of ''moe'' to go to ''larry'' without a link from the left of ''larry'' to ''moe''. It's possible to configure a computer with no outgoing links; the cursor will get stuck on that computer unless you have a hot key configured to switch off of that computer.

### seção options

''args'' é uma lista de linhas no formato <code>name = value</code>. Elas definem as opções globais.

```
section: options
        name = value
end
```

#### Lista de opções permitidas na seção options

| Options | Value Values| Description|
|:--------|:-----------:|:-----------|
|screenSaverSync| `true` or `false`| ''Note: Removed in v1.14.1'' If set to ''false'' then OpenFlowKey won't synchronize screen savers. Client screen savers will start according to their individual configurations. The server screen saver won't start if there is input, even if that input is directed toward a client computer.|
|keystroke(key) | actions | Binds the ''key'' combination key to the given ''actions''. ''key'' is an optional list of modifiers (''shift'', ''control'', ''alt'', ''meta'' or ''super'') optionally followed by a character or a key name, all separated by + (plus signs). You must have either modifiers or a character/key name or both. See below for `valid key names` and `actions`. Keyboard hot keys are handled while the cursor any computer. Separate actions can be assigned to press and release.|
|mousebutton(button) | actions| Binds the modifier and mouse button combination ''button'' to the given ''actions''. ''button'' is an optional list of modifiers (''shift'', ''control'', ''alt'', ''meta'' or ''super'') followed by a button number. The primary button (the left button for right handed users) is button 1, the middle button is 2, etc. Actions can be found below. Mouse button actions are not handled while the cursor is on the server. You cannot use these to perform an action while on the server. Separate actions can be assigned to press and release.|

##### Ações

Ações são duas listas de ações individuais separadas por vírgulas. The two lists are separated by a '';'' (semicolon). Either list can be empty and if the second list is empty then the semicolon is optional. The first list lists actions to take when the condition becomes true (e.g. the hot key or mouse button is pressed) and the second lists actions to take when the condition becomes false (e.g. the hot key or button is released). The condition becoming true is called activation and becoming false is called deactivation. Allowed individual actions are:

* `keystroke(key[,computers])`

* `keyDown(key[,computers])`

* `keyUp(key[,computers])`


: Synthesizes the modifiers and key given in ''key'' which has the same form as described in the ''keystroke'' option. If given, ''computers'' lists the computer or computers to direct the event to, regardless of the active computer. If not given then the event is directed to the active computer only.
: ''keyDown'' synthesizes a key press and ''keyUp'' synthesizes a key release. ''keystroke'' synthesizes a key press on activation and a release on deactivation and is equivalent to a ''keyDown'' on activation and ''keyUp'' on deactivation.
: ''computers'' is either ''*'' (asterisk) to indicate all computers or a '':'' (colon) separated list of computer names. (Note that the computer name must have already been encountered in the configuration file so you'll probably want to put ''actions'' at the bottom of the file.)

* `mousebutton(button)`
* `mouseDown(button)`
* `mouseUp(button)`
: Synthesizes the modifiers and mouse button given in ''button'' which has the same form as described in the ''mousebutton'' option.
: ''mouseDown'' synthesizes a mouse press and ''mouseUp'' synthesizes a mouse release. ''mousebutton'' synthesizes a mouse press on activation and a release on deactivation and is equivalent to a ''mouseDown'' on activation and ''mouseUp'' on deactivation.

* `lockCursorToScreen(mode)`
: Locks the cursor to or unlocks the cursor from the active computer. ''mode'' can be ''off'' to unlock the cursor, ''on'' to lock the cursor, or ''toggle'' to toggle the current state. The default is ''toggle''. If the configuration has no ''lockCursorToScreen'' action and ''Scroll Lock'' is not used as a hot key then ''Scroll Lock'' toggles cursor locking.

* `switchToScreen(computerName)`
: Jump to computer with name or alias ''computerName''.

* `switchInDirection(dir)`
: Switch to the computer in the direction ''dir'', which may be one of ''left'', ''right'', ''up'' or ''down''.

* `switchToNextScreen()`
: Cycle to the next computer in the configuration order. If at the last computer, cycles back to the first computer.

##### Nomes de Teclas
Nomes de teclas válidos são:

* AppMail
* AppMedia
* AppUser1
* AppUser2
* AudioDown
* AudioMute
* AudioNext
* AudioPlay
* AudioPrev
* AudioStop
* AudioUp
* BackSpace
* Begin
* Break
* Cancel
* CapsLock
* Clear
* Delete
* Down
* Eject
* End
* Escape
* Execute
* F1
* F2
* F3
* F4
* F5
* F6
* F7
* F8
* F9
* F10
* F11
* F12
* F13
* F14
* F15
* F16
* F17
* F18
* F19
* F20
* F21
* F22
* F23
* F24
* F25
* F26
* F27
* F28
* F29
* F30
* F31
* F32
* F33
* F34
* F35
* Find
* Help
* Home
* Insert
* KP_0
* KP_1
* KP_2
* KP_3
* KP_4
* KP_5
* KP_6
* KP_7
* KP_8
* KP_9
* KP_Add
* KP_Begin
* KP_Decimal
* KP_Delete
* KP_Divide
* KP_Down
* KP_End
* KP_Enter
* KP_Equal
* KP_F1
* KP_F2
* KP_F3
* KP_F4
* KP_Home
* KP_Insert
* KP_Left
* KP_Multiply
* KP_PageDown
* KP_PageUp
* KP_Right
* KP_Separator
* KP_Space
* KP_Subtract
* KP_Tab
* KP_Up
* Left
* LeftTab
* Linefeed
* Menu
* NumLock
* PageDown
* PageUp
* Pause
* Print
* Redo
* Return
* Right
* ScrollLock
* Select
* Sleep
* Space
* SysReq
* Tab
* Undo
* Up
* WWWBack
* WWWFavorites
* WWWForward
* WWWHome
* WWWRefresh
* WWWSearch
* WWWStop
* Space
* Exclaim
* DoubleQuote
* Number
* Dollar
* Percent
* Ampersand
* Apostrophe
* ParenthesisL
* ParenthesisR
* Asterisk
* Plus
* Comma
* Minus
* Period
* Slash
* Colon
* Semicolon
* Less
* Equal
* Greater
* Question
* At
* BracketL
* Backslash
* BracketR
* Circumflex
* Underscore
* Grave
* BraceL
* Bar
* BraceR
* Tilde

Além disso, um nome no formato `\uXXXX` where ''XXXX'' is a hexadecimal number é interpretado como código de caractere unicode. Key and modifier names are case-insensitive. Keys that don't exist on the keyboard or in the default keyboard layout will not work.

### Exemplo de arquivo de configuração textual

A seção alias não está mais na configuração do servidor

Este exemplo vem de doc/openflowkey-basic.conf

```
# sample openflowkey configuration file
#
# comments begin with the # character and continue to the end of
# line.  comments may appear anywhere the syntax permits.
# +-------+  +--------+ +---------+
# |Laptop |  |Desktop1| |iMac     |
# |       |  |        | |         |
# +-------+  +--------+ +---------+

section: screens
	# three hosts named:  Laptop, Desktop1, and iMac
	# These are the nice names of the hosts to make it easy to write the config file
	# The aliases section below contain the "actual" names of the hosts (their hostnames)
	Laptop:
	Desktop1:
	iMac:
end

section: links
	# iMac is to the right of Desktop1
	# Laptop is to the left of Desktop1
	Desktop1:
	        right(0,100) = iMac # the numbers in parentheses indicate the percentage of the computer's edge to be considered active for switching)
		left  = Laptop
		shift = shift (shift, alt, super, meta can be mapped to any of the others)
	# Desktop1 is to the right of Laptop
	Laptop:
		right = Desktop1
	# Desktop1 is to the left of iMac
	iMac:
		left  = Desktop1
end
section: aliases
	# The "real" name of iMac is John-Smiths-iMac-3.local. 
	# If we wanted we could remove this alias and instead use John-Smiths-iMac-3.local everywhere iMac is above. 
	# Hopefully it should be easy to see why using an alias is nicer
	iMac:
		John-Smiths-iMac-3.local
end
```

#### Envolvimento do Cursor

A configuração de texto permite que computadores sejam envolvidos (wrap around). For example, with two machines (a server and a client), the mouse can go off the right of the server onto the left side of the client, then off the right side of the client back onto the left side of server. This config also uses ''Ctrl''+''Super''+(''left arrow''/''right arrow'') to switch between machines on keypress.

```
# Physical monitor arrangement, with machine names as used by OpenFlowKey.
#  +----------+----------+
#  | syn-serv | syn-cli  |
#  |          |          |
#  +----------+----------+ 
 
section: screens
	syn-serv:
	syn-cli:
end
section: links
	syn-serv:
		left = syn-cli     # "wrapping" arrangement
		right = syn-cli    # "normal" arrangement
	syn-cli:
		left = syn-serv    # "normal"
		right = syn-serv   # "wrapping"
end
section: options
                keystroke(control+super+right) = switchInDirection(right) # Switch computers on keypress 
<!--		keystroke(control+super+left) = switchInDirection(left) -->
end
```

### Tecla AltGr

A configuração de tela a seguir permite o mapeamento de ''Alt'' para ''AltGr''. Embora possa não funcionar, veja [https://github.com/openflowkey/openflowkey-core/issues/4411 bug #4411].
```
section: screens
	client1:
		altgr = alt          # mapping to fix AltGr key not working on windows clients (e.g. @-Symbol etc.).
end
```

Veja também: a página man de ''openflowkey-core''.

### Exemplo Empilhado

Empilhe um computador sobre o outro's.

```
#           +-------+
#           | curly |
#           |       |
#           +-------+
# +-------+ +-------+
# | moe   | | larry |
# |       | |       |
# +-------+ +-------+

section: screens
	# three hosts named: moe, larry, and curly
	moe:
	larry:
	curly:
end

section: links
	# larry is to the right of moe and curly is above moe.
	moe:
		right = larry
		up    = curly

	# moe is to the left of larry and curly is above larry.
	larry:
		left  = moe
		up    = curly

	# larry is below curly.
	curly:
		down  = larry
end

section: aliases
	# curly is also known as shemp
	curly:
		shemp
end
```

### Exemplo Horizontal

Alinhe todos os computadores horizontalmente.

```
# +-------+ +-------+ +-------+
# | moe   | | larry | | curly |
# |       | |       | |       |
# +-------+ +-------+ +-------+

section: screens
	# three hosts named: moe, larry, and curly
	moe:
	larry:
	curly:
end

section: links
	# curly is to the right of larry and moe is to the left of larry.
	larry:
		right = curly
		left  = moe

	# larry is to the right of moe.
	moe:
		right = larry

	# larry is to the left of curly.
	curly:
		left  = larry
end

```

### Exemplo de Extensão

Estenda um computador sobre os outros dois.

```
# +-------+ +-------+
# | curly | | curly |
# |       | |       |
# +-------+ +-------+
# +-------+ +-------+
# | moe   | | larry |
# |       | |       |
# +-------+ +-------+

section: screens
	# three hosts named: moe, larry, and curly
	moe:
	larry:
	curly:
end

section: links
	# larry is to the right of moe and curly is above moe.
	moe:
		right = larry
		up    = curly

	# moe is to the left of larry and curly is above larry.
	larry:
		left  = moe
		up    = curly

	# larry is below curly.
	curly:
		down  = larry
end
```
