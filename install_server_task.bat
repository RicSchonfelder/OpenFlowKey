@echo off
schtasks /create /tn "OpenFlowKey-Server" /tr "\"C:\Program Files\OpenFlowKey\openflowkey-core.exe\" server -s \"Y:\Programas\OpenFlowKey\server.conf\"" /sc onlogon /rl highest /f
schtasks /run /tn "OpenFlowKey-Server"
