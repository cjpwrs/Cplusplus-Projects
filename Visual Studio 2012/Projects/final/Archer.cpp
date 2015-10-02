#include "Archer.h"
#include "Fighter.h"


Archer::Archer(string name, int hp, int strength, int magic):Fighter(name, hp, strength, magic)
{
}


Archer::~Archer(void){}

int Archer::getDamage() 
{
    int damage = currentspeed;
    return damage;
}

//---------------------------------------------------------------------------------------
void Archer::reset()
{
    current_hp = max_hp ;
    currentspeed = maxspeed ;
}

//---------------------------------------------------------------------------------------
void Archer::regenerate()
{
    int regeneration = (strength / 6) ;
    if (regeneration > 0)
    {
        current_hp = current_hp + regeneration ;
    }
    else if (regeneration == 0)
    {
        current_hp++ ;
    }
    if (current_hp > max_hp)
    {
        current_hp = max_hp ;
    }
}
