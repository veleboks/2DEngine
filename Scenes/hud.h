#ifndef HUD_H
#define HUD_H

#include "scene.h"
#include "Objects/player.h"
#include "Objects/enemyhpcounter.h"
#include "Objects/playerhpcounter.h"

class HUD : public Scene
{
private:
    Player * player;
    vector<Enemy*> enemies;
    vector<HPCounter*> healthBars;
public:
    HUD(Player * player);
    void addEnemyHealthBar(Enemy* enemy);
    void updateEnemies(vector<Enemy*> enemies);
    // Scene interface
protected:
    void sceneLogic() override;
};

#endif // HUD_H
