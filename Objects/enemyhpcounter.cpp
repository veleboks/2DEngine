#include "enemyhpcounter.h"

EnemyHPCounter::EnemyHPCounter(Vector2f pos, Vector2f size, Unit * unit1, float maxHP1) : HPCounter(pos, size, unit1, maxHP1){}

void EnemyHPCounter::posUpdate()
{
    background->setPosition(Vector2f(unit->getPosition().x,
                                     unit->getPosition().y - background->getSize().y - 5.0));
    hpRect->setPosition(Vector2f(background->getPosition().x + abs(background->getOutlineThickness()),
                                 background->getPosition().y + abs(background->getOutlineThickness())));
}

