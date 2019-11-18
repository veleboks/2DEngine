#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <SFML/Graphics.hpp>

using namespace sf;

class GameObject : public Drawable
{
public:
    virtual void logic(RenderWindow *w) = 0;
protected:
    virtual void draw(RenderTarget &target, RenderStates states) const = 0;
};

#endif // GAMEOBJECT_H
