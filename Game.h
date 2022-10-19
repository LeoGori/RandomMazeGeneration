//
// Created by leogori on 21/12/18.
//

#ifndef MAZERANDOMGENERATION_GAME_H
#define MAZERANDOMGENERATION_GAME_H

#include "GraphicState.h"
#include "Maze.h"
#include <vector>



class Game: public GraphicState {
public:

    Game(RenderWindow &window, vector<Vector2i> moves, Vector2i mazeSize);

    ~Game();

    void draw(RenderWindow &window) override;

    void getActivities(Event e1vent, RenderWindow &window) override;

    void update(RenderWindow &window);

    void buildRandomMaze();

private:

    Maze* map;

    vector<Vector2i> moves;

    int moveIndex;


};


#endif //MAZERANDOMGENERATION_GAME_H
