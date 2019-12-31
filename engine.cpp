#include "engine.h"

Engine::Engine(String nameWindow, unsigned int width, unsigned int height, bool defaultStart)
{
    window = new RenderWindow(VideoMode(width,height),nameWindow);
    view = new View();
    view->setSize(window->getSize().x, window->getSize().y);
    Globals::mainWindow = window;
    Globals::mainView = view;
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

void Engine::smoothViewMove()
{
    Vector2f viewMoving = view->getCenter();
    if (abs(Enemy::playerPos.x - viewMoving.x) < maxLen) {
        if (Enemy::playerPos.x > viewMoving.x)
            viewMoving = Vector2f(viewMoving.x + beginViewSpeed, viewMoving.y);
        if (Enemy::playerPos.x < viewMoving.x)
            viewMoving = Vector2f(viewMoving.x - beginViewSpeed, viewMoving.y);
    } else {
        if (Enemy::playerPos.x > viewMoving.x)
            viewMoving = Vector2f(viewMoving.x + finalViewSpeed, viewMoving.y);
        if (Enemy::playerPos.x < viewMoving.x)
            viewMoving = Vector2f(viewMoving.x - finalViewSpeed, viewMoving.y);
    }
    if (abs(Enemy::playerPos.y - viewMoving.y) < maxLen) {
        if (Enemy::playerPos.y > viewMoving.y)
            viewMoving = Vector2f(viewMoving.x, viewMoving.y + beginViewSpeed);
        if (Enemy::playerPos.y < viewMoving.y)
            viewMoving = Vector2f(viewMoving.x, viewMoving.y - beginViewSpeed);
    } else {
        if (Enemy::playerPos.y > viewMoving.y)
            viewMoving = Vector2f(viewMoving.x, viewMoving.y + finalViewSpeed);
        if (Enemy::playerPos.y < viewMoving.y)
            viewMoving = Vector2f(viewMoving.x, viewMoving.y - finalViewSpeed);
    }
    view->setCenter(viewMoving);
}

void Engine::update() {
    float time = clock.getElapsedTime().asMicroseconds();
    clock.restart();
    Globals::gameTime = time / 1000;
    for(auto it: scenes) it->logic();

    window->clear(Color::White);


    for(auto it: scenes) it->render();

    smoothViewMove();

    window->setView(*view);

    window->display();
}

void Engine::initObjects()
{
    addObject(new Game);
}
