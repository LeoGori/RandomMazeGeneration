#include "MenuLoop.h"
#include "Graphic.h"
#include "Game.h"

using namespace std;
using namespace sf;

MenuLoop::MenuLoop(int sizeX, int sizeY, vector<Vector2i> moves) {

    size = Vector2i (sizeX, sizeY);
    window.create(sf::VideoMode(sizeX * 32,sizeY * 32), "Maze Random Generator");
    this->moves = moves;
}

MenuLoop::~MenuLoop()=default;

void MenuLoop::generateScreen() {

    Graphic graphic(new Game(window, moves, size));
    times = seconds(10);

    while (window.isOpen()) {

        while (window.pollEvent(event)) {

                graphic.setInput(event, window);
        }

        if (!graphic.getState()) {
            if (times.asSeconds() > 0.5) {

                window.clear();

                graphic.draw(window);

                window.display();


                clock.restart(); //puts the time counter back to zero
            }
            times=clock.getElapsedTime(); //returns the time elapsed since the last call to restart()
        }
    }

}
