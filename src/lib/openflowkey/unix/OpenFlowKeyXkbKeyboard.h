/*
 * OpenFlowKey -- mouse and keyboard sharing utility
 * SPDX-FileCopyrightText: (C) 2012 - 2021 Synergy App Ltd
 * SPDX-FileCopyrightText: (C) 2002 Chris Schoeneman
 * SPDX-License-Identifier: GPL-2.0-only WITH LicenseRef-OpenSSL-Exception
 */

#if WINAPI_XWINDOWS

#pragma once

#include <X11/XKBlib.h>
#include <X11/extensions/XKBrules.h>

namespace openflowkey::linux {

class OpenFlowKeyXkbKeyboard
{
  XkbRF_VarDefsRec m_data = {};

public:
  OpenFlowKeyXkbKeyboard();
  OpenFlowKeyXkbKeyboard(const OpenFlowKeyXkbKeyboard &) = delete;
  OpenFlowKeyXkbKeyboard &operator=(const OpenFlowKeyXkbKeyboard &) = delete;

  const char *getLayout() const;
  const char *getVariant() const;

  ~OpenFlowKeyXkbKeyboard();
};

} // namespace openflowkey::linux

#endif // WINAPI_XWINDOWS
