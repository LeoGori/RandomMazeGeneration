#include "Game.h"

#include <random>
#include <chrono>
#include "Tile.h"

using namespace std;
using namespace sf;

Game::Game(RenderWindow &window, vector<Vector2i> moves, Vector2i mazeSize) {

    this->moves = moves;

    moveIndex = 0;

    map = new Maze(mazeSize);

    map->setTileMap();

    map->load("Tileset1.png",Vector2u(32,32));

    Clock clock;
    Time times;

}

Game::~Game() {


    delete map;
}

void Game::getActivities(Event event, RenderWindow &window) {

    switch (event.type) {

        case Event::KeyReleased:
            switch (event.key.code) {
                case Keyboard::Escape:
                        setState(true);
                    break;

                default:
                    break;
            }
            break;


        case Event::Closed:
            window.close();
        default:
            break;
    }
}

void Game::draw(RenderWindow &window) {

    map->draw(window);
    update(window);

}

void Game::update(RenderWindow &window) {

    buildRandomMaze();

}


void Game::buildRandomMaze() {

    Vector2i startPosition = Vector2i(0, 0);
    Vector2i endPosition = Vector2i(map->getWidth() - 1, map->getHeight() - 1);
    Vector2i wallPosition;
    Tile* wall;

    if (moveIndex < moves.size()) {
        wallPosition = moves[moveIndex];
        moveIndex++;

        // cout << wallPosition.x << ", " << wallPosition.y << endl;

        wall = &map->getTile(wallPosition);
        wall->setValue(map->getFloor());
    }
    else {

        setState(true);
    }

}



