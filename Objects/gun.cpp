#include "gun.h"

void Gun::logic()
{
    //    float mouseY = Mouse::getPosition(*Globals::mainWindow).y - getPosition().y;
    //    float mouseX = Mouse::getPosition(*Globals::mainWindow).x - getPosition().x;
    //    float mouseY = Mouse::getPosition(*Globals::mainWindow).y - Globals::mainWindow->getSize().y/2.0;
    //    float mouseX = Mouse::getPosition(*Globals::mainWindow).x - Globals::mainWindow->getSize().x/2.0;

    float mouseY = Mouse::getPosition(*Globals::mainWindow).y - getPosition().y + Globals::mainWindow->getView().getCenter().y - Globals::mainWindow->getView().getSize().y/2.0;
    float mouseX = Mouse::getPosition(*Globals::mainWindow).x - getPosition().x + Globals::mainWindow->getView().getCenter().x - Globals::mainWindow->getView().getSize().x/2.0;

    float angle = atan(mouseY/mouseX) * 180 / 3.14;
    if (mouseX < 0) angle += 180;
    sprite->setPosition(Enemy::playerPos);
    sprite->rotate(angle - getRotation());
    for (auto it : damagedObjs) it->logic();
    //    angle = (Mouse::getPosition().x - sprite->getPosition().x)

    /// Марат красавчик
    if (Mouse::isButtonPressed(Mouse::Left) && !mouseStateFlag) {
        onClick();
        mouseStateFlag = true;
    }
    if (!Mouse::isButtonPressed(Mouse::Left) && mouseStateFlag) {
        onRelease();
        mouseStateFlag = false;
    }

}
