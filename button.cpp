#include "button.h"

Button::Button(String name, Vector2f pos, Vector2f size, int text_size, Color text_color, Color background)
{
    sprite.setSize(size);
    sprite.setPosition(pos);
//    this->background = background;
    sprite.setFillColor(background);
    sprite.setOutlineColor(Color::Black);

    font = Helper::getFont(); // обязательно!!!

    text.setPosition(sprite.getPosition());


    Vector2f indent((sprite.getSize().x - text.getGlobalBounds().width)/2, (sprite.getSize().y - text.getGlobalBounds().height)/2);

    text.setString(name);
    text.setCharacterSize(text_size);
    text.setPosition(sprite.getPosition() + indent);
    text.setFont(font); // при уничтожении шрифта баг
    text.setFillColor(text_color);

}

void Button::draw(RenderTarget &target, RenderStates states) const
{
    target.draw(sprite, states);
    target.draw(text, states);
}

ButtonState Button::isClicked(RenderWindow *w)
{
    if (sprite.getGlobalBounds().contains(Mouse::getPosition(*w).x, Mouse::getPosition(*w).y)) {
        if (Mouse::isButtonPressed(Mouse::Left))
            return ButtonState::PRESS;
        return ButtonState::CURSOR_ON;
    }
    return ButtonState::NONE;
}

void Button::logic(RenderWindow *w)
{
    sprite.setOutlineThickness(0);
    if (isClicked(w) == ButtonState::CURSOR_ON)
        sprite.setFillColor(Color(sprite.getFillColor().r, sprite.getFillColor().g, sprite.getFillColor().b, 150));
    else if (isClicked(w) == ButtonState::PRESS)
        sprite.setOutlineThickness(-2);
    else
        sprite.setFillColor(Color(sprite.getFillColor().r, sprite.getFillColor().g, sprite.getFillColor().b, 255));
}
