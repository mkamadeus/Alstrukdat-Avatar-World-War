@echo off

echo Compiling program...
g++ -lm -o main ./core/src/*.c ./array/array.c ./buildings/buildings.c ./command/command.c ./graph/graph.c ./list/linkedlist.c ./matrix/matrix.c ./mesinKata/mesin.c ./mesinKata/mesinkar.c ./pcolor/pcolor.c ./point/point.c ./queue/queue.c ./stack/stack.c

main.exe

del main.exe