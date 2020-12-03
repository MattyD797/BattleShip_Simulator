/*
 * Name: Matt Duggan
 * Date: 11/15/2020 12:00am
 * Description: Header file for the Ship object. Classifies all public 
 * and private methods of the object.  
 * 
 * Input Requirements:
 * N/A Refer to Ship.cpp file for input requirements for the Ship 
 * object and the methods. 
 * 
 * Output:
 * N/A Again refer to the documentation presented in the Ship.cpp file. 
 * */

#ifndef SHIP_H
#define SHIP_H
#include <iostream>
#include <string>
#include "World.h"
#include "time.h"

using namespace std;

class Ship{
	public:
		//default constructor
		Ship();
		//getter for locx
		int getLocX() const;
		//setter for locx
		void setLocX(const int x);
		//getter for previous location x. 
		int getPrevLocX() const;
		//setter for previous location x. 
		void setPrevLocX(const int x);
		//getter for location y. 
		int getLocY() const;
		//setter for location y. 
		void setLocY(const int y);
		//getter for previous location y. 
		int getPrevLocY() const;
		//setter for previous location y. 
		void setPrevLocY(const int y);
		//getter for color. 
		char getColor() const;
		//getter for health. 
		float getHealth() const;
		//setter for health. 
		void setHealth(const double _health);
		//getter for the string that represents the status of the ship. 
		string getStatus() const;
		//setter for the status. 
		void setStatus(const string _status);
		//returns whether a ship has been restoked. 
		bool getRestock() const;
		//sets the new restock
		void setRestock(const bool _restock);
		//finds next x for new day. 
		void nextShipXMove();
		//finds next y for new day. 
		void nextShipYMove();
		//generates a health bar
		string healthBar();
		//sets parameters of a sunken ship. 
		void sunk();
		
	protected: 
		//previous location x
		int prevLocX;
		//previous location y
		int prevLocY;
		//location x
		int locX;
		//location y
		int locY;
		//character representing ship. 
		char color;
		//health of the ship 0-100
		double health;
		//current status of the ships well being. 
		string status;
		//
		bool restock;
};

#endif /* SHIP_CPP */
