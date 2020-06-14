#pragma once
#include "TPoint.h"
class GameUnit
{
protected:
	int MoveSpeed;
	int TactMoveSpeed;
	int AttackSpeed;
	int TactAttackSpeed;
	int AttackStrength;
	int AttackRange;
public:
	int Team;
	int Condition;
	TPoint Position, Target;
	GameUnit();
	GameUnit(int xPossitionInit, int yPossitionInit,int TeamInit,int AttackRangeInit, int ConditionInit, int MoveSpeedInit, int AttackSpeedInit);
	void Move();
	virtual void Attack();
	virtual void Defend(int a) {};
	virtual void Status();
};

