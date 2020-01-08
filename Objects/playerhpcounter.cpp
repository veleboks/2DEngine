#include "playerhpcounter.h"

PlayerHPCounter::PlayerHPCounter(Vector2f pos, Vector2f size, Unit *unit, float maxHP) : HPCounter(pos, size, unit, maxHP) {
    this->pos = pos;
}

void PlayerHPCounter::posUpdate()
{
    Vector2f viewPos = Vector2f(Globals::mainWindow->getView().getCenter().x - Globals::mainWindow->getView().getSize().x,
                                Globals::mainWindow->getView().getCenter().y - Globals::mainWindow->getView().getSize().y);
    background->setPosition(Vector2f(viewPos.x + pos.x, viewPos.y + pos.y));
    hpRect->setPosition(viewPos.x + pos.x + abs(background->getOutlineThickness()),
                        viewPos.y + pos.y + abs(background->getOutlineThickness()));
}

