#pragma once
#include "GameUnit.h"
class Knight:public GameUnit
{
protected:
	int Sword;
	int Armor;
public:
	Knight();
	Knight(int xPossitionInit, int yPossitionInit, int TeamInit, int AttackRangeInit, int ConditionInit, int MoveSpeedInit, int AttackSpeedInit, int SwordInit, int ArmorInit);
	void Attack();
	void Defend(int a);
	void Status();
};

