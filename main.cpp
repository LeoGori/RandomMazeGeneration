#include "Maze.h"
#include <iostream>
#include "MenuLoop.h"

using namespace std;


int main() {

    Tile* wall;
    Maze* map = new Maze(Vector2i (25, 17));

    map->setTileMap();

    Vector2i startPosition = Vector2i(0, 0);
    Vector2i endPosition = Vector2i(map->getWidth() - 1, map->getHeight() - 1);
    Vector2i wallPosition;

    vector<Vector2i> moves;

    while(! map->find(startPosition, endPosition)) {

        wallPosition = map->getRandomWall();

        // cout << wallPosition.x << ", " << wallPosition.y << endl;

        vector<Vector2i> wallNeighboursPos = map->getWallNeighboursPos(wallPosition);

        // cout << wallNeighboursPos[0].x << ", " << wallNeighboursPos[0].y << ", " << wallNeighboursPos[1].x << ", " << wallNeighboursPos[1].y << endl;

        if (! map->find(wallNeighboursPos[0], wallNeighboursPos[1])) {
            wall = &map->getTile(wallPosition);
            wall->setValue(map->getFloor());

            Tile* wallNeighbour1 = &map->getTile(wallNeighboursPos[0]);
            Tile* wallNeighbour2 = &map->getTile(wallNeighboursPos[1]);

            // cout << "Tile addresses: " << wallNeighbour1 << ", " << wallNeighbour2 << endl;

            // cout << "Tile findSet: "<< wallNeighbour1->findSet() << ", " << wallNeighbour2->findSet() << endl;

            wallNeighbour1->merge(*wallNeighbour2);

            // cout << wallNeighbour1->findSet() << ", " << wallNeighbour2->findSet() << " after merge" << endl;

            // cout << map->find(wallNeighboursPos[0], wallNeighboursPos[1]) << endl;

            moves.push_back(wallPosition);

        }
    }

    // cout << "################ done ###########" << endl;

    MenuLoop menuLoop(map->getWidth(), map->getHeight(), moves);
    menuLoop.generateScreen();

    return 0;
}


