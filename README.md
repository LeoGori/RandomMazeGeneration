# Random Maze Generation
This repo contains the source files for the random generation of a maze through the use of Disjoint Set data structures, implemented using union by rank and path compression techniques.


# Code Description
The main files that build up the project are:

- [**_Tile.h_**](https://github.com/LeoGori/RandomMazeGeneration/blob/main/Tile.h): class that represents the tiles of the maze, and that acts as a disjoint set.
- [**_Maze.h_**](https://github.com/LeoGori/RandomMazeGeneration/blob/main/Maze.h): class that represents the maze, containing a matrix of tiles.
- [**_main.cpp_**](https://github.com/LeoGori/RandomMazeGeneration/blob/main/main.cpp): the entry point of the program, contains an instance of the class **Maze** and the call of its method for the execution of the random maze generation algorithm.

[**_Graphic.h_**](https://github.com/LeoGori/RandomMazeGeneration/blob/main/Graphic.h), [**_GraphicState.h_**](https://github.com/LeoGori/RandomMazeGeneration/blob/main/GraphicState.h), [**_MenuLoop.h_**](https://github.com/LeoGori/RandomMazeGeneration/blob/main/MenuLoop.h) and [**_Game.h_**](https://github.com/LeoGori/RandomMazeGeneration/blob/main/Game.h) are respectively used for the graphic presentation of the maze generation.

# Language and APIs
The code is entirely written in C++ programming language, with the use of the following libraries and APIs (omitting the standard ones):

- [**_random_**](https://www.cplusplus.com/reference/random/): used for the random selection of wall to be removed inside the maze
- [**_chrono_**](https://www.cplusplus.com/reference/chrono/): used for the presentation of the maze generation
- [**_SFML_**](https://www.sfml-dev.org/) graphic library


# How to run the code (Windows)

1. Install [MinGw64](https://winlibs.com/) version > 9.2 (otherwise the random selection of the wall will be the same at each execution, as reported [here](https://stackoverflow.com/questions/18880654/why-do-i-get-the-same-sequence-for-every-run-with-stdrandom-device-with-mingw) and [here](https://en.cppreference.com/w/cpp/numeric/random/random_device#:~:text=A%20notable%20implementation%20where%20std%3A%3Arandom_device%20is%20deterministic%20is%20old%20versions%20of%20MinGW%20(bug%20338%2C%20fixed%20since%20GCC%209.2).%20The%20latest%20MinGW%20versions%20can%20be%20downloaded%20from%20GCC%20with%20the%20MCF%20thread%20model))
2. Install [CMake](https://cmake.org/download/)
3. Create folder for building project
```
  mkdir build
  cd build
```
4.Generate the makefiles
```
  cmake -G “MinGW Makefiles” ..
```
5. build the project
```
  cmake --build .
```
6. run the program
```
  ./RandomMazeGeneration.exe
```
