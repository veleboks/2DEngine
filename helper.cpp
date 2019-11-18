#include "helper.h"

Font Helper::getFont(String nameFont)
{
    Font font;
    if(!font.loadFromFile(nameFont))
        cout << "Not load font" << endl;
    else
        cout << "load font" << endl;
    return font;
}
