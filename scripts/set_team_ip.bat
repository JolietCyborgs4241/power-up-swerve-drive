@echo off
SET /p team="Team: "

netsh interface ipv4 set address name="Wi-Fi" static 10.%team:~0,2%.%team:~2,4%.5 255.255.255.0