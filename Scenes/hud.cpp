#include "hud.h"



HUD::HUD(Player *player)
{
    this->player = player;
    healthBars.push_back(new PlayerHPCounter(Vector2f(20, 20), Vector2f(150, 30), player));
    addObject(*healthBars.end());
}

void HUD::addEnemyHealthBar(Enemy *enemy)
{
    healthBars.push_back(new EnemyHPCounter(enemy->getPosition(), Vector2f(45, 15), enemy));
    enemies.push_back(enemy);
    addObject(*healthBars.end());
}

void HUD::sceneLogic()
{
    // TODO: check death
    clearObjects();
    addObject(*healthBars.begin());
    for (unsigned int i = 0; i < enemies.size();) {
        if (enemies[i]->getHP() <= 0) {
            auto eraseEnemy = enemies.begin();
            advance(eraseEnemy, i);
            enemies.erase(eraseEnemy);
            delete healthBars[i+1];
            auto eraseHB = healthBars.begin();
            advance(eraseHB, i+1);
            healthBars.erase(eraseHB);
        } else {
            addObject(healthBars[i+1]);
            ++i;
        }
    }

}
