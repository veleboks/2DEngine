#ifndef HPCOUNTER_H
#define HPCOUNTER_H

#include "gameobject.h"
#include "unit.h"

class HPCounter : public GameObject
{
private:
    virtual void posUpdate(){}
public:
    HPCounter(Vector2f pos, Vector2f size, Unit * unit, float maxHP = 100.0);
    ~HPCounter();
    // Drawable interface
protected:
    Unit * unit;
    RectangleShape * hpRect;
    RectangleShape * background;
    float maxHP;
    void draw(RenderTarget &target, RenderStates states) const override;

    // GameObject interface
public:
    void logic() override;
};

#endif // HPCOUNTER_H
