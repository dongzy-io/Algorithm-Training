#!/bin/sh
mkdir -p out
javac -encoding UTF-8 -d out src/cinema/*.java && java -Dfile.encoding=UTF-8 -Dstdout.encoding=UTF-8 -cp out cinema.Main
