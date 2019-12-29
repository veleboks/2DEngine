    #ifndef PLAYER_H
#define PLAYER_H

#include "unit.h"
#include "globals.h"
#include "lasergun.h"

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

    // DamageObject interface
public:
    FloatRect getGlobalBounds() override;
    Vector2f getPosition() override {return sprite.getPosition();}

    // DamageObject interface
public:
    float getRotation() override {return sprite.getRotation();}
};

#endif // PLAYER_H
