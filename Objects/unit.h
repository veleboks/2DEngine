#ifndef UNIT_H
#define UNIT_H

#include "gameobject.h"

class Unit : public GameObject
{
    // Drawable interface
protected:
    float SPEED;
    void draw(RenderTarget &target, RenderStates states) const override = 0;

    // GameObject interface
public:
    void logic() override = 0;
};

#endif // UNIT_H
