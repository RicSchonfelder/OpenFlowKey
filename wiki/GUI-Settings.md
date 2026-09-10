> Nota: idioma oficial do OpenFlowKey é português do Brasil.

# Configuração da GUI

 OpenFlowKey will automatically figure out where to save settings and other files.


## Caminhos de busca

OpenFlowKey will look for settings in several places depending on your operating system.
The search order for a setting file depends on your operating system

### Linux

  1. `<XDG_CONFIG_HOME>/OpenFlowKey/OpenFlowKey.conf`
  2. `~/.config/OpenFlowKey/OpenFlowKey.conf`
  3. `/etc/OpenFlowKey/OpenFlowKey.conf`
 
A new settings file will be created in the user path if no settings file is found.
The path of the settings file will be used as the base for all other config files.

### macOS
 
  1. `~/Library/OpenFlowKey/OpenFlowKey.conf`
  2. `/Library/OpenFlowKey/OpenFlowKey.conf`
 
A new settings file will be created in the user path if no settings file is found.
The path of the settings file will be used as the base for all other config files.

### Windows

  1. `<install-path>/settings/OpenFlowKey.conf`
  2. Windows Registry `HKCU\Software\OpenFlowKey\OpenFlowKey`

Windows will save to the install dir if settings are loaded from there. If not, it saves any other config files in: `C:\ProgramData\OpenFlowKey\`

When using settings from the install dir, the service mode will not be available.

### Caminhos Históricos

**v1.17.0 or higher**

- *Windows:* `\HKEY_CURRENT_USER\Software\OpenFlowKey\OpenFlowKey`
- *macOS:* `~/Library/Preferences/com.openflowkey.OpenFlowKey.plist`
- *Linux:* `~/.config/OpenFlowKey/OpenFlowKey.conf`

**v1.15.0 or v1.16.0**

- *Windows:* `\HKEY_CURRENT_USER\Software\Synergy\Synergy`
- *macOS:* `~/Library/Preferences/com.symless.Synergy.plist`
- *Linux:* `~/.config/Synergy/Synergy.conf`

**v1.14.x or lower**

- *Windows:* `\HKEY_CURRENT_USER\Software\Synergy\Synergy`
- *macOS:* `~/Library/Preferences/http-symless-com.Synergy.plist`
- *Linux:* `~/.config/Synergy/Synergy.conf`



## Chaves Válidas da GUI

The GUI config file contains several sections.
Each section is formatted the same.
Option-value pairs are only written if the value is not the default value.

```
[section]
option=value
```

### Client

This section contains options used when in client mode. 
It will begin with `[client]`

| Option            |    Valid Values    | Description |
|:------------------|:------------------:|:-----------|
| binary            | Filename           | The filename of the binary to call for client mode. This binary exists in the same path as the GUI |
| languageSync      | `true` or `false`  | Sync to server language [default: true] |
| remoteHost        | `IP` or `hostname` | The remote host(s) to connect to. Use a comma separated list when you want to try several hosts |
| yScrollScale      | Double 0.1 - 10.0  | Vertical mouse scrolling will be scaled by this amount on the client [default: 1.0] |
| xScrollScale      | Double 0.1 - 10.0  | Horizontal mouse scrolling will be scaled by this amount on the client [default: 1.0] |
| invertYScroll     | `true` or `false`  | Invert vertical scroll on this client [default: false] |
| invertXScroll     | `true` or `false`  | Invert horizontal scroll on this client [default: false] |
| xdpRestoreToken   | UUID               | Restore token provided by XDG portals  *state info not in settings file |

### Core
This section contains general options it will begin with `[core]`


|Option         | Valid Values|Description|
|:--------------|:-----------:|:-----------|
| coreMode      | `0` or `1` or `2` | The mode to start in 0: None, 1: Client, 2: Server [default: 0]|
| computerName    | string          | Name used to identify the computer [default: machine's hostname] (added 1.25.0.216) |
| display       |  int              | The XWindow display to use [default: autodetected] |
| interface     | IP Address        | Preferred IP to use for network communication. By default the server board casts on any available address |
| lastVersion   | M.m.p.t           | The version last run used for checking for updates |
| port          | port #            | Port to use when connecting [default: 24800 |
| preventSleep  | `true` or `false` | Prevent sleep when OpenFlowKey is active [default: false] |
| processMode   | `1` or `0`        | The mode we use to start the process Service or Desktop |
| screenName    | string            | Name used to identify the computer [default: machine's hostname] (removed 1.25.0.216) |
| startedBefore | `true` or `false `| Have we started client or server before. Used in logic when deciding to show some dialogs.
| updateUrl     | URL               | The URL to use when checking for a new version number, it should return a version [default: https://api.openflowkey.org/version]|
| useHooks      | `true` or `false` | If windows use use hooks or not [default: true] |
| language      | 639 language      | The language to display the GUI in [default: en] |
| wlClipboard   | `true` or `false` | When true the wl-clipboard backend will be enabled [default: false] (removed 1.26.0.xxx) |

### Daemon

This section contains options used by the daemon on windows it will begin with `[daemon]`

|Option | Valid Values|Description|
|:----------|:-----------:|:-----------|
| command   | Filename          | The filename of the binary the daemon. This binary exists in the same path as the openflowkey GUI |
| elevate   | `true` or `false` | Elevate the daemon app [default: true unless portable mode ] |
| logFile   | Filepath          | Filepath of the daemon log |
| logLevel  | valid log Level,  | Log Level  |

### GUI

This section contains options used by the GUI it will begin with `[gui]`

|Option                          | Valid Values      |Description|
|:-------------------------------|:-----------------:|:-----------|
| autoHide                       | `true` or `false` | When true the app will hide itself on start up [default: false] |
| enableUpdateCheck              | `true` or `false` | When true check the update URL to see if a new version was released on start up [default: false] |
| closeReminder                  | `true` or `false` | Used to track if we have shown the reminder that when you close the app it remain running in the background  [default: true]|
| closeToTray                    | `true` or `false` | When `true` the gui will run in the systemTray when its closed [default: true] |
| logExpanded                    | `true` or `false` | Should the log section of the GUI be opened [default: false] |
| symbolicTrayIcon               | `true` or `false` | When true use the monocolor (symbolic) icon false uses a colorful icon for the tray [default: true] |
| windowGeometry                 | QRect             | Geometry of the window used to restore the window geometry after exiting the app *state info not in settings file |
| showGenericClientFailureDialog | `true` or `false` | When `true` client connection errors will not show popup error messages [default: true]  | shownFirstConnectedMessage     | `true` or `false` | When `true` the first connected has been show and will not show again [default: false] 
| shownServerFirstStartMessage   | `true` or `false` | When `true` the first started message has been show and will not show again [default: false] |
| showVersionInTitle             | `true` or `false` | When `true` the version will be included in the window's title [default: false] |


### Log

This section contains options used by the application logging it will begin with `[log]`

|Option |    Valid Values   |Description|
|:------|:-----------------:|:-----------|
| file   | Filepath          | The file to write the log into |
| level  | Valid log level   | Log level to use |
| toFile | `true` or `false` | When true the log will be written to the value of the `file` option |
| guiDebug | `true` or `false` | When true the log will show the Guis internal debug messages |


### Security

This section contains options used by the application security it will begin with `[security]`

|Option                 |   Valid Values    |Description|
|:----------------------|:-----------------:|:-----------|
| checkPeerFingerprints | `true` or `false` | When true peers will have their fingerprints confirmed by the user and stored [default: true] |
| certificate           | Filepath          | Path to the certificate to use to encrypt messages.|
| keySize               | `2048` OR `4096`  | Size of the TLS key to use [default: 2048]| 
| tlsEnabled            | `true` or `false` | Are we using TLS encryption when communicating [default: true].|

### Server

This section contains options used when in server mode it will begin with `[server]`

|Option              |    Valid Values   |Description|
|:-------------------|:-----------------:|:-----------|
| externalConfig     | `true` or `false` | When true use the external config path |
| externalConfigFile | Filepath          | Path the server config file if it does not exist the GUI will it generated based on the `internalConfig` section.|
| protocol           | `barrier` or `synergy` | The protocol to use when saying hello to clients. Can be set to barrier or synergy. If not set barrier is used as the default (v1.26.0.156+)

### InternalConfig

This section contains options used when in server mode it will begin with `[internalConfig]`
block of a server config file as seen below. This section is used by the GUI to generate a server configuration

```
[internalConfig]
clipboardSharing=true
clipboardSharingSize=@Variant(\0\0\0\x84\0\0\0\0\0\0<\0)
disableLockToScreen=false
hasHeartbeat=false
hasSwitchDelay=false
hasSwitchDoubleTap=false
heartbeat=5000
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
numColumns=5
numRows=3
relativeMouseMoves=false
screens\1\name=
screens\10\aliasArray\size=0
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
screens\7\aliasArray\size=0
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
screens\8\aliasArray\size=0
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
screens\9\aliasArray\size=0
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
switchCornerArray\1\switchCorner=false
switchCornerArray\2\switchCorner=false
switchCornerArray\3\switchCorner=false
switchCornerArray\4\switchCorner=false
switchCornerArray\size=4
switchCornerSize=0
switchDelay=250
switchDoubleTap=250
win32KeepForeground=false
```
# Limpar

Clearing settings may help resolve some bugs.

## Reset suave 

If you have v1.15.0 or higher, use the GUI to reset the settings.

![image](https://github.com/user-attachments/assets/4b62b8c7-b585-432f-bbf3-1999a91c17f1)

## Reset completo
 
For a more thorough reset, you can delete the actual files on disk.

**Windows:**

First, ensure that Synergy is uninstalled.

Run `regedit` and delete these registry keys (if they exist):

* `HKEY_CURRENT_USER\Software\OpenFlowKey`

Now, delete these directories (if they exist):

* `%ProgramData%\OpenFlowKey`

**macOS:**

First, ensure that Synergy is uninstalled.

On newer macOS versions, you'll need to use `defaults delete` to clear the settings cache:
```
defaults delete com.symless.Synergy.plist
defaults delete com.http-symless-com.Synergy.plist
defaults delete com.https-symless-com.Synergy.plist
```

For all macOS versions, delete any files on disk:
```
rm -r ~/Library/Preferences/Symless
rm -r ~/Library/Synergy
rm ~/Library/Preferences/com.symless.Synergy.plist
rm ~/Library/Preferences/com.http-symless-com.Synergy.plist
rm ~/Library/Preferences/com.https-symless-com.Synergy.plist
```

On older macOS versions, you'll need to kill the `cfprefsd` process to clear the cache:
```
killall -u $USER cfprefsd
```

**Linux:**

First, ensure that Synergy is uninstalled.

Run these commands to delete these files and folders (if they exist):
```
rm -rf ~/.config/Synergy/
rm -rf ~/.config/Symless/
rm -rf ~/.synergy/
```

