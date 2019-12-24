#include "light.h"

Light::Light(Vector2f pos, float angle)
{
    DAMAGE = 50.0;
    sprite = new RectangleShape();
    sprite->setPosition(pos);
    sprite->setSize(Vector2f(1000, 5));
    sprite->rotate(angle);
    sprite->setFillColor(Color(0, 255, 0, 100));
}

Light::~Light()
{
    delete sprite;
}

void Light::draw(RenderTarget &target, RenderStates states) const
{
    target.draw(*sprite, states);
}

void Light::logic()
{
    sprite->setPosition(Enemy::playerPos);
    sprite->rotate(0.05 * Globals::gameTime);
}

