@echo off

echo Compiling program...
g++ -lm -o main23 ./core/src/*.c ./lib/src/*.c

main23.exe

del main.exe
