#ifndef MAZERANDOMGENERATION_GRAPHICSTATE_H
#define MAZERANDOMGENERATION_GRAPHICSTATE_H

#include <SFML/Graphics.hpp>


using namespace sf;

class GraphicState {
public:

    GraphicState();

    virtual bool getState();

    virtual void setState(bool state);

    virtual void draw(RenderWindow &window)=0;

    virtual void getActivities(Event event,RenderWindow &window)=0;

private:

    bool stateChanged;

};


#endif //MAZERANDOMGENERATION_GRAPHICSTATE_H
