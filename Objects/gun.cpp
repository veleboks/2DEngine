#include "gun.h"

void Gun::logic()
{
    float angle;
    sprite->setPosition(Enemy::playerPos);
    sprite->rotate(0.05 * Globals::gameTime);
    for (auto it : damagedObjs) it->logic();
//    angle = (Mouse::getPosition().x - sprite->getPosition().x)
    if (Mouse::isButtonPressed(Mouse::Left)) onClick();
}
