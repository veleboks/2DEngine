#ifndef PLAYERHPCOUNTER_H
#define PLAYERHPCOUNTER_H

#include "hpcounter.h"
#include "globals.h"

class PlayerHPCounter : public HPCounter
{
public:
    PlayerHPCounter(Vector2f pos, Vector2f size, Unit * unit, float maxHP = 100.0);

    // HPCounter interface
private:
    Vector2f pos;
    void posUpdate() override;
};

#endif // PLAYERHPCOUNTER_H
