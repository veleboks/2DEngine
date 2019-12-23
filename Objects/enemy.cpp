#include "enemy.h"

Vector2f Enemy::playerPos = Vector2f();

Enemy::Enemy(Vector2f pos, float speed)
{
    SPEED = speed;
    sprite.setPosition(pos);
    sprite.setSize(Vector2f(30, 30));
    sprite.setFillColor(Color::Red);
}

void Enemy::draw(RenderTarget &target, RenderStates states) const
{
    target.draw(sprite, states);
}

FloatRect Enemy::getGlobalBounds()
{
    return sprite.getGlobalBounds();
}

void Enemy::logic()
{
    float speed = SPEED * Globals::gameTime;

    if (sprite.getPosition().x + sprite.getSize().x/2 < playerPos.x) sprite.move(speed, 0);
    else sprite.move(-speed, 0);
    if (sprite.getPosition().y + sprite.getSize().y/2 < playerPos.y) sprite.move(0, speed);
    else sprite.move(0, -speed);

}
