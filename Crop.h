#ifndef Crop_H
#define Crop_H

#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

class Crop {
protected: 
	//Base statistic for every plant.
	bool isNormal;

	int health;
	int maxHealth;

	int currentMaturity;
	int maxMaturity;

	int currentEnergyLevel;
	int maxEnergyLevel;
	int criticalEnergy;
	int lowerEnergy;

	int currentWaterLevel;
	int maxWaterLevel;
	int criticalWater;
	int lowerWater;
	int upperWater;

	int currentFertilizerLevel;
	int maxFertilizerLevel;
	int criticalFertilizer;
	int lowerFertilizer;
	int upperFertilizer;

	//STATUS EFFECTS
	bool status_drought; //decrease effectiveness of watering plants
	int droughtCounter;

	bool status_heavyrain; //give A LOT of water to the plant per turn
	int heavyrainCounter;

	bool status_heatwave; //increase water loss per turn
	int heatwaveCounter;

	bool status_coldsnap; //deal small but direct damage to health for a few turns
	int coldsnapCounter;

	bool status_buginfest; //has a chance to deal small damage, but lasts permenantly until removed
	bool buginfestUniqueStatus; //used for the status message when the infestation is cleared.

	//Player interactions values (watering plants, fertilizing)
	int watering;
	int fertilizing;

	//Token to end the game.
	bool loseToken;
	bool winToken;

public:
	bool GetLoseToken() { return loseToken; }
	bool GetWinToken() { return winToken; }
	int GetHealth() { return health; }
	void LoadGame();
	//Default constructor.
	Crop() {}

	//Player interaction.
	virtual void UserInput(bool clearToken) = 0;
	virtual void NextDay() = 0;
	virtual void SaveGame() = 0;
};




#endif