#include "engine.h"

//Engine::Engine(String nameWindow, unsigned int width, unsigned int height, bool defaultStart)
Engine::Engine(RenderWindow *window, bool defaultStart)
{
//    window = new RenderWindow(VideoMode(width,height),nameWindow);

    this->window = window;

    this->initObjects();

    if(defaultStart)
        start();
}

Engine::~Engine()
{
    for(auto it : objects) {
        delete it;
    }
}

void Engine::addObject(GameObject *object)
{
    objects.push_back(object);
}

void Engine::addObject(vector<GameObject*> obj)
{
    objects.insert(objects.end(), obj.begin(), obj.end());
}

void Engine::start()
{
    while(window->isOpen()){

        processingEvents();

        logic();
        render();
    }
}

void Engine::processingEvents()
{
    while(window->pollEvent(event))
    {
        if(event.type == Event::Closed)
            window->close();
    }
}

void Engine::logic()
{
    for(auto it: objects) it->logic(window);
}

void Engine::render()
{
    window->clear(Color::White);

    for(auto it: objects) window->draw(*it);

    window->display();
}

void Engine::initObjects()
{
    addObject(new Button("name", Vector2f(100, 100), Vector2f(200, 40)));
}
