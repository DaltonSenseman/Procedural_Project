/**
*	COP-2001 Procedural Project
*	main.cpp
*	Purpose: To create a inventory management system for OraclProduction Ltd. That allows for users to be create accounts and manage inventory. 
*
*	@author Dalton Senseman
*	@version 0.0 5/16/2019
*/

#include "pch.h"
#include <iostream>

using namespace std;

int main() {

	bool mainMenuChoice = false;
	int mainMenuUserSelcection;

	do {

		cout << " ______________________________________ " << endl;
		cout << "|       Production Line Tracker        |" << endl;
		cout << "|                                      |" << endl;
		cout << "|    1. Add Employee Account           |" << endl;
		cout << "|    2. Add Music Player               |" << endl;
		cout << "|    3. Add Movie Player               |" << endl;
		cout << "|    4. Display Production Statistics  |" << endl;
		cout << "|    5. Exit                           |" << endl;
		cout << "|______________________________________|" << endl;
		cout << "     Enter your selection: " << flush;
		cin >> mainMenuUserSelcection;
		cout << " " << endl;

		switch (mainMenuUserSelcection) { //main menu switch to select one of the 5 options above. 
		case 1: cout << "Selection 1: Accounts" << endl;
			break;
		case 2: cout << "Selection 2: Music players" << endl;
			break;
		case 3: cout << "Selection 3: Movie players" << endl;
			break;
		case 4: cout << "Selection 4: Production stats" << endl;
			break;
		case 5: cout << "Selection Exit" << endl;
			exit(0); //program is terminated
			break;
		default: cout << "Unexpected error has occured in menu selection, choose an option from 1-5 on the menu screen\nThen press the numerical choice on your keyboard and hit enter." << endl;
		}
	} while (mainMenuChoice == false);
	
	return 0;
}
