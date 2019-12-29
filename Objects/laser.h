#ifndef LIGHT_H
#define LIGHT_H

#include "gun.h"
#include "enemy.h"
#include "globals.h"
#include "cmath"
#include <float.h>

class Laser : public DamageObject
{
private:
    RectangleShape * sprite;
public:
    Laser(Vector2f pos, float angle, DamageObject * prev);
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

    // DamageObject interface
public:
    float getRotation() override {return sprite->getRotation();}
};

#endif // LIGHT_H
