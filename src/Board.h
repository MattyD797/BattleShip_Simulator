/*
 * Name: Matt Duggan
 * Date: 11/15/2020 12:00am
 * Description: Header file for the Board object. Classifies all public 
 * and private methods of the object.  
 * 
 * Input Requirements:
 * N/A Refer to Board.cpp file for input requirements for the String 
 * object and the methods. 
 * 
 * Output:
 * N/A Again refer to the documentation presented in the Board.cpp file. 
 * */


#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include "BlueShip.h"
#include "GreenShip.h"
#include "GreenCannon.h"
#include "BlueCannon.h"
#include "World.h"
#include "stdlib.h"


using namespace std;

class Board: public World{
	public:
	//Default constructor
	Board();
	//Returns the day which the simulation is on. 
	int getDay() const;
	//Prints out the contents of grid. 
	void PrintGrid();
	//sets ship in the grid. 
	void initGrid();
	//resets the grid. 
	void clearGrid();
	//Moves to the next day and updates contents of grid. 
	void UpdateGrid();
	//checks the x and y are within bounds of < 9 to fit in grid. 
	bool checkBounds(int,int);
	//Sets the green ships in the grid. 
	void placeGreenShips(GreenShip* green);
	//Sets the blue ships in the grid. 
	void placeBlueShips(BlueShip* blue);
	//Checks each ship and compares whether they are in the same location. 
	void checkShips(Ship* ship);
	//Bubble sorts the ships based on coordinates. 
	void sortShips(Ship* ship);
	//Moves the ships in the grid by one square and updates the grid. 
	void nextMove();
	//Displays a next day header. 
	void printNextDayHeader() const;
	//Edits the health of a ship based off current health. 
	void editHealth(Ship* ship);
	//Displays a Fire transition header. 
	void transition() const;
	//Moves a ship by one grid. 
	void moveShips(Ship* ship);
	// Checks to see how many ships are sunk. 
	void checkIfSunk(Ship* ship) const;
	//reset the status of all ships to null. 
	void resetStatus(Ship* ship) const;
	//Fires cannons at the opposing side. 
	void fire();
	//checks if blue is against a side. 
	void checkBlueHitWall() const;
	//checks if green is against a side.
	void checkGreenHitWall() const;
	//Chooses new green cannon locations. 
	void moveGreenCannons();
	//Chooses new blue cannon locations. 
	void moveBlueCannons();
	//Determines the health taken from each ship based on where cannons hit. 
	void fireCannons(Cannon* cannon, const int num, Ship* ship);
	//Displays the health of the green ships. 
	void printGreenHealth();
	//Displays the health of the blue ships. 
	void printBlueHealth();
	//Checks whether a ship is too weak to carry on < 10%. 
	void checkStatus(Ship* ship, const int num);
	//Ends the program and calls for memory deallocation. 
	void terminate();
	//Checks to see if both sides have at elast one ship. 
	bool checkTerminate();
	//Calculates the number of ships on eah side. 
	const int checkQuit(Ship* ship) const;
	//Displays the blue ships that sank and the number of ships sunk. 
	void displayBlueSunkenShips() const;
	//Displays the green ships that sank and the number of ships sunk. 
	void displayGreenSunkenShips() const;
	//Deallocates all cannon and ship array from memory. 
	void DeleteShipsAndCannons();
	//Checks to see if ships need to be restocked.
	void checkGreenRestock();
	//Checks to see if ships need to be restocked. 
	void checkBlueRestock();
	//randomizes the intial ship location
	void randInit();
	
	private:
		//amount of rows in the grid. 
		const int rows = sizeof grid / sizeof grid[0];
		//amount of cols in the grid. 
		const int cols = sizeof grid[0] / sizeof(char);
		//Number of ships on each team. 
		static const int NUMBEROFSHIPS = 5;
		//Array of green ships. 
		GreenShip* Green;
		//Array of blue ships. 
		BlueShip* Blue;
		//Array of green cannons. 
		GreenCannon* greenCan;
		//Array of blue cannons. 
		BlueCannon* blueCan;
		//Determines if ships have be set or not. 
		bool didSetShips;
		//Determines if memory has been deallocated. 
		bool deallocated;
};
#endif
