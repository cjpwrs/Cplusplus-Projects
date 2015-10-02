#pragma once
#include "fighterinterface.h"


/*
 *	This class specifies the methods for a fighter.
 *
 *	All fighters have the following attributes:
 *		Name - The fighter's name
 *		Hit Points - The amount of health the fighter has, with a specified maximum; reaching 0 is equivalent to losing
 *		Strength - Physical power, used to determine hit point regeneration
 *		Speed - Dexterity and physical movement, used to reduce damage when being attacked
 *		Magic - Magical prowess, used for some special abilities
 *
 *	The three fighter types have unique abilities:
 *		Robot - Relies on strength to deal damage; also can use stored electricity to temporarily increase damage (maximum electricity equal to 2*magic)
 *		Archer - Relies on speed to deal damage; also can increase its speed for the remainder of the battle (no max bonus speed)
 *		Cleric - Relies on magic to deal damage; also can heal itself using mana, restoring hit points (maximum mana equal to 5*magic)
 *
 *	For any stat that has a maximum value (hit points, electricity, and mana), never allow the current value to exceed the maximum under any circumstances.
 *
 *	More details about how stats are used and how abilities work can be found in the comments below.
 */

/*
 *	ROBOT_ABILITY_COST
 *	The amount of electricity a Robot needs to use its special ability.
 */
const int ROBOT_ABILITY_COST = 5;

/*
 *	CLERIC_ABILITY_COST
 *	The amount of mana a Cleric needs to use its special ability.
 */
const int CLERIC_ABILITY_COST = 25;

class Fighter :
	public FighterInterface
{
private:
	string name;
	int hit_points;
	int current_hp;
	int max_hp;
	int strength;
	int speed;
	int magic;

public:
	Fighter(string name, int hp, int strength, int magic);
	~Fighter(void);
		
		/*
		 *	getName()
		 *
		 *	Returns the name of this fighter.
		 */
		string getName();

		/*
		 *	getMaximumHP()
		 *
		 *	Returns the maximum hit points of this fighter.
		 */
		int getMaximumHP();

		/*
		 *	getCurrentHP()
		 *
		 *	Returns the current hit points of this fighter.
		 */
		int getCurrentHP();

		/*
		 *	getStrength()
		 *
		 *	Returns the strength stat of this fighter.
		 */
		int getStrength();

		/*
		 *	getSpeed()
		 *
		 *	Returns the speed stat of this fighter.
		 */
		int getSpeed();

		/*
		 *	getMagic()
		 *
		 *	Returns the magic stat of this fighter.
		 */
		int getMagic();

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
		void takeDamage(int damage);

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

