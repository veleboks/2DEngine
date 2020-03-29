#ifndef PLAYER_H
#define PLAYER_H

#include "unit.h"
#include "globals.h"
#include "lasergun.h"

enum class eDir {LEFT, RIGHT};

class Player : public Unit
{
private:
    eDir dir = eDir::LEFT;
    Sprite sprite;
    const IntRect animation[2][4] = {
        {IntRect(14, 0, 14, 16), IntRect(28, 0, 13, 16), IntRect(41, 0, 12, 16), IntRect(53, 0, 13, 16)},
        {IntRect(14, 16, 14, 16), IntRect(28, 16, 13, 16), IntRect(41, 16, 12, 16), IntRect(53, 16, 13, 16)}
    };
    const IntRect stand[2] = {IntRect(0, 0, 14, 16), IntRect(0, 16, 14, 16)};
    Image img;
    Texture texture;
    int textNum = 0;
    float playerTime = 0;
    float prevAnTime = 0;
    float aNTime = 0;
    // Drawable interface
//    void dash();

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
