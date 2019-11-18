#ifndef ENGINE_H
#define ENGINE_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "gameobject.h"
#include "button.h"
#include "helper.h"

using namespace sf;
using namespace std;

class Engine
{
public:
//    Engine(String nameWindow, unsigned int width = 800, unsigned int height = 600, bool defaultStart = true);
    Engine(RenderWindow *window, bool defaultStart = false);
    ~Engine();
    ///Запуск
    void start();
    void addObject(GameObject* object);
    void addObject(vector<GameObject*> obj);
private:
    vector<GameObject*> objects; // объекты для отрисовки
    ///Обработка событий
    void processingEvents();
    ///Окно
    RenderWindow *window;
    Event event;
    void logic();
    void render();
protected:
    void initObjects();
};

#endif // ENGINE_H
