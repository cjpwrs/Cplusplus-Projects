#pragma once
#include "fighter.h"
class Robot :
	public Fighter
{
private:
	string name;
	int hit_points;
	int current_hp;
	int max_hp;
	int strength;
	int currentspeed;
	int maxspeed;
	int magic;
	int additional_damage;
	int current_energy;

public:
	Robot(string name, int hp, int strength, int magic);
	~Robot(void);

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
		int getDamage();

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
		void reset();

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
		void regenerate();

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
		bool useAbility();
};

