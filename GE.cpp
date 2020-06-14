#include <iostream>
#include "GameUnit.h"
#include "Knight.h"
#include "Monster.h"
#include "GameEngine.h"
extern GameEngine* p;

int main()
{
	Knight Shen(1, 1, 1, 3, 40, 3, 3, 25, 5);
	Monster Warwick(5, 5, 2, 3, 40, 4, 4, 20, 20);
	GameEngine lol;
	p = &lol;
	lol.AddUnit(&Shen);
	lol.AddUnit(&Warwick);
	for(int i=0;i<10;i++)
		lol.Tact();
}