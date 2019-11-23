@echo off

g++ -lm -o main ./core/src/*.c ./lib/src/*.c
main.exe
del main.exe
