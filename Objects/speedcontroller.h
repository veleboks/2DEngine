#ifndef SPEEDCONTROLLER_H
#define SPEEDCONTROLLER_H

#include "damageobject.h"

class SpeedController: public DamageObject
{
private:
    Sprite sprite;
    Text key;
public:
    SpeedController();
};

#endif // SPEEDCONTROLLER_H
