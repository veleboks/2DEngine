#ifndef LASERGUN_H
#define LASERGUN_H

#include "gun.h"
#include "laser.h"

class LaserGun : public Gun
{
public:
    LaserGun(Vector2f pos);

    // Drawable interface
protected:
    void draw(RenderTarget &target, RenderStates states) const override;

    // DamageObject interface
public:
    FloatRect getGlobalBounds() override {return sprite->getGlobalBounds();}

    // Gun interface
protected:
    void onClick() override;

    // DamageObject interface
public:
    float getDamage() override {return 0;}

protected:
    bool checkIntersection(DamageObject *dObj) override {return false;}
};

#endif // LASERGUN_H
