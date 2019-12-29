#ifndef DAMAGEOBJECT_H
#define DAMAGEOBJECT_H

#include "gameobject.h"
#include <vector>

using namespace std;

class DamageObject : public GameObject
{
protected:
    DamageObject * prev;
    float DAMAGE;
public:
    virtual float getRotation() = 0;
    virtual Vector2f getPosition() = 0;
    virtual FloatRect getGlobalBounds() = 0;
    virtual float getDamage();
    void setDamage(float value);
    float getGlobalDamage(DamageObject * d);


    // Drawable interface
protected:
    vector<DamageObject*> damagedObjs;
    virtual void draw(RenderTarget &target, RenderStates states) const = 0;
    void addDamagedObj(DamageObject * obj){damagedObjs.push_back(obj);}
    virtual bool checkIntersection(DamageObject * dObj) {return getGlobalBounds().intersects(dObj->getGlobalBounds());}
    // GameObject interface
public:
    virtual void logic() = 0;
};

#endif // DAMAGEOBJECT_H
