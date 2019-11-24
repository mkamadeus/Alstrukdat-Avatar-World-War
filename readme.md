# Alstrukdat : Avatar World War
> A time when the Avatar dissappeared, a world war happens.

<p align="center">
    <img src="https://s1.zerochan.net/Avatar%3A.The.Last.Airbender.600.374938.jpg" alt="Fan Art Image">
</p>

This is a project/game in order to fulfill the requirements of the study of Alstrukdat. This game is awesome, try to play this game!

## Installing / Getting started

This is a quick run guide for the program:

If you're running on a Windows machine, run `compile.bat`:
```shell
compile.bat
```

Or if you're running on a Linux based machine, run `compile.sh`:
```shell
compile.sh
```

This script will compile and run the program, and after finished executing the `.exe`/`.out` file will be automatically deleted.

### Initial Configuration

For the game to be played, you will need to create `config.conf` file.
The format will be as the following:
```
<map row count> <map col count>
<building count>
<building type> <building row> <building col>
... repeated <building count> times
<adjacency matrix with size of building count * building count>
```

For example, if you wanted:
* Map size of 10x15
* Building count of 17 (predefined)

```
10 15
17
C 10 1
C 1 15
V 1 9
T 1 13
C 2 3
T 3 1
V 3 8
C 3 14
F 4 5
F 5 12
T 6 3
T 7 10
C 8 2
V 8 6
T 8 15
C 9 13
T 10 3
0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 1
0 0 0 1 0 0 0 1 0 0 0 0 0 0 0 0 0
0 0 0 1 0 0 1 1 0 0 0 0 0 0 0 0 0
0 1 1 0 0 0 0 1 0 0 0 0 0 0 0 0 0
0 0 0 0 0 1 1 0 1 0 0 0 0 0 0 0 0
0 0 0 0 1 0 0 0 1 0 1 0 0 0 0 0 0
0 0 1 0 1 0 0 1 1 1 0 0 0 0 0 0 0
0 1 1 1 0 0 1 0 0 1 0 0 0 0 1 0 0
0 0 0 0 1 1 1 0 0 1 1 1 0 0 0 0 0
0 0 0 0 0 0 1 1 1 0 0 1 0 0 1 0 0
0 0 0 0 0 1 0 0 1 0 0 1 1 1 0 0 0
0 0 0 0 0 0 0 0 1 1 1 0 0 1 0 1 0
1 0 0 0 0 0 0 0 0 0 1 0 0 1 0 0 1
0 0 0 0 0 0 0 0 0 0 1 1 1 0 0 0 1
0 0 0 0 0 0 0 1 0 1 0 0 0 0 0 1 0
0 0 0 0 0 0 0 0 0 0 0 1 0 0 1 0 0
1 0 0 0 0 0 0 0 0 0 0 0 1 1 0 0 0
```
