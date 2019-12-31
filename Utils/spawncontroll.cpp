#include "spawncontroll.h"

SpawnControll::SpawnControll()
{
    srand(time(NULL));
}

Vector2f SpawnControll::generateSpawnPos()
{
    int side = rand() % 4;
    if (side == 0) return Vector2f(Enemy::playerPos.x + Globals::mainWindow->getSize().x/2 + 50, rand() % Globals::mainWindow->getSize().y);
    if (side == 1) return Vector2f(Enemy::playerPos.x - Globals::mainWindow->getSize().x/2 - 50, rand() % Globals::mainWindow->getSize().y);
    if (side == 2) return Vector2f(rand() % Globals::mainWindow->getSize().x, Enemy::playerPos.y + Globals::mainWindow->getSize().y/2 + 50);
    if (side == 3) return Vector2f(rand() % Globals::mainWindow->getSize().x, Enemy::playerPos.y - Globals::mainWindow->getSize().y/2 - 50);
}


