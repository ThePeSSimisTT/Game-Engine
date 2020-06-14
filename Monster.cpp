#include "Monster.h"
#include "stdio.h"
#include "GameEngine.h"
extern GameEngine* p;
Monster::Monster() :GameUnit() {
	Nails = 0;
	Teeth = 0;
}
Monster::Monster(int xPossitionInit, int yPossitionInit, int TeamInit, int AttackRangeInit, int ConditionInit, int MoveSpeedInit, int AttackSpeedInit, int NailsInit, int TeethInit) :
	GameUnit(xPossitionInit, yPossitionInit,TeamInit, AttackRangeInit, ConditionInit, MoveSpeedInit, AttackSpeedInit) {
	Nails =NailsInit;
	Teeth = TeethInit;
}
void Monster::Attack() {
	GameUnit::Attack();
	AttackStrength = (Condition / 20 + 1) * ((Nails + Teeth) / 5 + 1);
}
void Monster::Defend(int a) {
	Condition = Condition - a;
}
void Monster::Status() {
	GameUnit::Status();
	printf("     As Monster this unit have stat for nails: %d and stat for teeth: %d\n", Nails, Teeth);
}
