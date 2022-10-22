#include "Graphic.h"
#include <iostream>

using namespace std;
using namespace sf;

Graphic::Graphic() {}

Graphic::Graphic(GraphicState *gContext) {

    graphicState = gContext;
}

Graphic::~Graphic() {}

void Graphic::draw(RenderWindow &window) {

    graphicState->draw(window);
}

void Graphic::setInput(Event event, RenderWindow &window) {

    graphicState->getActivities(event, window);
}

bool Graphic::getState() {

        return graphicState->getState();
}

GraphicState *Graphic::getGraphicState() {

    return graphicState;
}
