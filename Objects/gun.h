#ifndef GUN_H
#define GUN_H

#include "globals.h"
#include "enemy.h"

class Gun : public DamageObject
{
    // Drawable interface
protected:
    RectangleShape * sprite;
    virtual void draw(RenderTarget &target, RenderStates states) const override = 0;
    virtual void onClick() = 0;
    // GameObject interface
public:
    void logic() override;

    // DamageObject interface
public:
    virtual FloatRect getGlobalBounds() override = 0;
    virtual float getDamage() override = 0;
    Vector2f getPosition() override {sprite->getPosition();}
protected:
    virtual bool checkIntersection(DamageObject *dObj) override = 0;
};

#endif // GUN_H