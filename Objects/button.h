#ifndef BUTTON_H
#define BUTTON_H

#include "gameobject.h"
#include "globals.h"

enum class ButtonState {NONE, PRESS, CURSOR_ON};

class Button : public GameObject{
private:
    RectangleShape sprite;
    Color background;
    Text text;
    Font font;
public:
    Button(String name, Vector2f pos, Vector2f size, int text_size = 30, Color text_color = Color::Black, Color background = Color::Blue);
    // Drawable interface
    virtual void logic() override;
    ButtonState isClicked(RenderWindow *w);
protected:
    void draw(RenderTarget &target, RenderStates states) const override;
    // GameObject interface
};

#endif // BUTTON_H
