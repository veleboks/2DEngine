#include "spawncontroll.h"

SpawnControll::SpawnControll()
{
    srand(time(NULL));
}

Vector2f SpawnControll::generateSpawnPos()
{
    int side = rand() % 4;
    if (side == 0) return Vector2f(Globals::mainWindow->getSize().x + 50, rand() % Globals::mainWindow->getSize().y);
    if (side == 1) return Vector2f(-50, rand() % Globals::mainWindow->getSize().y);
    if (side == 2) return Vector2f(rand() % Globals::mainWindow->getSize().x, Globals::mainWindow->getSize().y + 50);
    if (side == 3) return Vector2f(rand() % Globals::mainWindow->getSize().x, -50);
}


