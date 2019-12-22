#ifndef SPAWNCONTROLL_H
#define SPAWNCONTROLL_H

#include <SFML/Graphics.hpp>
#include <ctime>
#include <cstdlib>
#include "globals.h"

using namespace std;
using namespace sf;

class SpawnControll
{
public:
    SpawnControll();
    Vector2f generateSpawnPos();
};

#endif // SPAWNCONTROLL_H
