#ifndef SPAWNCONTROLL_H
#define SPAWNCONTROLL_H

#include "vector"
#include "Objects/enemy.h"

using namespace std;
using namespace sf;

class SpawnControll
{
private:
    float pK;
    vector<Vector2f> spawnPoints;
public:
    void generateSpawnPos(vector<Enemy*> * enemies);
};

#endif // SPAWNCONTROLL_H
