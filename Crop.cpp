#include "Crop.h"
using namespace std;

void Crop::LoadGame() {
	ifstream IFS;
	IFS.open("savegame.txt");

	if (!IFS.is_open()) {
		cout << "savegame.txt not found. Make sure to save the game before loading!" << endl << endl;
		exit(-1);
	}
	int temp;

	//statistics
	IFS >> temp;
	isNormal = temp;

	IFS >> temp;
	health = temp;
	IFS >> temp;
	maxHealth = temp;

	IFS >> temp; 
	currentMaturity = temp;
	IFS >> temp;
	maxMaturity = temp;

	IFS >> temp;
	currentEnergyLevel = temp;
	IFS >> temp;
	maxEnergyLevel = temp;
	IFS >> temp;
	criticalEnergy = temp;
	IFS >> temp;
	lowerEnergy = temp;

	IFS >> temp;
	currentWaterLevel = temp;
	IFS >> temp;
	maxWaterLevel = temp;
	IFS >> temp;
	criticalWater = temp;
	IFS >> temp;
	lowerWater = temp;
	IFS >> temp;
	upperWater = temp;

	IFS >> temp;
	currentFertilizerLevel = temp;
	IFS >> temp;
	maxFertilizerLevel = temp;
	IFS >> temp;
	criticalFertilizer = temp;
	IFS >> temp;
	lowerFertilizer = temp;
	IFS >> temp;
	upperFertilizer = temp;

	IFS >> temp;
	status_drought = temp;
	IFS >> temp;
	droughtCounter = temp;

	IFS >> temp;
	status_heavyrain = temp;
	IFS >> temp;
	heavyrainCounter = temp;

	IFS >> temp;
	status_heatwave = temp;
	IFS >> temp;
	heatwaveCounter = temp;

	IFS >> temp;
	status_coldsnap = temp;
	IFS >> temp;
	coldsnapCounter = temp;

	IFS >> temp;
	status_buginfest = temp;
	IFS >> temp;
	buginfestUniqueStatus = temp;

	//Player interactions values (watering plants, fertilizing)
	IFS >> temp;
	watering = temp;
	IFS >> temp;
	fertilizing = temp;

	//Token to end the game.
	IFS >> temp;
	loseToken = temp;
	IFS >> temp;
	winToken = temp;

	IFS.close();

	return;
}