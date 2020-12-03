/*
 * Name: Matt Duggan
 * Date: 11/15/2020 12:00am
 * Description: Header file for the Start object. Classifies all public 
 * and private methods of the object.  
 * 
 * Input Requirements:
 * N/A Refer to Start.cpp file for input requirements for the Start 
 * object and the methods. 
 * 
 * Output:
 * N/A Again refer to the documentation presented in the Start.cpp file. 
 * */

#ifndef START_H
#define START_H
#include "Board.h"
#include <limits>
#include <ctime>


class Start{
	public:
		//default constructor
		Start();
		//prints the contents of the board
		void printTheBoard();
		//Gives the user its first options upon entering the simulation. 
		int opening();
		//Fastforward through a specified number of days. 
		void fastForward(const int days);
		//Displays options upon firing cannons. 
		void nextDay();
		//Fires the cannons and performs tasks presented in opening. 
		void fireCans(const int num);
		//Runs forward a 100 days to randomize initial board. 
		void randomInit();
		//Starts the "UI".
		void start();
		
	private:
		//The amount of days to fast forward. 
		int days;
		//The commmand of which the user would like to continue. 
		int cont;
		//states whether the simulation should quit. 
		bool quit;
		//Starts a board upon creating start. 
		Board W;
		//A check to see if a display has already been displayed. 
		bool alreadyDisplayed;
};

#endif
