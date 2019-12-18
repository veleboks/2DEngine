#include "game.h"

Game::Game()
{
    player = new Player(Vector2f(100, 100));
    addObject(player);
    addEnemy(new Enemy(Vector2f(100, 100)));
}

void Game::addEnemy(Enemy *e)
{
    enemies.push_back(e);
    addObject(e);
}

void Game::sceneLogic()
{
    Enemy::playerPos = player->getCenter();
}

