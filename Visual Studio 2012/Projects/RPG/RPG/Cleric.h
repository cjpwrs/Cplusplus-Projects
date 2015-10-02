#include <iostream>
#pragma once
#include "Fighter.h"
//#include "FighterInterface.h"


class Cleric : public Fighter
{
private:
    int max_mana;
    int current_mana;

public:
	//cleric constructor
    Cleric(string name, int strength, int hp, int speed, int magic);
  /*
   *  getDamage()
   *
   *  Returns the amount of damage a fighter will deal.
   *
   *  Cleric:
   *  This value is equal to the Cleric's magic.
   */
    int getDamage();
  /*
   *  Restores a fighter's current hit points to its maximum value.
   *
   *  Cleric:
   *  Also restores a Cleric's current mana to its maximum value.
   */
    void reset();
	
	/*
   *  regenerate()
   *
   *  Cleric:
   *  Also increases a Cleric's current mana by an amount equal to one fifth of the
   *  Cleric's magic.  This method must increase the Cleric's current mana by at
   *  least one.  Do not allow the current mana to exceed the maximum mana.
   */
    void regenerate();

  /*
   *  useAbility()
   *
   *  Attempts to perform a special ability based on the type of fighter.  The
   *  fighter will attempt to use this special ability just prior to attacking
   *  every turn.
   *
   *  Cleric: Healing Light
   *  Increases the Cleric's current hit points by an amount equal to one third of its magic.
   *  Can only be used if the Cleric has at least [CLERIC_ABILITY_COST] mana.
   *  Will be used even if the Cleric's current HP is equal to their maximum HP
   *  Decreases the Cleric's current mana by [CLERIC_ABILITY_COST] when used.
   *
   *  Cleric Note:
   *  This ability, when successful, must increase the Cleric's current hit points
   *  by at least one.  Do not allow the current hit points to exceed the maximum
   *  hit points.
   *
   * Return true if the ability was used; false otherwise.
   */
    bool useAbility();
  

};



