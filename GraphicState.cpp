#include "GraphicState.h"


GraphicState::GraphicState() {

    stateChanged=false;
}

bool GraphicState::getState() {
    return stateChanged;
}

void GraphicState::setState(bool state) {

    stateChanged=state;
}

