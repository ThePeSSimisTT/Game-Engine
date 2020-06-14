#pragma once
#include "GameUnit.h"
class Monster :public GameUnit
{
protected:
	int Nails;
	int Teeth;
public:
	Monster();
	Monster(int xPossitionInit, int yPossitionInit, int TeamInit, int AttackRangeInit, int ConditionInit, int MoveSpeedInit, int AttackSpeedInit, int NailsInit, int TeethInit);
	void Attack();
	void Defend(int a);
	void Status();
};

