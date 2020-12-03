/*
 * Name: Matt Duggan
 * Date: 11/15/2020 12:00am
 * Description: Header file for the GreenShip object. Classifies all public 
 * and private methods of the object.  
 * 
 * Input Requirements:
 * N/A Refer to GreenShip.cpp file for input requirements for the GreenShip 
 * object and the methods. 
 * 
 * Output:
 * N/A Again refer to the documentation presented in the GreenShip.cpp file. 
 * */

#ifndef GREENSHIP_CPP
#define GREENSHIP_CPP

#include "Ship.h"

class GreenShip : public Ship{
	public:
		//Default constructor. 
		GreenShip();
		//Looks to see if two ships are next to each other. 
		bool operator==(GreenShip&) const;
		//Removes health if ship hits side. 
		void operator --();
};
#endif
