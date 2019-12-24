#include "damageobject.h"

float DamageObject::getDamage()
{
    return DAMAGE;
}

void DamageObject::setDamage(float value)
{
    DAMAGE = value;
}

float DamageObject::getGlobalDamage(DamageObject *d)
{
    float damage = 0;
    if (checkIntersection(d)) damage += getDamage();
    for (auto it : damagedObjs)
        damage += it->getGlobalDamage(d);
    return damage;
}
