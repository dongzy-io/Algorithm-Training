@echo off
chcp 65001 >nul
if not exist out mkdir out
javac -encoding UTF-8 -d out src/cinema/*.java
java -Dfile.encoding=UTF-8 -Dstdout.encoding=UTF-8 -cp out cinema.Main
pause
