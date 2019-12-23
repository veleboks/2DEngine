#ifndef LIGHT_H
#define LIGHT_H

#include "damageobject.h"
#include "enemy.h"
#include "globals.h"

class Light : public DamageObject
{
private:
    RectangleShape * sprite;
public:
    Light(Vector2f pos, float angle);
    ~Light();

    // Drawable interface
protected:
    void draw(RenderTarget &target, RenderStates states) const override;

    // GameObject interface
public:
    void logic() override;

    // DamageObject interface
public:
    FloatRect getGlobalBounds() override;
};

#endif // LIGHT_H
