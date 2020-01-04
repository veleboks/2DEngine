#ifndef GAME_H
#define GAME_H

#include "scene.h"
#include "Objects/player.h"
#include "Objects/enemy.h"
#include "Utils/spawncontroll.h"
#include "Objects/laser.h"
#include "Objects/damageobject.h"

class Game : public Scene
{
private:
    const float beginViewSpeed = 0.15;
    const float finalViewSpeed = 0.5;
    const float maxLen = 30; // max len with center of a view and player
    float spawnDelay = 0.2; // in seconds
    float sceneTime; // in seconds
    float prevSpawnTime;
    vector<Enemy *> enemies;
    SpawnControll * spawner;
    Player * player;
    void spawnEnemy();
    void smoothViewMove();
public:
    Game();
    void addEnemy(Enemy *e);

//     Scene interface
protected:
    void sceneLogic() override;
};

#endif // GAME_H
