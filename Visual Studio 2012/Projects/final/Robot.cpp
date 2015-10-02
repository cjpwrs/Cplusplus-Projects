#include "Robot.h"


Robot::Robot(string name, int hp, int strength, int magic):Fighter(name, hp, strength, magic)
{
	
}


Robot::~Robot(void){}
int Robot::getDamage()
{
    int damage = strength + additional_damage;
    return damage ;
}

//---------------------------------------------------------------------------------------
void Robot::reset()
{
    current_hp = max_hp ;
    additional_damage = 0 ;
    current_energy = 2 * magic ;
}

//---------------------------------------------------------------------------------------
void Robot::regenerate()
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
