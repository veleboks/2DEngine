#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include <SFML/Graphics.hpp>
#include "gameobject.h"
#include "globals.h"

using namespace std;
using namespace sf;

class Scene
{
public:

    void clearObjects();
    void addObject(GameObject* object);
    void addObject(vector<GameObject*> obj);
    void logic();
    void render();

private:
    bool available = false;
    vector<GameObject*> objects;
protected:
    virtual void renderUI(){}
    virtual void sceneLogic() = 0;
};

#endif // SCENE_H
