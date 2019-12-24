#include "game.h"

void Game::spawnEnemy()
{
    if (sceneTime - prevSpawnTime > spawnDelay) {
        addEnemy(new Enemy(spawner->generateSpawnPos()));
        prevSpawnTime = sceneTime;
    }
}

Game::Game()
{
    sceneTime = 0;
    spawner = new SpawnControll();
    player = new Player(Vector2f(100, 100));
    addObject(player);
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
    spawnEnemy();
    clearObjects();
    addObject(player);
    for (auto it = enemies.begin(); it != enemies.end();) {
        float damage = player->getGlobalDamage(*it);
        (*it)->damage(damage);
        if ((*it)->getHP() <= 0) enemies.erase(it);
        else {
            addObject(*it);
            ++it;
        }
    }
}

