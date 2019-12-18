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
    void addObject(GameObject* object);
    void addObject(vector<GameObject*> obj);
    void logic();
    void render();
private:
    vector<GameObject*> objects;
protected:
    virtual void sceneLogic() = 0;
};

#endif // SCENE_H
