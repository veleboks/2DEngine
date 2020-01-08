#include "hpcounter.h"

HPCounter::HPCounter(Vector2f pos, Vector2f size, Unit * unit, float maxHP)
{
    background = new RectangleShape();
    background->setSize(size);
    background->setPosition(pos);
    background->setFillColor(Color(150, 150, 150));
    background->setOutlineThickness(-3);
    background->setOutlineColor(Color::Black);
    this->maxHP = maxHP;
    hpRect = new RectangleShape();
    hpRect->setSize(Vector2f(size.x - 6, size.y - 6));
    hpRect->setPosition(pos.x + 3, pos.y + 3);
    hpRect->setFillColor(Color::Red);
    this->unit = unit;
    logic();
}

HPCounter::~HPCounter()
{
    delete hpRect;
    delete background;
}

void HPCounter::draw(RenderTarget &target, RenderStates states) const
{
    target.draw(*background, states);
    target.draw(*hpRect, states);
}

void HPCounter::logic()
{
    posUpdate();
    hpRect->setSize(Vector2f((background->getSize().x-10) * unit->getHP() / maxHP, hpRect->getSize().y));
}
