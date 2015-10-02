#include "Fighter.h"

Fighter::Fighter(string fname, int max_HP, int fstrength, int fspeed, int fmagic)
{
    name = fname;
    max_hp = max_HP;
    strength = fstrength;
    speed = fspeed;
    magic = fmagic;
}

string Fighter::getName()
{
    return name;
}

int Fighter::getMaximumHP()
{
    return max_hp;
}

int Fighter::getCurrentHP()
{
    return current_hp;
}

int Fighter::getStrength()
{
    return strength;
}

int Fighter::getSpeed()
{
    return speed;
}

int Fighter::getMagic()
{
    return magic;
}

int Fighter::getDamage()
{
    return 0;
}

void Fighter::takeDamage(int damage)
{	
    int damage_taken = damage - (speed/4);
    if (damage_taken > 1)
    {
        current_hp -= (damage_taken);
    }
    if (damage_taken <= 1)
    {
        current_hp--;
    }
}

void Fighter::reset()
{
    current_hp = max_hp;
}

void Fighter::regenerate()
{

}

bool Fighter::useAbility()
{
    return true;
}


