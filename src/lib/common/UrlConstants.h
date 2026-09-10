/*
 * OpenFlowKey -- mouse and keyboard sharing utility
 * SPDX-FileCopyrightText: (C) 2024 OpenFlowKey Devs
 * SPDX-License-Identifier: GPL-2.0-only WITH LicenseRef-OpenSSL-Exception
 */

#pragma once

#include <QString>

// important: this is used for settings paths on some platforms,
// and must not be a url. qt automatically converts this to reverse domain
// notation (rdn), e.g. org.openflowkey
const auto kOrgDomain = QStringLiteral("openflowkey.org");

const auto kUrlSourceQuery = QStringLiteral("source=gui");
const auto kUrlApp = QStringLiteral("https://github.com/openflowkey/openflowkey");
const auto kUrlHelp = QStringLiteral("https://github.com/openflowkey/openflowkey/wiki");
const auto kUrlDownload = QStringLiteral("https://github.com/openflowkey/openflowkey/releases");
const auto kUrlWiki = QStringLiteral("https://github.com/openflowkey/openflowkey/wiki");
const auto kUrlUpdateCheck = QStringLiteral("https://api.%1/version").arg(kOrgDomain);

#if defined(Q_OS_LINUX)
const auto kUrlGnomeTrayFix = QStringLiteral("https://extensions.gnome.org/extension/615/appindicator-support/");
#endif
