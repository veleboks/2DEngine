#include "lasergun.h"

LaserGun::LaserGun(Vector2f pos)
{
    sprite = new RectangleShape();
    sprite->setSize(Vector2f(5, 5));
    sprite->setPosition(pos);
}

void LaserGun::draw(RenderTarget &target, RenderStates states) const
{
    target.draw(*sprite, states);
    for (auto it : damagedObjs) target.draw(*it, states);
}

void LaserGun::onClick()
{
    if (damagedObjs.empty()) {
        damagedObjs.push_back(new Laser(getPosition(), getRotation(), this));
    }
}
