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
- [**_SFML_**](https://www.sfml-dev.org/) 2.5.0 graphic library

# Benchmarking
Checkout the benchmaks of the implementation [here](https://colab.research.google.com/drive/1kLGa8e6yBhUF3DqU0ZwF65sBCby3ecHZ?usp=sharing)!
