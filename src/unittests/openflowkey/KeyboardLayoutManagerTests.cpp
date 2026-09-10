/*
 * OpenFlowKey -- mouse and keyboard sharing utility
 * SPDX-FileCopyrightText: (C) 2025 Chris Rizzitello <sithlord48@gmail.com>
 * SPDX-FileCopyrightText: (C) 2014 - 2024 Synergy App Ltd
 * SPDX-License-Identifier: GPL-2.0-only WITH LicenseRef-OpenSSL-Exception
 */

#include "KeyboardLayoutManagerTests.h"

#include "openflowkey/KeyboardLayoutManager.h"

void KeyboardLayoutManagerTests::initTestCase()
{
  m_log.setFilter(LogLevel::Level::Verbose);
}

void KeyboardLayoutManagerTests::remoteLayouts()
{
  std::string remoteLayouts = "ruenuk";
  openflowkey::KeyboardLayoutManager manager({"ru", "en", "uk"});

  manager.setRemoteLayouts(remoteLayouts);
  QCOMPARE(manager.getRemoteLayouts(), (std::vector<std::string>{"ru", "en", "uk"}));

  manager.setRemoteLayouts(std::string());
  QVERIFY(manager.getRemoteLayouts().empty());
}

void KeyboardLayoutManagerTests::remoteLayoutsOddPayload()
{
  // regression: 1-byte LSYN payload must not crash with std::out_of_range
  // (GH openflowkey#10107 — malicious server DoS)
  openflowkey::KeyboardLayoutManager manager({"ru", "en", "uk"});
  manager.setRemoteLayouts(std::string_view{"a"});
  QVERIFY(manager.getRemoteLayouts().empty());
}

void KeyboardLayoutManagerTests::localLayout()
{
  std::vector<std::string> localLayouts = {"ru", "en", "uk"};
  openflowkey::KeyboardLayoutManager manager(localLayouts);
  QCOMPARE(manager.getLocalLayouts(), (std::vector<std::string>{"ru", "en", "uk"}));
}

void KeyboardLayoutManagerTests::missedLayout()
{
  std::string remoteLayouts = "ruenuk";
  std::vector<std::string> localLayouts = {"en"};
  openflowkey::KeyboardLayoutManager manager(localLayouts);

  manager.setRemoteLayouts(remoteLayouts);
  QCOMPARE(manager.getMissedLayouts(), "ru, uk");
}

void KeyboardLayoutManagerTests::layoutInstall()
{
  std::vector<std::string> localLayouts = {"ru", "en", "uk"};
  openflowkey::KeyboardLayoutManager manager(localLayouts);

  QVERIFY(!manager.isLayoutInstalled("us"));
  QVERIFY(manager.isLayoutInstalled("en"));
}

void KeyboardLayoutManagerTests::serializeLocalLayouts()
{
  std::vector<std::string> localLayouts = {"ru", "en", "uk"};
  openflowkey::KeyboardLayoutManager manager(localLayouts);

  QCOMPARE(manager.getSerializedLocalLayouts(), "ruenuk");
}

QTEST_MAIN(KeyboardLayoutManagerTests)
