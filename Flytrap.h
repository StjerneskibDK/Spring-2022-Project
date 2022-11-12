#ifndef Plant2_H
#define Plant2_H

#pragma once

#include "Crop.h"
#include <cstdlib>
#include <iostream>
#include <ctime>

//flytrap has the ability to gain massive fertilizer levels from bugs, but is much more fertilizer sensitive and susceptible to droughts due to their poor environment
class Flytrap : public Crop {
public:
	//Default constructor.
	Flytrap();

	//Round looping functions, changes base stats until maxMaturity is reached or health is 0.
	void UserInput(bool clearToken);
	void NextDay();
	void SaveGame();
};

#endif