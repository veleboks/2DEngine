#include "menu.h"

Menu::Menu() {
    for (int i = 1; i <= 3; ++i)
        addObject(new Button(BUTTONS_NAMES[i-1], Vector2f(Globals::mainWindow->getSize().x/2-100, Globals::mainWindow->getSize().y/4*i), Vector2f(200, 50), 30, Color::White));
}
