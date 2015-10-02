#pragma once
#include "FighterInterface.h"

class Fighter : public FighterInterface
{
protected:
	string name; 
	int max_hp;	
	int current_hp; 
	int strength; 
	int speed; 
	int magic; 

public:

	Fighter();

	Fighter(string name, int max_hp, int strength, int speed, int magic);
	//fighter constructor

	/*
		*	getName()
		*
		*	Returns the name of this fighter.
		*/
	virtual string getName();

	/*
		*	getMaximumHP()
		*
		*	Returns the maximum hit points of this fighter.
		*/
	virtual int getMaximumHP();

	/*
		*	getCurrentHP()
		*
		*	Returns the current hit points of this fighter.
		*/
	virtual int getCurrentHP();

	/*
		*	getStrength()
		*
		*	Returns the strength stat of this fighter.
		*/
	virtual int getStrength();

	/*
		*	getSpeed()
		*
		*	Returns the speed stat of this fighter.
		*/
	virtual int getSpeed();

	/*
		*	getMagic()
		*
		*	Returns the magic stat of this fighter.
		*/
	virtual int getMagic();

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
	virtual int getDamage();

	/*
	 *	takeDamage(int)
	 *
	 *	Examples:
	 *    damage=10, speed=7		=> damage_taken=9
	 *    damage=10, speed=9		=> damage_taken=8
	 *    damage=10, speed=50		=> damage_taken=1
	 */
	void takeDamage(int damage);

	virtual void reset();

	virtual void regenerate();

	virtual bool useAbility();



};


