#ifndef PLAYER_H
#define PLAYER_H

#include "unit.h"
#include "globals.h"

class Player : public Unit
{
private:
    RectangleShape sprite;
    // Drawable interface
protected:
    void draw(RenderTarget &target, RenderStates states) const override;

    // GameObject interface
public:
    Player(Vector2f pos, float speed = 0.5);
    void logic() override;
    Vector2f getCenter();
};

#endif // PLAYER_H
