#ifndef GLOBALS_H
#define GLOBALS_H

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

class Globals
{
public:
    static RenderWindow *mainWindow;
    static Font getFont(String nameFont = "Resources/Fonts/main.ttf");
};

#endif // GLOBALS_H
