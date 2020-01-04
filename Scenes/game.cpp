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
    smoothViewMove();
}

void Game::smoothViewMove()
{
    Vector2f viewMoving = Globals::mainWindow->getView().getCenter();
    if (abs(Enemy::playerPos.x - viewMoving.x) < maxLen) {
        if (Enemy::playerPos.x > viewMoving.x)
            viewMoving = Vector2f(viewMoving.x + beginViewSpeed, viewMoving.y);
        if (Enemy::playerPos.x < viewMoving.x)
            viewMoving = Vector2f(viewMoving.x - beginViewSpeed, viewMoving.y);
    } else {
        if (Enemy::playerPos.x > viewMoving.x)
            viewMoving = Vector2f(viewMoving.x + finalViewSpeed, viewMoving.y);
        if (Enemy::playerPos.x < viewMoving.x)
            viewMoving = Vector2f(viewMoving.x - finalViewSpeed, viewMoving.y);
    }
    if (abs(Enemy::playerPos.y - viewMoving.y) < maxLen) {
        if (Enemy::playerPos.y > viewMoving.y)
            viewMoving = Vector2f(viewMoving.x, viewMoving.y + beginViewSpeed);
        if (Enemy::playerPos.y < viewMoving.y)
            viewMoving = Vector2f(viewMoving.x, viewMoving.y - beginViewSpeed);
    } else {
        if (Enemy::playerPos.y > viewMoving.y)
            viewMoving = Vector2f(viewMoving.x, viewMoving.y + finalViewSpeed);
        if (Enemy::playerPos.y < viewMoving.y)
            viewMoving = Vector2f(viewMoving.x, viewMoving.y - finalViewSpeed);
    }
    Globals::mainWindow->setView(View(viewMoving, Vector2f(Globals::mainWindow->getSize())));
}

