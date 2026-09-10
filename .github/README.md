<picture>
  <source media="(prefers-color-scheme: dark)" srcset="https://github.com/openflowkey/openflowkey-artwork/blob/main/logo/openflowkey-logo-dark-200px.png?raw=true">
  <source media="(prefers-color-scheme: light)" srcset="https://github.com/openflowkey/openflowkey-artwork/blob/main/logo/openflowkey-logo-light-200px.png?raw=true">
  <img alt="OpenFlowKey" src="https://github.com/user-attachments/assets/f005b958-24df-4f4a-9bfd-4f834dae59d6">
</picture>

**OpenFlowKey** is a free and open source keyboard and mouse sharing app.
Use the keyboard, mouse, or trackpad of one computer to control nearby computers,
and work seamlessly between them.
It's like a software KVM (but without the video).
TLS encryption is enabled by default. Wayland is supported. Clipboard sharing is supported.

> [!TIP]
>
> **Chat with us**
>
> - Main discussion on Matrix: [`#openflowkey:matrix.org`](https://matrix.to/#/#openflowkey:matrix.org) ([Matrix clients](https://matrix.org/ecosystem/clients/))
> - Discussion also happens on IRC: `#openflowkey` or `#openflowkey-dev` on [Libera Chat](https://libera.chat/)
> - Start a [new discussion](https://github.com/openflowkey/openflowkey/discussions) on our GitHub project.

## Download

[![Downloads: Stable Release](https://img.shields.io/github/downloads/openflowkey/openflowkey/latest/total?style=for-the-badge&logo=github&label=Download%20Stable)](https://github.com/openflowkey/openflowkey/releases/latest)&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;[![Downloads: Continuous Build](https://img.shields.io/github/downloads/openflowkey/openflowkey/continuous/total?style=for-the-badge&logo=github&label=Download%20Continuous)](https://github.com/openflowkey/openflowkey/releases/continuous)&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;[![Download From Flathub](https://img.shields.io/flathub/downloads/org.openflowkey.openflowkey?style=for-the-badge&logo=flathub&label=Download%20from%20flathub)](https://flathub.org/apps/org.openflowkey.openflowkey)

> [!NOTE]
> On Windows, you will need to install the
> [Microsoft Visual C++ Redistributable](https://learn.microsoft.com/en-us/cpp/windows/latest-supported-vc-redist?view=msvc-170#latest-microsoft-visual-c-redistributable-version).  
> Download latest: [`vc_redist.x64.exe`](https://aka.ms/vc14/vc_redist.x64.exe) [`vc_redist.arm64.exe`](https://aka.ms/vc14/vc_redist.arm64.exe)

> [!TIP]
> For macOS users, the easiest way to install and stay up to date is to use [Homebrew](https://brew.sh) with our [homebrew-tap](https://github.com/openflowkey/homebrew-tap).
> macOS reports unsigned apps as damaged. This occurs because we do not use an Apple certificate for notarization. Clear the quarantine attribute to run the app: `xattr -c OpenFlowKey.app`

To use OpenFlowKey, download one of our [packages](https://github.com/openflowkey/openflowkey/releases), install `openflowkey` (from your package repository), or [build it](https://github.com/openflowkey/openflowkey/wiki/Building) from source.

## Stats

[![GitHub commit activity](https://img.shields.io/github/commit-activity/m/openflowkey/openflowkey?logo=github)](https://github.com/openflowkey/openflowkey/commits/master/)
[![GitHub top language](https://img.shields.io/github/languages/top/openflowkey/openflowkey?logo=github)](https://github.com/openflowkey/openflowkey/commits/master/)
[![GitHub License](https://img.shields.io/github/license/openflowkey/openflowkey?logo=github)](LICENSE)
[![REUSE status](https://api.reuse.software/badge/github.com/openflowkey/openflowkey)](https://api.reuse.software/info/github.com/openflowkey/openflowkey)

[![Quality Gate Status](https://sonarcloud.io/api/project_badges/measure?project=openflowkey_openflowkey&metric=alert_status)](https://sonarcloud.io/summary/new_code?id=openflowkey_openflowkey)
[![Coverage](https://sonarcloud.io/api/project_badges/measure?project=openflowkey_openflowkey&metric=coverage)](https://sonarcloud.io/summary/new_code?id=openflowkey_openflowkey)
[![Code Smells](https://sonarcloud.io/api/project_badges/measure?project=openflowkey_openflowkey&metric=code_smells)](https://sonarcloud.io/summary/new_code?id=openflowkey_openflowkey)
[![Vulnerabilities](https://sonarcloud.io/api/project_badges/measure?project=openflowkey_openflowkey&metric=vulnerabilities)](https://sonarcloud.io/summary/new_code?id=openflowkey_openflowkey)

[![CI](https://github.com/openflowkey/openflowkey/actions/workflows/continuous-integration.yml/badge.svg)](https://github.com/openflowkey/openflowkey/actions/workflows/continuous-integration.yml)
[![CodeQL Analysis](https://github.com/openflowkey/openflowkey/actions/workflows/codeql-analysis.yml/badge.svg)](https://github.com/openflowkey/openflowkey/actions/workflows/codeql-analysis.yml)
[![SonarCloud Analysis](https://github.com/openflowkey/openflowkey/actions/workflows/sonarcloud-analysis.yml/badge.svg)](https://github.com/openflowkey/openflowkey/actions/workflows/sonarcloud-analysis.yml)

## Contribute

[![Good first issues](https://img.shields.io/github/issues/openflowkey/openflowkey/good%20first%20issue?label=good%20first%20issues&color=%2344cc11)](https://github.com/openflowkey/openflowkey/labels/good%20first%20issue)

There are many ways to contribute to the OpenFlowKey project.

We're a friendly, active, and welcoming community focused on building a great app.

Read our [Contributing](https://github.com/openflowkey/openflowkey/wiki/Contributing) page to get started.

For instructions on building OpenFlowKey, use the wiki page: [Building](https://github.com/openflowkey/openflowkey/wiki/Building)

## Operating Systems

We support all major operating systems, including Windows, macOS, Linux, and Unix-like BSD-derived.

Windows 10 v1809 or higher is required.

macOS 13 or higher is required to use our CI builds for Apple Silicon machines. macOS 12 or higher is required for Intel macs or local builds.

Linux requires libei 1.3+ and libportal 0.8+ for the server/client. Additionally, Qt 6.7+ is required for the GUI.
Linux users with systems not meeting these requirements should use flatpak in place of a native package.

We officially support FreeBSD, and would also like to support: OpenBSD, NetBSD, DragonFly, Solaris.

## Repology

Repology monitors a huge number of package repositories and other sources comparing package
versions across them and gathering other information.

[![Repology](https://repology.org/badge/vertical-allrepos/openflowkey.svg?columns=2&exclude_unsupported)](https://repology.org/project/openflowkey/versions)

## Installing on macOS

When you install OpenFlowKey on macOS, you need to allow accessibility access (Privacy & Security) to both the `OpenFlowKey` app and the `openflowkey` process.

If using Sequoia, you may also need to allow `OpenFlowKey` under Local Network‍ settings (Privacy & Security).
When prompted by the OS, go to the settings and enable the access.

If you are upgrading and you already have `OpenFlowKey` or `openflowkey`
on the allowed list you will need to manually remove them before accessibility access can be granted to the new version.

macOS users who download directly from releases may need to run `xattr -c /Applications/OpenFlowKey.app` after copying the app to the `Applications` dir.

It is recommended to install OpenFlowKey using [Homebrew](https://brew.sh) from our [homebrew-tap](https://github.com/openflowkey/homebrew-tap)

To add our tap, run:

```
brew tap openflowkey/tap
```

Then install either:

- Stable: `brew install openflowkey`
- Continuous: `brew install openflowkey-dev`

## Similar Projects

In the open source developer community, similar projects collaborate for the improvement of all
mouse and keyboard sharing tools. We aim for idea sharing and interoperability.

- [**Lan Mouse**](https://github.com/feschber/lan-mouse) -
  Rust implementation with the goal of having native front-ends and interoperability with
  OpenFlowKey/Synergy.
- [**Synergy**](https://symless.com/synergy) -
  Downstream commercial fork. Synergy sponsors OpenFlowKey with financial support and contributes code ([learn more](https://github.com/openflowkey/openflowkey/wiki/Relationship-with-Synergy)).
- [**Input Leap**](https://github.com/input-leap/input-leap) -
  Inactive OpenFlowKey/Synergy-derivative with the goal continuing Barrier development (now a dead fork).

## FAQ

### Is OpenFlowKey compatible with Synergy, Input Leap, or Barrier?

Yes, OpenFlowKey has network compatibility with all forks:

- Requires OpenFlowKey >= v1.17.0.96
- OpenFlowKey will _just work_ with Input Leap and Barrier (server or client).
- Connecting a OpenFlowKey client to a Synergy 1 server will also _just work_.
- To connect a Synergy 1 client, you need to select the Synergy protocol in the OpenFlowKey server settings.

_Note:_ Only Synergy 1 is compatible with OpenFlowKey (Synergy 3 is not yet compatible).

### Is OpenFlowKey compatible with Lan Mouse?

We would love to see compatibility with Lan Mouse. This may be quite an effort as currently the way they handle the generated input is very different.

### If I want to solve issues in OpenFlowKey do I need to contribute to a fork?

We welcome PRs (pull requests) from the community. If you'd like to make a change, please feel
free to [start a discussion](https://github.com/openflowkey/openflowkey/discussions) or
[open a PR](https://github.com/openflowkey/openflowkey/wiki/Contributing).

### Is clipboard sharing supported?

Absolutely. The clipboard-sharing feature is a cornerstone feature of the product and we are
committed to maintaining and improving that feature.

### Is Wayland for Linux supported?

Yes! Wayland (the Linux display server protocol aimed to become the successor of the X Window
System) is an important platform for us.
The [`libei`](https://gitlab.freedesktop.org/libinput/libei) and
[`libportal`](https://github.com/flatpak/libportal) libraries enable
Wayland support for OpenFlowKey. We would like to give special thanks to Peter Hutterer,
who is the author of `libei`, a major contributor to `libportal`, and the author of the Wayland
implementation in OpenFlowKey. Others such as Olivier Fourdan and Povilas Kanapickas helped with the
Wayland implementation.

Some features _may_ be unavailable or broken on Wayland. Please see the [known Wayland issues](https://github.com/openflowkey/openflowkey/discussions/7499).

### Where did it all start?

OpenFlowKey was first created as Synergy in 2001 by Chris Schoeneman.
Read about the [history of the project](https://github.com/openflowkey/openflowkey/wiki/History) on our
wiki.

## Meow'Dib (our mascot)

![Meow'Dib](https://github.com/user-attachments/assets/726f695c-3dfb-4abd-875d-ed658f6c610f)

## OpenFlowKey Contributors

[![Sponsored by Synergy](https://raw.githubusercontent.com/openflowkey/openflowkey-artwork/b2c72a3e60a42dee793bd47efc275b5ee0bdaa5f/misc/synergy-sponsor.svg)](https://symless.com/synergy)

[Synergy](https://symless.com/synergy) sponsors the OpenFlowKey project by contributing code and providing financial support ([learn more](https://github.com/openflowkey/openflowkey/wiki/Relationship-with-Synergy)).

OpenFlowKey is made by possible by these contributors.

 <a href = "https://github.com/openflowkey/openflowkey/graphs/contributors">
   <img src = "https://contrib.rocks/image?repo=openflowkey/openflowkey"/>
 </a>

## License

This project is licensed under [GPL-2.0](LICENSE) with an [OpenSSL exception](../LICENSES/LicenseRef-OpenSSL-Exception.txt).
