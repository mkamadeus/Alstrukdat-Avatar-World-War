@echo off

g++ -lm -o main2 ./core/src/*.c ./lib/src/*.c
main2.exe
del main.exe
