@echo off

echo Compiling program...
g++ -lm -o main22 ./core/src/*.c ./lib/src/*.c

main.exe

del main.exe
