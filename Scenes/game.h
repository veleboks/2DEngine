#ifndef GAME_H
#define GAME_H

#include "scene.h"
#include "Objects/player.h"
#include "Objects/enemy.h"
#include "Utils/spawncontroll.h"

class Game : public Scene
{
private:
    float spawnDelay = 1; // in seconds
    float sceneTime; // in seconds
    float prevSpawnTime;
    vector<Enemy *> enemies;
    SpawnControll *spawner;
    Player *player;
public:
    Game();
    void addEnemy(Enemy *e);

//     Scene interface
protected:
    void sceneLogic() override;
};

#endif // GAME_H
