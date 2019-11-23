@echo off

g++ -lm -o main3 ./core/src/*.c ./lib/src/*.c
main3.exe
del main.exe
