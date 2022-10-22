#include "Maze.h"
#include <iostream>
#include "MenuLoop.h"

using namespace std;

int main() {

    Tile* wall;
    Maze map(Vector2i (25, 17));

    // build the tilemap as a matrix of tiles, assigning at each tile its corresponding value based on the position
    map.setTileMap();

    // define start position, end position
    Vector2i startPosition = Vector2i(0, 0);
    Vector2i endPosition = Vector2i(map.getWidth() - 1, map.getHeight() - 1);
    // declare variable for storing the position of a generic wall
    Vector2i wallPosition;

    // declare sequence of positions of the wall that are sequentially removed
    vector<Vector2i> moves;

    // definition of the random maze generator algorithm
    while(! map.find(startPosition, endPosition)) {

        // get the position of a wall of the map chosen randomly
        wallPosition = map.getRandomWall();

        // cout << wallPosition.x << ", " << wallPosition.y << endl;

        // select its 2 neighbour cells, that are floor cells
        vector<Vector2i> wallNeighboursPos = map.getWallNeighboursPos(wallPosition);

        // cout << wallNeighboursPos[0].x << ", " << wallNeighboursPos[0].y << ", " << wallNeighboursPos[1].x << ", " << wallNeighboursPos[1].y << endl;

        // if the 2 floor cells do not share the same representative
        if (! map.find(wallNeighboursPos[0], wallNeighboursPos[1])) {

            // get the wall placed in the randomly chosen position
            wall = &map.getTile(wallPosition);
            // make it a floor cell, i.e. remove the wall
            wall->setValue(map.getFloor());

            // get the same floor tiles that are its neighbours
            Tile* wallNeighbour1 = &map.getTile(wallNeighboursPos[0]);
            Tile* wallNeighbour2 = &map.getTile(wallNeighboursPos[1]);

            // cout << "Tile addresses: " << wallNeighbour1 << ", " << wallNeighbour2 << endl;

            // cout << "Tile findSet: "<< wallNeighbour1->findSet() << ", " << wallNeighbour2->findSet() << endl;

            // perform the union of the 2 tiles
            wallNeighbour1->merge(*wallNeighbour2);

            // cout << wallNeighbour1->findSet() << ", " << wallNeighbour2->findSet() << " after merge" << endl;

            // cout << map->find(wallNeighboursPos[0], wallNeighboursPos[1]) << endl;

            // add the position of the randomly chosen wall into the sequence of positions
            moves.push_back(wallPosition);

        }
    }

    // cout << "################ done ###########" << endl;

    // present on screen
    MenuLoop menuLoop(map.getWidth(), map.getHeight(), moves);
    menuLoop.generateScreen();

    return 0;
}


