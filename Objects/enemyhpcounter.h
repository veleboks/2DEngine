#ifndef ENEMYHPCOUNTER_H
#define ENEMYHPCOUNTER_H

#include "hpcounter.h"

class EnemyHPCounter : public HPCounter
{
public:
    EnemyHPCounter(Vector2f pos, Vector2f size, Unit * unit1, float maxHP1 = 100.0);
    // HPCounter interface
private:
    void posUpdate() override;
};

#endif // ENEMYHPCOUNTER_H
