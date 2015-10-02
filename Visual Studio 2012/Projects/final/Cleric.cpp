#include "Cleric.h"


Cleric::Cleric(string name, int hp, int strength, int magic):Fighter(name, hp, strength, magic)
{
}


Cleric::~Cleric(void)
{
}
int Cleric::getDamage()
{
    int damage = magic ;
    return damage ;
}

//---------------------------------------------------------------------------------------
void Cleric::reset()
{
    current_hp = max_hp ;
    current_mana = 5 * magic ;
}

//---------------------------------------------------------------------------------------
/*
 *	regenerate()
 *
 *	Increases the fighter's current hit points by an amount equal to one sixth of
 *	the fighter's strength.  This method must increase the fighter's current hit 
 *	points by at least one.  Do not allow the current hit points to exceed the 
 *	maximum hit points.
 *
 *	Cleric:
 *	Also increases a Cleric's current mana by an amount equal to one fifth of the 
 *	Cleric's magic.  This method must increase the Cleric's current mana by at 
 *	least one.  Do not allow the current mana to exceed the maximum mana.
 */
void Cleric::regenerate()
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
    int mana_increase = magic / 5 ;
    if (mana_increase > 0)
    {
        current_mana = mana_increase + current_mana ;
    }
    else if (mana_increase == 0)
    {
        current_mana++ ;
    }
    if (current_mana > (magic*5))
    {
        current_mana = magic * 5 ;
    }
}
