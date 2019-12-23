#ifndef UNIT_H
#define UNIT_H

#include "damageobject.h"

class Unit : public DamageObject
{
    // Drawable interface
protected:
    float HP = 100;
    float SPEED;
    void draw(RenderTarget &target, RenderStates states) const override = 0;
    // GameObject interface
public:
    void logic() override = 0;

    // DamageObject interface
public:
    virtual FloatRect getGlobalBounds() = 0;
};

#endif // UNIT_H
