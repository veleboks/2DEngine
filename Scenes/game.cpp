#include "game.h"

Game::Game()
{
    sceneTime = 0;
    spawner = new SpawnControll();
    player = new Player(Vector2f(100, 100));
    addObject(player);
    addEnemy(new Enemy(Vector2f(100, 100)));
    prevSpawnTime = 0;
}

void Game::addEnemy(Enemy *e)
{
    enemies.push_back(e);
    addObject(e);
}

void Game::sceneLogic()
{
    sceneTime += Globals::gameTime/1000;
    Enemy::playerPos = player->getCenter();
    if (sceneTime - prevSpawnTime > spawnDelay) {
        addEnemy(new Enemy(spawner->generateSpawnPos()));
        prevSpawnTime = sceneTime;
    }
}

