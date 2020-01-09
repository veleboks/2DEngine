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
    hud = new HUD(player);
    addObject(player);
    prevSpawnTime = 0;
}

void Game::addEnemy(Enemy *e)
{
    hud->addEnemyHealthBar(e);
    enemies.push_back(e);
    addObject(e);
}

void Game::renderUI()
{
    hud->render();
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
        if ((*it)->getHP() <= 0){
            delete *it;
            enemies.erase(it);
        } else {
            addObject(*it);
            ++it;
        }
    }
    smoothViewMove();
    hud->logic();
}

void Game::smoothViewMove()
{
    static Vector2f prevMouseMove;

    Vector2f viewMoving = Vector2f(Globals::mainWindow->getView().getCenter().x - prevMouseMove.x,
                                   Globals::mainWindow->getView().getCenter().y - prevMouseMove.y);

    float bs = beginViewSpeed * Globals::gameTime;
    float fs = finalViewSpeed * Globals::gameTime;

    if (abs(Enemy::playerPos.x - viewMoving.x) < maxLen) {
        if (Enemy::playerPos.x > viewMoving.x)
            viewMoving = Vector2f(viewMoving.x + bs, viewMoving.y);
        if (Enemy::playerPos.x < viewMoving.x)
            viewMoving = Vector2f(viewMoving.x - bs, viewMoving.y);
    } else {
        if (Enemy::playerPos.x > viewMoving.x)
            viewMoving = Vector2f(viewMoving.x + fs, viewMoving.y);
        if (Enemy::playerPos.x < viewMoving.x)
            viewMoving = Vector2f(viewMoving.x - fs, viewMoving.y);
    }
    if (abs(Enemy::playerPos.y - viewMoving.y) < maxLen) {
        if (Enemy::playerPos.y > viewMoving.y)
            viewMoving = Vector2f(viewMoving.x, viewMoving.y + bs);
        if (Enemy::playerPos.y < viewMoving.y)
            viewMoving = Vector2f(viewMoving.x, viewMoving.y - bs);
    } else {
        if (Enemy::playerPos.y > viewMoving.y)
            viewMoving = Vector2f(viewMoving.x, viewMoving.y + fs);
        if (Enemy::playerPos.y < viewMoving.y)
            viewMoving = Vector2f(viewMoving.x, viewMoving.y - fs);
    }

    prevMouseMove = Vector2f((Mouse::getPosition(*Globals::mainWindow).x - Globals::mainWindow->getSize().x/2.0)*0.2,
                             (Mouse::getPosition(*Globals::mainWindow).y - Globals::mainWindow->getSize().y/2.0)*0.2);

    viewMoving = Vector2f(viewMoving.x + prevMouseMove.x,
                          viewMoving.y + prevMouseMove.y);
    Globals::mainWindow->setView(View(viewMoving, Vector2f(Globals::mainWindow->getSize())));
}

