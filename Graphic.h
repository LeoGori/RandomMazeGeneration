//
// Created by leogori on 21/12/18.
//

#ifndef MAZERANDOMGENERATION_GRAPHIC_H
#define MAZERANDOMGENERATION_GRAPHIC_H


#include "GraphicState.h"
#include <vector>

using namespace std;

class Graphic {
public:

    Graphic();

    Graphic(GraphicState* gContext);

    virtual ~Graphic();

    void draw(RenderWindow &window);

    void setInput(Event event, RenderWindow &window);

    bool getState();

    GraphicState* getGraphicState();

private:

    GraphicState* graphicState;
};


#endif //PROJECT_GRAPHIC_H
