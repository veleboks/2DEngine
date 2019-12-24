#ifndef DAMAGEOBJECT_H
#define DAMAGEOBJECT_H

#include "gameobject.h"
#include <vector>

using namespace std;

class DamageObject : public GameObject
{
protected:
    float DAMAGE;
public:
    virtual FloatRect getGlobalBounds() = 0;
    float getDamage();
    void setDamage(float value);
    float getGlobalDamage(DamageObject * d);

    // Drawable interface
protected:
    vector<DamageObject*> damagedObjs;
    virtual void draw(RenderTarget &target, RenderStates states) const = 0;
    void addDamagedObj(DamageObject * obj){damagedObjs.push_back(obj);}
    bool checkIntersection(DamageObject * dObj) {return getGlobalBounds().intersects(dObj->getGlobalBounds());}
    // GameObject interface
public:
    virtual void logic() = 0;
};

#endif // DAMAGEOBJECT_H
