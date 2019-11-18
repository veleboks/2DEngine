#include <engine.h>

int main()
{
    RenderWindow *window = new RenderWindow(VideoMode(800, 600), "SFML");
    Engine e(window, true);
}
