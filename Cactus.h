#ifndef Plant1_H
#define Plant1_H

#pragma once

#include "Crop.h"
#include <cstdlib>
#include <iostream>
#include <ctime>

//Cactus is resistant to heat effects and droughts, but takes extra damage from cold and is MUCH more sensitive to water levels
class Cactus : public Crop {
public:
	//Default constructor.
	Cactus();
	
	//Round looping functions, changes base stats until maxMaturity is reached or health is 0.
	void UserInput(bool clearToken);
	void NextDay();
	void SaveGame();
};

#endif