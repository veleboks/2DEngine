#include "unit.h"

float Unit::getHP()
{
    return HP;
}

void Unit::setHP(float value)
{
    HP = value;
}

void Unit::damage(float HP)
{
    this->HP -= HP;
}
