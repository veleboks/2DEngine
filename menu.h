#ifndef MENU_H
#define MENU_H

#include "engine.h"

enum class MenuButtons {Play, Settings};

class Menu : public Engine
{
public:
    Menu(RenderWindow *window);
};

#endif // MENU_H
