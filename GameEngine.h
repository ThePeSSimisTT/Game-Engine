#pragma once
#include "GameUnit.h"
class GameEngine
{
	
public:
	GameUnit* Unit[20]; //problem li e che sa public
	int CountUnits; //????
	GameEngine();
	void AddUnit(GameUnit* U);
	void Clear();
	void Search();
	void Tact();
};

