#include "player.h"

Player::Player(Vector2f pos, float speed)
{
    sprite.setPosition(pos);
    sprite.setSize(Vector2f(40, 40));
    sprite.setFillColor(Color::Blue);
    SPEED = speed;
}

void Player::draw(RenderTarget &target, RenderStates states) const
{
    target.draw(sprite, states);
}

void Player::logic()
{
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
