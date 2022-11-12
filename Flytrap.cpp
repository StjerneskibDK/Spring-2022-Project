#include "Flytrap.h"

using namespace std;

//initializes values
Flytrap::Flytrap() {
	health = 100;
	maxHealth = 100;

	currentMaturity = 0;
	maxMaturity = 20;

	currentEnergyLevel = 20;
	maxEnergyLevel = 20;
	criticalEnergy = 6;
	lowerEnergy = 14;

	currentWaterLevel = 30;
	maxWaterLevel = 30;
	criticalWater = 8;
	lowerWater = 18;
	upperWater = 36;

	currentFertilizerLevel = 22;
	maxFertilizerLevel = 22;
	criticalFertilizer = 6;
	lowerFertilizer = 14;
	upperFertilizer = 27;

	status_drought = false;
	droughtCounter = rand() % 4 + 2;

	status_heavyrain = false;
	heavyrainCounter = rand() % 4 + 2;

	status_heatwave = false;
	heatwaveCounter = rand() % 4 + 2;

	status_coldsnap = false;
	coldsnapCounter = rand() % 4 + 2;

	status_buginfest = false;
	buginfestUniqueStatus = false;

	watering = 6;
	fertilizing = 6;

	loseToken = false;
	winToken = false;
}

//writes to .txt file
void Flytrap::SaveGame() {
	ofstream OFS;
	OFS.open("savegame.txt");

	//Flytrap identifier
	OFS << 0 << " ";

	//statistics
	OFS << health << " ";
	OFS << maxHealth << " ";

	OFS << currentMaturity << " ";
	OFS << maxMaturity << " ";

	OFS << currentEnergyLevel << " ";
	OFS << maxEnergyLevel << " ";
	OFS << criticalEnergy << " ";
	OFS << lowerEnergy << " ";

	OFS << currentWaterLevel << " ";
	OFS << maxWaterLevel << " ";
	OFS << criticalWater << " ";
	OFS << lowerWater << " ";
	OFS << upperWater << " ";

	OFS << currentFertilizerLevel << " ";
	OFS << maxFertilizerLevel << " ";
	OFS << criticalFertilizer << " ";
	OFS << lowerFertilizer << " ";
	OFS << upperFertilizer << " ";

	OFS << status_drought << " ";
	OFS << droughtCounter << " ";

	OFS << status_heavyrain << " ";
	OFS << heavyrainCounter << " ";

	OFS << status_heatwave << " ";
	OFS << heatwaveCounter << " ";

	OFS << status_coldsnap << " ";
	OFS << coldsnapCounter << " ";

	OFS << status_buginfest << " ";
	OFS << buginfestUniqueStatus << " ";

	//Player interactions values (watering plants, fertilizing)
	OFS << watering << " ";
	OFS << fertilizing << " ";

	//Token to end the game.
	OFS << loseToken << " ";
	OFS << winToken << " ";
	OFS.close();

	exit(0);
}

//user input function, changes values based on input
void Flytrap::UserInput(bool clearToken) {
	system("CLS"); //clears console when called
	//prints the UI
	for (int i = 0; i < 100; i++) {
		if (i == 45) {
			cout << (char)0xBF;
		}
		else if (i == 46) {
			cout << " DAY: " << currentMaturity << " ";
			if (currentMaturity < 10) {
				cout << " ";
			}
		}
		else if (i == 55) {
			cout << (char)0xDA;
		}
		else if (i < 45 || i > 55) {
			cout << (char)0xC4;
		}
	}
	cout << endl;
	for (int i = 0; i <= 55; i++) {
		if (i == 45) {
			cout << (char)0xC0;

		}
		else if (i == 55) {
			cout << (char)0xD9;
		}
		else if (i > 45 && i < 55) {
			cout << (char)0xC4;
		}
		else {
			cout << " ";
		}
	}
	cout << endl;

	if (clearToken == true) {
		cout << "Invalid input received, please try again!" << endl << endl;
	}
	cout << "Enter one of the following input options, or S to exit and save the game" << endl << endl
		<< "W: Water flytrap (+" << watering << " water) | F: Fertilize flytrap (+4 fertilizer) | ";
	if (status_buginfest == true) { cout << "R: Consume bugs  |  "; }
	cout << "N: No input";

	cout << endl << endl << endl << endl << endl << endl << endl;
	for (int i = 0; i < 100; i++) {
		if (i == 13) {
			cout << (char)0xC2;
		}
		else {
			cout << (char)0xC4;
		}
	}
	cout << endl <<
		"Current stats" << (char)0xB3 << endl;
	for (int i = 0; i < 13; i++) {
		cout << (char)0xC4;
	}
	cout << (char)0xD9 << endl <<
		"Health: " << health << endl <<
		"Water: " << currentWaterLevel << endl <<
		"Fertilizer: " << currentFertilizerLevel << endl <<
		"Energy: " << currentEnergyLevel << endl;

	for (int i = 0; i < 100; i++) {
		if (i == 14) {
			cout << (char)0xC2;
		}
		else {
			cout << (char)0xC4;
		}
	}
	cout << endl <<
		"Current events" << (char)0xB3 << endl;
	for (int i = 0; i < 14; i++) {
		cout << (char)0xC4;
	}
	cout << (char)0xD9 << endl;

	if (status_drought == true) {
		if (droughtCounter == 0) {
			cout << "Drought, ends next day" << endl;
		}
		else {
			cout << "Drought. Days remaining: " << droughtCounter << " (very effective)" << endl;
		}
	}
	if (status_heavyrain == true) {
		if (heavyrainCounter == 0) {
			cout << "Heavy rains, ends next day" << endl;
		}
		else {
			cout << "Heavy rains. Days remaining: " << heavyrainCounter << endl;
		}
	}
	if (status_heatwave == true) {
		if (heatwaveCounter == 0) {
			cout << "Heatwave, ends next day" << endl;
		}
		else {
			cout << "Heatwave. Days remaining: " << heatwaveCounter << endl;
		}
	}
	if (status_coldsnap == true) {
		if (coldsnapCounter == 0) {
			cout << "Cold snap, ends next day" << endl;
		}
		else {
			cout << "Cold snap. Days remaining: " << coldsnapCounter << endl;
		}
	}
	if (status_buginfest == true) {
		cout << "Bug infestation. You can consume them for fertilizer!" << endl;
	}

	cout << endl;
	for (int i = 0; i < 100; i++) {
		cout << (char)0xC4;
	}

	cout << endl;
	char input; cin >> input;
	system("CLS");
	//reprint the top of screen
	for (int i = 0; i < 100; i++) {
		if (i == 45) {
			cout << (char)0xBF;
		}
		else if (i == 46) {
			cout << " DAY: " << currentMaturity << " ";
			if (currentMaturity < 10) {
				cout << " ";
			}
		}
		else if (i == 55) {
			cout << (char)0xDA;
		}
		else if (i < 45 || i > 55) {
			cout << (char)0xC4;
		}
	}
	cout << endl;
	for (int i = 0; i <= 55; i++) {
		if (i == 45) {
			cout << (char)0xC0;

		}
		else if (i == 55) {
			cout << (char)0xD9;
		}
		else if (i > 45 && i < 55) {
			cout << (char)0xC4;
		}
		else {
			cout << " ";
		}
	}
	cout << endl;
	//user inputs
	if (input == 'W') {
		currentWaterLevel += watering;
		cout << "Watered the flytrap! (+" << watering << " water)" << endl << endl;
	}
	else if (input == 'w') {
		currentWaterLevel += watering;
		cout << "Watered the flytrap! (+" << watering << " water)" << endl << endl;
	}
	else if (input == 'F') {
		currentFertilizerLevel += fertilizing;
		cout << "Fertilized the flytrap! (+" << fertilizing << " fertilizer)" << endl << endl;
	}
	else if (input == 'f') {
		currentFertilizerLevel += fertilizing;
		cout << "Fertilized the flytrap! (+" << fertilizing << " fertilizer)" << endl << endl;
	}
	else if (input == 'R') {
		status_buginfest = false;
		currentFertilizerLevel += 7;
		cout << "The flytrap ate the bugs. +7 fertilizer!" << endl << endl;
	}
	else if (input == 'r') {
		status_buginfest = false;
		currentFertilizerLevel += 7;
		cout << "The flytrap ate the bugs. +7 fertilizer!" << endl << endl;
	}
	else if (input == 'N') {
		cout << "No action taken." << endl << endl;
	}
	else if (input == 'n') {
		cout << "No action taken." << endl << endl;
	}
	else if (input == 'S') {
		cout << "Game saved, now exiting." << endl << endl;
		SaveGame();
	}
	else if (input == 's') {
		cout << "Game saved, now exiting." << endl << endl;
		SaveGame();
	}
	else {
		UserInput(true);
	}
	if (clearToken == true) {
		return;
	}

	//reprint the bottom of screen
	cout << endl << endl << endl << endl << endl << endl << endl;
	for (int i = 0; i < 100; i++) {
		if (i == 13) {
			cout << (char)0xC2;
		}
		else {
			cout << (char)0xC4;
		}
	}
	cout << endl <<
		"Current stats" << (char)0xB3 << endl;
	for (int i = 0; i < 13; i++) {
		cout << (char)0xC4;
	}
	cout << (char)0xD9 << endl <<
		"Health: " << health << endl <<
		"Water: " << currentWaterLevel << endl <<
		"Fertilizer: " << currentFertilizerLevel << endl <<
		"Energy: " << currentEnergyLevel << endl;

	for (int i = 0; i < 100; i++) {
		if (i == 14) {
			cout << (char)0xC2;
		}
		else {
			cout << (char)0xC4;
		}
	}
	cout << endl <<
		"Current events" << (char)0xB3 << endl;
	for (int i = 0; i < 14; i++) {
		cout << (char)0xC4;
	}
	cout << (char)0xD9 << endl;

	if (status_drought == true) {
		if (droughtCounter == 0) {
			cout << "Drought, ends next day" << endl;
		}
		else {
			cout << "Drought. Days remaining: " << droughtCounter << " (very effective)" << endl;
		}
	}
	if (status_heavyrain == true) {
		if (heavyrainCounter == 0) {
			cout << "Heavy rains, ends next day" << endl;
		}
		else {
			cout << "Heavy rains. Days remaining: " << heavyrainCounter << endl;
		}
	}
	if (status_heatwave == true) {
		if (heatwaveCounter == 0) {
			cout << "Heatwave, ends next day" << endl;
		}
		else {
			cout << "Heatwave. Days remaining: " << heatwaveCounter << endl;
		}
	}
	if (status_coldsnap == true) {
		if (coldsnapCounter == 0) {
			cout << "Cold snap, ends next day" << endl;
		}
		else {
			cout << "Cold snap. Days remaining: " << coldsnapCounter << endl;
		}
	}
	if (status_buginfest == true) {
		cout << "Bug infestation. You can consume them for fertilizer!" << endl;
	}

	cout << endl;
	for (int i = 0; i < 100; i++) {
		cout << (char)0xC4;
	}
	cout << endl << "Enter any input to continue...";
}

//updates values after input
void Flytrap::NextDay() {
	srand(time(NULL));
	string buff;
	cin >> buff;
	system("CLS");
	if (currentMaturity + 1 == maxMaturity) {
		cout << "Your flytrap has reached maturity, great job!" << endl << endl;
		winToken = true;
		return;
	}
	currentMaturity += 1;
	if (currentWaterLevel - 5 > 0) {
		currentWaterLevel -= 5;
	}
	else {
		currentWaterLevel = 0;
	}
	if (currentWaterLevel >= 26 && currentWaterLevel <= 30) {
		currentEnergyLevel += 1;
	}
	else if (currentWaterLevel >= upperWater) {
		health -= 3;
	}
	else if (currentWaterLevel <= criticalWater) {
		if (currentEnergyLevel - 4 > 0) {
			currentEnergyLevel -= 3;
		}
		else {
			currentEnergyLevel = 0;
		}
	}
	else if (currentWaterLevel <= lowerWater) {
		if (currentEnergyLevel - 2 > 0) {
			currentEnergyLevel -= 2;
		}
		else {
			currentEnergyLevel = 0;
		}
	}
	if (currentFertilizerLevel - 4 > 0) {
		currentFertilizerLevel -= 4;
	}
	else {
		currentFertilizerLevel = 0;
	}
	if (currentFertilizerLevel >= 19 && currentFertilizerLevel <= 22) {
		currentEnergyLevel += 2;
	}
	else if (currentFertilizerLevel >= upperFertilizer) {
		health -= 3;
	}
	else if (currentFertilizerLevel <= criticalFertilizer) {
		if (currentEnergyLevel - 4 > 0) {
			currentEnergyLevel -= 4;
		}
		else {
			currentEnergyLevel = 0;
		}
	}
	else if (currentFertilizerLevel <= lowerFertilizer) {
		if (currentEnergyLevel - 2 > 0) {
			currentEnergyLevel -= 2;
		}
		else {
			currentEnergyLevel = 0;
		}
	}

	if (currentEnergyLevel <= criticalEnergy) {
		health -= 7;
	}
	else if (currentEnergyLevel <= lowerEnergy) {
		health -= 3;
	}

	if (status_drought == true) {
		if (droughtCounter > 0) {
			watering = 3;
			droughtCounter -= 1;
		}
		else if (droughtCounter == 0) {
			watering = 6;
			status_drought = false;
			droughtCounter = rand() % 3 + 1;
		}
	}

	if (status_heavyrain == true) {
		if (heavyrainCounter > 0) {
			currentWaterLevel += 4;
			heavyrainCounter -= 1;
		}
		else if (heavyrainCounter == 0) {
			status_heavyrain = false;
			heavyrainCounter = rand() % 4 + 2;
		}
	}

	if (status_heatwave == true) {
		if (heatwaveCounter > 0) {
			if (currentWaterLevel - 2 > 0) {
				currentWaterLevel -= 2;
			}
			else {
				currentWaterLevel = 0;
			}
			heatwaveCounter -= 1;
		}
		else if (heatwaveCounter == 0) {
			status_heatwave = false;
			heatwaveCounter = rand() % 5 + 1;
		}
	}

	if (status_coldsnap == true) {
		if (coldsnapCounter > 0) {
			health -= 4;
			coldsnapCounter -= 1;
		}
		else if (coldsnapCounter == 0) {
			status_coldsnap = false;
			coldsnapCounter = rand() % 4 + 1;
		}
	}

	if (status_buginfest == true) {
		int temp = rand() % 5 + 1;
		if (temp <= 2) {
			health -= 2;
		}
	}

	int statusRandom;

	//if the event just ended, prepares a new randomized instance for the next time it occurs
	statusRandom = rand() % 20;
	if (statusRandom <= 2 && status_drought != true) { status_drought = true; }
	statusRandom = rand() % 20;
	if (statusRandom <= 3 && status_heavyrain != true) { status_heavyrain = true; }
	statusRandom = rand() % 20;
	if (statusRandom <= 3 && status_heatwave != true) { status_heatwave = true; }
	statusRandom = rand() % 20;
	if (statusRandom <= 3 && status_coldsnap != true) { status_coldsnap = true; }
	statusRandom = rand() % 20;
	if (statusRandom <= 4 && status_buginfest != true) { status_buginfest = true; }
	if (health <= 0) {
		cout << "Your flytrap has perished... better luck next time." << endl << endl;
		loseToken = true;
		return;
	}
}

