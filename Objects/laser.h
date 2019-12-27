#ifndef LIGHT_H
#define LIGHT_H

#include "damageobject.h"
#include "enemy.h"
#include "globals.h"
#include "cmath"
#include <float.h>

class Laser : public DamageObject
{
private:
    RectangleShape * sprite;
public:
    Laser(Vector2f pos, float angle);
    ~Laser();

    // Drawable interface
protected:
    void draw(RenderTarget &target, RenderStates states) const override;

    // GameObject interface
public:
    void logic() override;

    // DamageObject interface
public:
    float getDamage() override {return DAMAGE * Globals::gameTime;}
    FloatRect getGlobalBounds() override {return sprite->getGlobalBounds();}
    Vector2f getPosition() override {sprite->getPosition();}

    // DamageObject interface
protected:
    bool checkIntersection(DamageObject *dObj);
};

#endif // LIGHT_H
