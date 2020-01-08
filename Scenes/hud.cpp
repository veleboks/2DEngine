#include "hud.h"



HUD::HUD(Player *player, vector<Enemy *> enemies)
{
    addObject(new PlayerHPCounter(Vector2f(20, 20), Vector2f(30, 150), player));

    for (auto enemy : enemies) {
        addObject(new EnemyHPCounter(enemy->getPosition(), Vector2f(15, 45), enemy));
    }
}

void HUD::sceneLogic()
{
    // TODO: check death
}
