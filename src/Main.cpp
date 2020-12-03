/*
 * Name: Matt Duggan
 * Date: 11/15/2020 10:39am
 * Description:   
 * The driver for the Ship simulation. 
 * 
 * Input Requirements:
 *<g++ BlueCannon.cpp BlueShip.cpp Board.cpp Cannon.cpp GreenCannon.cpp GreenShip.cpp Main.cpp Ship.cpp Start.cpp>
 * Requires compilation of the following cpp files. Starts the program start, 
 * and will ask for additional user input. Input requirements for this
 * class can be found in its class input requirements. 
 * 
 * Output:
 * N/A The start class is the only output. Refer to start class output 
 * description for more details. 
 * 
 * */

#include "start.h"

//Creates a new simulation through the UI. 
Start S;

int main(int argc, char **argv)
{
	srand((unsigned int)time(0));
	S.randomInit();
	//S.printTheBoard();
	S.start();
	
	return 0;
}


