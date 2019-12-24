#include "scene.h"

void Scene::clearObjects()
{
    objects.clear();
}

void Scene::addObject(GameObject *object)
{
    objects.push_back(object);
}

void Scene::addObject(vector<GameObject*> objects)
{
    this->objects.insert(this->objects.end(), objects.begin(), objects.end());
}

void Scene::logic()
{
    sceneLogic();
    for(auto it: objects) it->logic();
}

void Scene::render()
{
    for(auto it: objects) Globals::mainWindow->draw(*it);
}

