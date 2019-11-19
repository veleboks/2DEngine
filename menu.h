#ifndef MENU_H
#define MENU_H

#include "scene.h"
#include "button.h"

class Menu : public Scene
{
private:
    const String BUTTONS_NAMES[3] = {"Play", "Records", "Settings"};
public:
    Menu();
};

#endif // MENU_H
