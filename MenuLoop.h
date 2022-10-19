
#ifndef PROJECT_MENULOOP_H
#define PROJECT_MENULOOP_H

#include <SFML/Graphics.hpp>

#include <thread>
#include <chrono>

using namespace std;
using namespace sf;

class MenuLoop {
public:
    MenuLoop(int sizeX, int sizeY, vector<Vector2i> moves);

    ~MenuLoop();

    void generateScreen();


private:

    sf::Event event;

    sf::RenderWindow window;

    Time times;

    vector<Vector2i> moves;

    Clock clock;

    Vector2i size;


};

#endif //PROJECT_MENULOOP_H
