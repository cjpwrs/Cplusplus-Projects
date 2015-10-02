#include <iostream>
#pragma once
#include "Fighter.h"
//#include "FighterInterface.h"

class Archer : public Fighter
{
private:
    int original_speed;

public:
	//archer constructor
    Archer(string name, int strength, int hp, int speed, int magic);

  /*
   *  getDamage()
   *
   *  Returns the amount of damage a fighter will deal.
   *
   *  Archer:
   *  This value is equal to the Archer's speed.
   */
    int getDamage();

  /*
   *  reset()
   *
   *  Restores a fighter's current hit points to its maximum hit points.
   *
   *  Archer:
   *  Also resets an Archer's current speed to its original value.
   */
    void reset();

  /*
   *  useAbility()
   *
   *  Attempts to perform a special ability based on the type of fighter.  The
   *  fighter will attempt to use this special ability just prior to attacking
   *  every turn.
   *
   *  Archer: Quickstep
   *  Increases the Archer's speed by one point each time the ability is used.
   *  This bonus lasts until the reset() method is used.
   *  This ability always works; there is no maximum bonus speed.
   *
   *  Return true if the ability was used; false otherwise.
   */
	void regenerate();

    bool useAbility();

    

};



