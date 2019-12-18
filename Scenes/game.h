#ifndef GAME_H
#define GAME_H

#include "scene.h"
#include "Objects/player.h"
#include "Objects/enemy.h"

class Game : public Scene
{
private:
    vector<Enemy*> enemies;
    Player * player;
public:
    Game();
    void addEnemy(Enemy* e);

//     Scene interface
protected:
    void sceneLogic() override;
};

#endif // GAME_H
