//
// Created by leogori on 03/04/19.
//

#ifndef PROJECT_TILEBOSSMAP_H
#define PROJECT_TILEBOSSMAP_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <fstream>
#include <iostream>
#include "Tile.h"

using namespace std;
using namespace sf;

class Maze {

public:

    Maze(Vector2i size);

    bool load(const string& tileset, Vector2u tileSize);

    virtual void setTileMap();

    virtual void draw(RenderWindow &window);

    Tile &getTile(Vector2i tileCoords);

    void setWall(int wall);

    void setHeight(int height);

    void setWidth(int width);

    int getHeight();

    int getWidth();

    void setFloor(int floor);

    int getFloor();

    bool find(Vector2i tileCoords1, Vector2i tileCoords2);

    bool isWall(Vector2i tileCoords);

    vector<Vector2i> getWallNeighboursPos(Vector2i wallPos);

    Vector2i getRandomWall();

    void setJunctionWall(int junctWall);

    int getJunctionWall();

    void setStartPos(int startPos);

    int getStartPos();

    void setEndPos(int endPos);

    int getEndPos();

protected:

    Sprite sprite;

    int wall;

    int floor;

    int junctionWall;

    int startPosition;

    int endPosition;

    Vector2i size;

    vector<Vector2i> wallPositions;

    int wallPositionIndex;

    sf::VertexArray m_vertices;

    sf::Texture tilemapTexture;

    vector <vector<Tile>> tiles;

    RenderStates states;

};


#endif //PROJECT_TILEBOSSMAP_H
