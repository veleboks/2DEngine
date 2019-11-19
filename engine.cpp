#include "engine.h"

Engine::Engine(String nameWindow, unsigned int width, unsigned int height, bool defaultStart)
{
    window = new RenderWindow(VideoMode(width,height),nameWindow);

    Globals::mainWindow = window;

    this->initScenes();

    if(defaultStart)
        start();
}

Engine::~Engine()
{
    for(auto it : scenes) {
        delete it;
    }
}

void Engine::addScene(Scene *scene)
{
    scenes.push_back(scene);
}

void Engine::addScene(vector<Scene*> scenes)
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

void Engine::initScenes()
{
    addScene(new Menu());
}
