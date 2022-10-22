#include "Maze.h"
#include <cmath>
#include <sstream>
#include <chrono>
#include <random>

Maze::Maze(Vector2i size) {
    this->size = size;
    setWall(42);
    setFloor(111);
    setJunctionWall(409);
    setStartPos(30);
    setEndPos(31);
    wallPositionIndex = 0;
}

bool Maze::load(const std::string &tileset, sf::Vector2u tileSize) {

    // load the map tileset texture

    if (!tilemapTexture.loadFromFile(tileset))
        return false;

    // resize the vertex array to fit the tile size

    m_vertices.setPrimitiveType(sf::Quads);

    m_vertices.resize(size.y * size.x * 4);

    // populate the vertex array, with one quad per tile

    for (unsigned int i = 0; i < size.y; i++) {

        for (unsigned int j = 0; j < size.x; j++) {

            // get the current tile number

            unsigned int tileNumber = tiles[i][j].getValue();

            // find its position in the tileset texture
            unsigned int tu = tileNumber % (tilemapTexture.getSize().x / tileSize.x);

            unsigned int tv = tileNumber / (tilemapTexture.getSize().x / tileSize.x);

            // get a pointer to the current tile's quad

            sf::Vertex *quad = &m_vertices[(j + i * size.x) * 4];

            // define its 4 cornvoid findDimension();ers

            quad[0].position = sf::Vector2f(j * tileSize.x, i * tileSize.y);

            quad[1].position = sf::Vector2f((j + 1) * tileSize.x, i * tileSize.y);

            quad[2].position = sf::Vector2f((j + 1) * tileSize.x, (i + 1) * tileSize.y);

            quad[3].position = sf::Vector2f(j * tileSize.x, (i + 1) * tileSize.y);

            // define its 4 texture coordinates

            quad[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);

            quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);

            quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);

            quad[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);
        }
    }

    states.texture=&tilemapTexture;

    return true;

}


void Maze::draw(RenderWindow &window) {

    load("Tileset1.png",Vector2u(32,32));

    window.draw(m_vertices,states);
}

void Maze::setTileMap() {

    // initialize the maze

    vector <Tile> lineTiles;
    Tile tile;

    for(int i=0;i<size.y;i++){
        for(int j=0;j<size.x;j++){
            if(i % 2 == 0) {
                if (j % 2 == 0) {
                    tile.setValue(floor);
                }
                else {
                    tile.setValue(wall);
                    wallPositions.emplace_back(j, i);
                }
            }
            else {
                if (i % 2 != 0 && j % 2 != 0) {
                    // value of the junction wall
                    tile.setValue(junctionWall);
                } else {
                    tile.setValue(wall);
                    wallPositions.emplace_back(j, i);
                }
            }
            lineTiles.push_back(tile);
        }
        tiles.push_back(lineTiles);
        lineTiles.clear();
    }

    tiles[0][0].setValue(startPosition);
    tiles[size.y - 1][size.x - 1].setValue(endPosition);

    std::random_device rd;
    auto rng = std::default_random_engine { rd() };
    std::shuffle(std::begin(wallPositions), std::end(wallPositions), rng);

}

Tile & Maze::getTile(Vector2i tileCoords) {

    return tiles[tileCoords.y][tileCoords.x];
}


int Maze::getHeight() {

    return size.y;
}

int Maze::getWidth() {

    return size.x;
}

void Maze::setWall(int wall) {

    this->wall=wall;
}

void Maze::setHeight(int height) {
    size.y = height;
}

void Maze::setWidth(int width) {
    size.x = width;
}

void Maze::setFloor(int floor) {
    Maze::floor = floor;
}

bool Maze::find(Vector2i tileCoords1, Vector2i tileCoords2) {
    Tile* tile1 = &getTile(tileCoords1);
    Tile* tile2 = &getTile(tileCoords2);

/*
    cout << tileCoords1.x << ", " << tileCoords1.y << "| " << tileCoords2.x << ", " << tileCoords2.y << endl;
*/

/*    cout << "Tile addresses in maze: " << tile1 << ", " << tile2 << endl;

    cout << tile1->findSet() << ", " << tile2->findSet() << endl;*/

    if (tile1->findSet() == tile2->findSet()) {
        return true;
    }
    else {
        return false;
    }
}

bool Maze::isWall(Vector2i tileCoords) {
    if (getTile(tileCoords).getValue() == wall)
        return true;
    return false;
}

vector<Vector2i> Maze::getWallNeighboursPos(Vector2i wallPos) {
    vector<Vector2i> wallNeighboursPos;

    if (wallPos.y %2 == 0) {

        Vector2i leftNeighbourPos = Vector2i(wallPos.x - 1, wallPos.y);
        Vector2i rightNeighbourPos = Vector2i(wallPos.x + 1, wallPos.y);

        wallNeighboursPos.push_back(leftNeighbourPos);
        wallNeighboursPos.push_back(rightNeighbourPos);
    }
    else {
        Vector2i upNeighbourPos = Vector2i(wallPos.x, wallPos.y - 1);
        Vector2i downNeighbourPos = Vector2i(wallPos.x, wallPos.y + 1);

        wallNeighboursPos.push_back(upNeighbourPos);
        wallNeighboursPos.push_back(downNeighbourPos);
    }

    return wallNeighboursPos;
}

int Maze::getFloor() {
    return floor;
}

Vector2i Maze::getRandomWall() {
    return wallPositions[wallPositionIndex ++];
}

void Maze::setJunctionWall(int junctWall) {
    junctionWall = junctWall;
}

int Maze::getJunctionWall() {
    return junctionWall;
}

void Maze::setStartPos(int startPos) {
    startPosition = startPos;
}

int Maze::getStartPos() {
    return startPosition;
}

void Maze::setEndPos(int endPos) {
    endPosition = endPos;
}

int Maze::getEndPos() {
    return endPosition;
}
