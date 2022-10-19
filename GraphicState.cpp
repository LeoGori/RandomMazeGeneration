//
// Created by leogori on 21/12/18.
//

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

