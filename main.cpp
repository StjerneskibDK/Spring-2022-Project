// NewGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdlib.h>
#include <string>
#include <windows.h>
#include <fstream>
#include <math.h>
#include "Crop.h"
#include "Cactus.h"
#include "Flytrap.h"

using namespace std;

//simple game details screen, asks for the user to start a new game or load an existing file
void WelcomePrompt() {
	cout << "Welcome to Kaspar's Crop Simulator TM!" << endl << endl;

	cout << "How to play: The objective of the game is simple, guide your plant to maturity before it's health" << endl << "runs out." << endl << endl;
	cout << "There are two variables that you can directly influence, water and fertilizer. Once these values" << endl << "become too low (or high!) your energy levels will decrease." << endl << endl;
	cout << "And when your energy becomes too low, you will begin losing your health; losing if it reaches 0." << endl << endl;

	cout << "There are many different events that influence the game." << endl << endl << "Droughts: Reduce effectiveness of watering" << endl << "Heavy rains : Flood the plant with water" << endl
		<< "Heatwave: Increases water loss per day" << endl << "Cold snap: Deal DIRECT damage to health" << endl << "Bug infestation: Has only a chance to deal damage to health, but lasts until removed" << endl << endl;

	cout << "If you wish to start a new game, input N. To load a saved game input L." << endl << endl;
}

//this is a function that creates an aesthetic loading bar
void loadingBar()
{
	system("color 0F");

	//initialize char for printing
	char a = 177, b = 219;

	cout << "Loading Game...\n\n";

	//print initial loading bar
	for (int i = 0; i < 26; i++)
		printf("%c", a);

	cout << "\r";

	//print loading bar progress
	for (int i = 0; i < 26; i++) {
		printf("%c", b);

		//randomized delayed output
		if (i < 19) {
			int randomTime = rand() % 260 + 30;
			Sleep(randomTime);
		}
		else if (i >= 19 && i <= 23) {
			int randomTime = rand() % 30 + 15;
			Sleep(randomTime);
		}
		else {
			Sleep(.1);
		}
	}
	Sleep(30);
}


int main()
{
	bool restartToken = false;
	do {
		string input;
		int intinput;
		Crop* plant = nullptr;
		ifstream IS;
		WelcomePrompt();
		cin >> input;
		if (input == "L") {
			IS.open("savegame.txt");
			IS >> intinput;
			if (intinput == 1) {
				plant = new Cactus;
			}
			else if (intinput == 0) {
				plant = new Flytrap;
			}
			IS.close();
			plant->LoadGame();
		}
		else if (input == "l") {
			IS.open("savegame.txt");
			IS >> intinput;
			if (intinput == 1) {
				plant = new Cactus;
			}
			else if (intinput == 0) {
				plant = new Flytrap;
			}
			IS.close();
			plant->LoadGame();
		}
		else if (input == "N") {
			system("CLS");
			cout << "Select your plant:" << endl << endl;
			cout << "Input 1 to select Cactus, or input 2 to select the Venus Flytrap." << endl << endl;
			bool badinput = false;
			do {
				cin >> intinput;
				if (intinput == 1) {
					plant = new Cactus;
					badinput = false;
				}
				else if (intinput == 2) {
					plant = new Flytrap;
					badinput = false;
				}
				else {
					cout << "Invalid input, please try again." << endl << endl;
					badinput = true;
				}
			} while (badinput == true);
		}

		else if (input == "n") {
			system("CLS");
			cout << "Select your plant:" << endl << endl;
			cout << "Input 1 to select Cactus, or input 2 to select the Venus Flytrap." << endl << endl;
			bool badinput = false;
			int intinput;
			do {
				cin >> intinput;
				cout << endl;
				if (intinput == 1) {
					plant = new Cactus;
					badinput = false;
				}
				else if (intinput == 2) {
					plant = new Flytrap;
					badinput = false;
				}
				else {
					cout << "Invalid input, please try again." << endl << endl;
					badinput = true;
				}
			} while (badinput == true);
		}
		else {
			system("CLS");
			cout << "Invalid input detected, please restart the game." << endl << endl;
			exit(-1);
		}
		system("CLS");
		loadingBar();
		cin.ignore();
		while (!plant->GetWinToken() && !plant->GetLoseToken()) {
			plant->UserInput(false);
			plant->NextDay();
		}
		delete plant;
		cout << "Would you like to play again? Enter Y for yes, or anything else for no" << endl << endl;
		cin >> input;
		if (input == "Y") {
			restartToken = true;
			system("CLS");
		}
		else if (input == "y") {
			restartToken = true;
			system("CLS");
		}
		else {
			restartToken = false;
		}
	} while (restartToken == true);
	system("CLS");
	return 0;
}