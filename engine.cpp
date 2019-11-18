#include "engine.h"

Engine::Engine(String nameWindow, unsigned int width, unsigned int height, bool defaultStart)
{
    window = new RenderWindow(VideoMode(width,height),nameWindow);

    Globals::mainWindow = window;

    this->initObjects();

    if(defaultStart)
        start();
}

Engine::~Engine()
{
    for(auto it : scenes) {
        delete it;
    }
}

void Engine::addObject(Scene *scene)
{
    scenes.push_back(scene);
}

void Engine::addObject(vector<Scene*> scenes)
{
    this->scenes.insert(this->scenes.end(), scenes.begin(), scenes.end());
}

void Engine::start()
{
    while(window->isOpen()){

        processingEvents();

        update();
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

void Engine::update() {

    for(auto it: scenes) it->logic();

    window->clear(Color::White);

    for(auto it: scenes) it->render();

    window->display();
}

void Engine::initObjects()
{
//    addObject(new Button("name", Vector2f(100, 100), Vector2f(200, 40)));
}