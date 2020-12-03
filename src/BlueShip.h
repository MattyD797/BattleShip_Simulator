/*
 * Name: Matt Duggan
 * Date: 11/15/2020 12:00am
 * Description: Header file for the BlueShip object. Classifies all public 
 * and private methods of the object.  
 * 
 * Input Requirements:
 * N/A Refer to BlueShip.cpp file for input requirements for the BlueShip 
 * object and the methods. 
 * 
 * Output:
 * N/A Again refer to the documentation presented in the BlueShip.cpp file. 
 * */

#ifndef BLUESHIP_CPP
#define BLUESHIP_CPP

#include "Ship.h"

class BlueShip : public Ship{
	public:
		//default constructor
		BlueShip();
		//Overloads the + operator to determine if the two ships can heal each other. 
		bool operator==(BlueShip&) const;
		//Reduces of ship whos location is on the side of the map. 
		void operator --();
};
#endif
