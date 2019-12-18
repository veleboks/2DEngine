#include "globals.h"

float Globals::gameTime = 0;
RenderWindow *Globals::mainWindow = new RenderWindow();

Font Globals::getFont(String nameFont)
{
    Font font;
    if(!font.loadFromFile(nameFont))
        cout << "Not load font" << endl;
    else
        cout << "load font" << endl;
    return font;
}
