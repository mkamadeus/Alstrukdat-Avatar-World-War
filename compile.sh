#!/bin/bash
gcc -lm -o main ./core/src/*.c
if [ $? -eq 0 ]; then
	clear
    ./main
	rm main
else
    echo Compilation failed, exiting.
fi