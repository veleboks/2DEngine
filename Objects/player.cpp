#include "player.h"

Player::Player(Vector2f pos, float speed)
{
    cout << "Trying to load tileset" << endl;
    if(!img.loadFromFile("C:/Programming/qt_projects/2DEngine/Resources/Images/Knight_tileset.png")) {
        cout << "can't load tileset" << endl;
    } else cout << "load tileset" << endl;
    texture.loadFromImage(img);
    sprite.setTexture(texture);
    sprite.setTextureRect(IntRect(0, 0, 14, 16));
    sprite.scale(3, 3);
    sprite.setPosition(pos);
    SPEED = speed;
    addDamagedObj(new LaserGun(getCenter()));
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
    if (Mouse::getPosition(*Globals::mainWindow).x + Globals::mainWindow->getView().getCenter().x - Globals::mainWindow->getView().getSize().x/2 > getCenter().x) dir = eDir::RIGHT;
    else dir = eDir::LEFT;
    bool isMove = Keyboard::isKeyPressed(Keyboard::W)
            || Keyboard::isKeyPressed(Keyboard::S)
            || Keyboard::isKeyPressed(Keyboard::A)
            || Keyboard::isKeyPressed(Keyboard::D);
    if (Keyboard::isKeyPressed(Keyboard::W)) sprite.move(0, -speed);
    if (Keyboard::isKeyPressed(Keyboard::S)) sprite.move(0, speed);
    if (Keyboard::isKeyPressed(Keyboard::A)) sprite.move(-speed, 0);
    if (Keyboard::isKeyPressed(Keyboard::D)) sprite.move(speed, 0);
    if (isMove) {
        aNTime += Globals::gameTime;
        if (aNTime - prevAnTime > 80) {
            textNum = (textNum+1)%4;
            prevAnTime = aNTime;
            if (dir == eDir::RIGHT) {
                if (textNum == 0 || textNum == 3) sprite.move(-3, 0);
                if (textNum == 1 || textNum == 2) sprite.move(3, 0);
            }
        }
        if (dir == eDir::LEFT) {
            sprite.setTextureRect(animation[1][textNum]);
        } else {
            sprite.setTextureRect(animation[0][textNum]);
        }
    } else {
        if (dir == eDir::LEFT) {
            sprite.setTextureRect(stand[1]);
        } else {
            sprite.setTextureRect(stand[0]);
        }
        aNTime = 0;
        prevAnTime = 0;
        textNum = 0;
    }
}

Vector2f Player::getCenter()
{
    return Vector2f(sprite.getPosition().x + sprite.getTexture()->getSize().x/2, sprite.getPosition().y + sprite.getTexture()->getSize().y/2);
}

FloatRect Player::getGlobalBounds()
{
    return sprite.getGlobalBounds();
}
