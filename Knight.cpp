#include "Knight.h"
#include "stdio.h"
#include "GameEngine.h"
extern GameEngine* p;
Knight::Knight() :GameUnit() {
	Sword = 0;
	Armor = 0;
}
Knight::Knight(int xPossitionInit, int yPossitionInit, int TeamInit, int AttackRangeInit, int ConditionInit, int MoveSpeedInit, int AttackSpeedInit, int SwordInit, int ArmorInit) :
	GameUnit(xPossitionInit, yPossitionInit, TeamInit, AttackRangeInit, ConditionInit, MoveSpeedInit, AttackSpeedInit) {
	Sword = SwordInit;
	Armor = ArmorInit;
}
void Knight::Attack() {
	GameUnit::Attack();
	AttackStrength = (Condition / 20 + 1) * (Sword / 2 + 1);
}
void Knight::Defend(int a) {
	Condition = Condition - (a-Armor*2);
}
void Knight::Status() {
	GameUnit::Status();
	printf("     As Knight this unit have stat for sword: %d and stat for armor: %d\n",Sword,Armor);
}