#include "player.h"

Player::Player(Vector2f pos, float speed)
{
    sprite.setPosition(pos);
    sprite.setSize(Vector2f(40, 40));
    sprite.setFillColor(Color::Blue);
    SPEED = speed;
    addDamagedObj(new Light(pos, 270));
//    addDamagedObj(new Light(pos, 90));
//    addDamagedObj(new Light(pos, 180));
//    addDamagedObj(new Light(pos, 270));
}

void Player::draw(RenderTarget &target, RenderStates states) const
{
    target.draw(sprite, states);
    for (auto it : damagedObjs) target.draw(*it, states);
}

void Player::logic()
{
    for (auto it : damagedObjs) it->logic();
    float speed = SPEED * Globals::gameTime;
    if (Keyboard::isKeyPressed(Keyboard::W)) sprite.move(0, -speed);
    if (Keyboard::isKeyPressed(Keyboard::S)) sprite.move(0, speed);
    if (Keyboard::isKeyPressed(Keyboard::A)) sprite.move(-speed, 0);
    if (Keyboard::isKeyPressed(Keyboard::D)) sprite.move(speed, 0);
}

Vector2f Player::getCenter()
{
    return Vector2f(sprite.getPosition().x + sprite.getSize().x/2, sprite.getPosition().y + sprite.getSize().y/2);
}

FloatRect Player::getGlobalBounds()
{
    return sprite.getGlobalBounds();
}
