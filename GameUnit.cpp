#include "GameUnit.h"
#include "stdio.h"
#include "math.h"
#include "GameEngine.h"
extern GameEngine* p;
GameUnit::GameUnit() {
	Condition = 100;
	MoveSpeed = 0;
	TactMoveSpeed = 5-MoveSpeed;
	AttackSpeed = 0;
	TactAttackSpeed = 5 - AttackSpeed;
	AttackStrength = 0;
	Team = 0;
	AttackRange = 0;
}
GameUnit::GameUnit(int xPossitionInit, int yPossitionInit, int TeamInit, int AttackRangeInit, int ConditionInit, int MoveSpeedInit, int AttackSpeedInit) {
	Position.x = xPossitionInit;
	Position.y = yPossitionInit;
	Team = TeamInit;
	AttackRange = AttackRangeInit;
	Condition = ConditionInit;
	MoveSpeed = MoveSpeedInit;
	TactMoveSpeed = 5 - MoveSpeed;
	AttackSpeed = AttackSpeedInit;
	TactAttackSpeed = 5 - AttackSpeed;
	AttackStrength = 0;
}
void GameUnit::Move() {
	if (TactMoveSpeed > 0)
		TactMoveSpeed--;
	else if (TactMoveSpeed <= 0) {
		printf("\nUnit Moves from (%d:%d) toward (%d:%d)\n", Position.x, Position.y, Target.x, Target.y);
		for (int i = 0;i < 2;i++) {
			if (abs(Position.x - Target.x) <= 1) {}
			else if (Position.x < Target.x)
				Position.x = Position.x + 1;
			else if (Position.x > Target.x)
				Position.x = Position.x - 1;
		}
		if (abs(Position.y - Target.y) <= 1) {}
		else if (Position.y < Target.y)
			Position.y = Position.y + 1;
		else if (Position.y > Target.y)
			Position.y = Position.y - 1;
		TactMoveSpeed = 5 - MoveSpeed;
	}
}
void GameUnit::Attack() {
	if (TactAttackSpeed > 0)
		TactAttackSpeed--;
	else if (TactAttackSpeed<=0) {
		printf("\nUnit at (%d:%d) attacks\n", Target.x,Target.y);
		for (int i = 0;i < p->CountUnits;i++){
			if (p->Unit[i]->Position.x > Position.x - AttackRange &&
				p->Unit[i]->Position.x < Position.x + AttackRange &&
				p->Unit[i]->Position.y > Position.y - AttackRange &&
				p->Unit[i]->Position.y < Position.y + AttackRange &&
				p->Unit[i]->Team!=Team)
				Defend(AttackStrength);
		}
		TactAttackSpeed = 5 - AttackSpeed;
	}
}
void GameUnit::Status() {
	printf("\n\nThis Unit have:\n     Possition: (%d:%d)\n     Target: (%d:%d)\n     Condition: %d\n     MoveSpeed: %d and %d turns left before moving\n     AttackSpeed: %d and %d turns left before attacking\n",
		Position.x, Position.y, Target.x, Target.y, Condition, MoveSpeed, TactMoveSpeed, AttackSpeed, TactAttackSpeed);
}