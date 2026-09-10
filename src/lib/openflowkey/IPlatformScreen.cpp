/*
 * OpenFlowKey -- mouse and keyboard sharing utility
 * SPDX-FileCopyrightText: (C) 2016 Synergy App Ltd
 * SPDX-License-Identifier: GPL-2.0-only WITH LicenseRef-OpenSSL-Exception
 */

#include "openflowkey/IPlatformScreen.h"

bool IPlatformScreen::fakeMediaKey(KeyID)
{
  return false;
}
