#include "Fighter.h"
#include <vector>
#include<sstream>


Fighter::Fighter(string name, int hp, int strength, int magic)
{
}

Fighter::~Fighter(void){}

		/*Fighter::Fighter(string name, int hp, int speed, int magic)
		{

		}*/
/*
		 *	getName()
		 *
		 *	Returns the name of this fighter.
		 */
		string Fighter::getName()
		{
			return name;
		}

		/*
		 *	getMaximumHP()
		 *
		 *	Returns the maximum hit points of this fighter.
		 */
		int Fighter::getMaximumHP()
		{
			return max_hp;
		}

		/*
		 *	getCurrentHP()
		 *
		 *	Returns the current hit points of this fighter.
		 */
		int Fighter::getCurrentHP()
		{
			return current_hp;
		}

		/*
		 *	getStrength()
		 *
		 *	Returns the strength stat of this fighter.
		 */
		int Fighter::getStrength()
		{
			return strength;
		}

		/*
		 *	getSpeed()
		 *
		 *	Returns the speed stat of this fighter.
		 */
		int Fighter::getSpeed()
		{
			return speed;
		}

		/*
		 *	getMagic()
		 *
		 *	Returns the magic stat of this fighter.
		 */
		int Fighter::getMagic()
		{
			return magic;
		}

		/*
		 *	getDamage()
		 *
		 *	Returns the amount of damage a fighter will deal.
		 *
		 *	Robot:
		 *	This value is equal to the Robot's strength plus any additional damage added for having just used its special ability.
		 *
		 *	Archer:
		 *	This value is equal to the Archer's speed.
		 *
		 *	Cleric:
		 *	This value is equal to the Cleric's magic.
		 */
		int Fighter::getDamage()
		{

		}

		/*
		 *	takeDamage(int)
		 *
		 *	Reduces the fighter's current hit points by an amount equal to the given 
		 *	damage minus one fourth of the fighter's speed (minimum of one).  It is 
		 *	acceptable for this method to give the fighter negative current hit points.
		 *
		 *	Examples:
		 *		damage=10, speed=3		=> damage_taken=10
		 *		damage=10, speed=7		=> damage_taken=9
		 *		damage=10, speed=9		=> damage_taken=8
		 *		damage=10, speed=50		=> damage_taken=1
		 */
		void takeDamage(int damage)
		{
			int damage_taken = 0 ;
			damage_taken = damage - (speed/4) ;
			if (damage_taken >= 1)
			{
				current_hp = current_hp - damage_taken ;
			}
			else if (damage_taken == 0)
			{
				current_hp-- ;
			}  
		}

		/*
		 *	reset()
		 *
		 *	Restores a fighter's current hit points to its maximum value.
		 *
		 *	Robot:
		 *	Also restores a Robot's current electricity to its maximum value.
		 *	Also resets a Robot's bonus damage to 0.
		 *
		 *	Archer:
		 *	Also resets an Archer's speed to its original value.
		 *
		 *	Cleric:
		 *	Also restores a Cleric's current mana to its maximum value.
		 */
		void Fighter::reset()
		{

		}

		/*
		 *	regenerate()
		 *
		 *	Increases the fighter's current hit points by an amount equal to one sixth of
		 *	the fighter's strength (minimum of one unless already at maximum).
		 *
		 *	Cleric:
		 *	Also increases a Cleric's current mana by an amount equal to one fifth of the 
		 *	Cleric's magic (minimum of one unless already at maximum).
		 */
		void Fighter::regenerate()
		{

		}

		/*
		 *	useAbility()
		 *	
		 *	Attempts to perform a special ability based on the type of fighter.  The 
		 *	fighter will attempt to use this special ability just prior to attacking 
		 *	every turn.
		 *
		 *	Robot: Shockwave Punch
		 *	Adds bonus damage to the Robot's next attack (and only its next attack) equal to (strength  * ((current_electricity/maximum_electricity)^4)).
		 *	Can only be used if the Robot has at least [ROBOT_ABILITY_COST] electricity.
		 *	Decreases the Robot's current electricity by [ROBOT_ABILITY_COST] (after calculating the additional damage) when used.
		 *	The bonus damage formula should be computed using double arithmetic, and only the final result should be cast into an integer.
		 *	Examples:
		 *		strength=20, current_electricity=20, maximum_electricity=20		=> bonus_damage=20
		 *		strength=20, current_electricity=15, maximum_electricity=20		=> bonus_damage=6
		 *		strength=20, current_electricity=10, maximum_electricity=20		=> bonus_damage=1
		 *		strength=20, current_electricity=5,  maximum_electricity=20		=> bonus_damage=0
		 *
		 *	Archer: Quickstep
		 *	Increases the Archer's speed by one point each time the ability is used.
		 *	This bonus lasts until the reset() method is used.
		 *	This ability always works; there is no maximum bonus speed.
		 *
		 *	Cleric: Healing Light
		 *	Increases the Cleric's current hit points by an amount equal to one third of its magic (minimum of one unless already at maximum).
		 *	Can only be used if the Cleric has at least [CLERIC_ABILITY_COST] mana.
		 *	Will be used even if the Cleric's current hit points is equal to their maximum hit points.
		 *	Decreases the Cleric's current mana by [CLERIC_ABILITY_COST] when used.
		 *
		 *	Return true if the ability was used; false otherwise.
		 */
		bool Fighter::useAbility()
		{

		}