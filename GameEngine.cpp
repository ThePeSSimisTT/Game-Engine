#include "GameEngine.h"
#include "stdio.h"
#include "math.h"
#include "float.h"

GameEngine* p;

GameEngine::GameEngine() {
	CountUnits = 0;
}
void GameEngine::AddUnit(GameUnit* U) {
	Unit[CountUnits] = U;
	CountUnits++;
}
void GameEngine::Clear() {
	for (int i = 0;i < CountUnits;i++)
		if (Unit[i]->Condition <= 0) {
			CountUnits--;
			for (int j = i;j < CountUnits;j++)
				Unit[j] = Unit[j + 1];
		}
}

void GameEngine::Search() {
	for (int i = 0;i < CountUnits;i++) {
		double min = DBL_MAX;
		for (int j = 0;j < CountUnits;j++) {
			if (Unit[i]->Team == Unit[j]->Team)
				continue;
			double min_min= DBL_MAX;
			min_min= sqrt((Unit[i]->Position.x - Unit[j]->Position.x) * (Unit[i]->Position.x - Unit[j]->Position.x) + (Unit[i]->Position.y - Unit[j]->Position.y)* (Unit[i]->Position.y - Unit[j]->Position.y));
			if (min_min < min) {
				min = min_min;
				Unit[i]->Target.x = Unit[j]->Position.x;
				Unit[i]->Target.y = Unit[j]->Position.y;
			}
		}
	}
}
void GameEngine::Tact() {
	printf("Start of a tact");
	printf("\nUnits Move\n");

	for (int i = 0;i < CountUnits;i++) 
		Unit[i]->Move();

	printf("\nEnd of Move\n");
	Search();

	for (int i = 0;i < CountUnits;i++) 
		Unit[i]->Status();

	Clear();
	printf("\nUnits Attack\n");

	for (int i = 0;i < CountUnits;i++) 
		Unit[i]->Attack();

	printf("\nEnd of Attack\n");
	printf("\nStats After Attack\n");
	for (int i = 0;i < CountUnits;i++) 
		Unit[i]->Status();
	printf("\nEnd of a tact\n\n\n\n\n\n");
}