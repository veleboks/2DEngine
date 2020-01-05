#ifndef ENGINE_H
#define ENGINE_H

#include <SFML/Graphics.hpp>
//#include <vector>
#include <iostream>
//#include "gameobject.h"
#include "Objects/button.h"
#include "globals.h"
#include "scene.h"
#include "Scenes/game.h"
#include "Objects/enemy.h"

using namespace sf;
using namespace std;

class Engine
{
public:
    Engine(String nameWindow, unsigned int width = 1080, unsigned int height = 1080, bool defaultStart = true);
    ~Engine();
    ///Запуск
    virtual void start();
    void addObject(Scene* object);
    void addObject(vector<Scene*> obj);
private:
    Clock clock;
    vector<Scene*> scenes; // сцены для отрисовки
    ///Обработка событий
    void processingEvents();
    ///Окно
    RenderWindow * window;
    Event event;
    void update();
protected:
    void initObjects();
};

#endif // ENGINE_H
