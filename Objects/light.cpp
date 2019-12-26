#include "light.h"

Light::Light(Vector2f pos, float angle)
{
    DAMAGE = 50.0;
    sprite = new RectangleShape();
    sprite->setSize(Vector2f(1000, 5));
    sprite->setOrigin(0, 3);
    sprite->setFillColor(Color(0, 255, 0, 100));
    sprite->setPosition(pos);
    sprite->rotate(angle);
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

bool Light::checkIntersection(DamageObject *dObj)
{
    float rayAngleTan = tan(sprite->getRotation() * 3.14 / 180.0);
    float rayAngleCos = cos(sprite->getRotation() * 3.14 / 180.0);
    float rayAngleSin = sin(sprite->getRotation() * 3.14 / 180.0);

    FloatRect dRect = dObj->getGlobalBounds();

    float angle = fmod(sprite->getRotation(), 360.0);

    float y1 = rayAngleTan * (dRect.left - sprite->getPosition().x) - dRect.top + sprite->getPosition().y;
    float y2 = rayAngleTan * (dRect.left + dRect.width - sprite->getPosition().x) - dRect.top + sprite->getPosition().y;

    float x1 = (dRect.top - sprite->getPosition().y) / rayAngleTan - dRect.left + sprite->getPosition().x;
    float x2 = (dRect.top + dRect.height - sprite->getPosition().y) / rayAngleTan - dRect.left + sprite->getPosition().x;



    if ((y1 > 0 && y1 < dRect.height) || (y2 > 0 && y2 < dRect.height)) return true;
    if ((x1 > 0 && x1 < dRect.width) || (x2 > 0 && x2 < dRect.width)) return true;

    return false;
}

