#ifndef HELPER_H
#define HELPER_H

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

class Helper
{
public:
    static Font getFont(String nameFont = "Resources/Fonts/main.ttf");
};

#endif // HELPER_H
