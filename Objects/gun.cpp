#include "gun.h"

void Gun::logic()
{
    float mouseY = Mouse::getPosition(*Globals::mainWindow).y - getPosition().y;
    float mouseX = Mouse::getPosition(*Globals::mainWindow).x - getPosition().x;
    float angle = atan(mouseY/mouseX) * 180 / 3.14;
    if (mouseX < 0) angle += 180;
    sprite->setPosition(Enemy::playerPos);
    sprite->rotate(angle - getRotation());
    for (auto it : damagedObjs) it->logic();
//    angle = (Mouse::getPosition().x - sprite->getPosition().x)
    if (Mouse::isButtonPressed(Mouse::Left)) onClick();
}
