/*
 * Name: Matt Duggan
 * Date: 11/15/2020 12:00am
 * 
 * Description: 
 * 
 * This is an parent class of Blue and Green Ship.  
 * Ship has getters and setters to manipulate its contents and change the 
 * locations for each ship. Ships are not allowed to be in the same location
 * and are randomely set on their side of the board. Each side is made up 
 * of 50 squares.    
 * 
 * Input Requirements:
 * 
 * N/A Cannon needs a child class to be constructed in order to 
 * display character. Otherwise, char is null. 
 * 
 * Output:
 * 
 *	N/A 
 *   
 * */

#include "Ship.h"

/*
 * Default constructor of the type ship. Set the x and y location randomely
 * between 0-10 for x and 0-5 for y. Also stores a previous location to go back to
 * previous point. Sets the status to nothing and health to 100. 
 * */
Ship::Ship()
{
	int x = rand() % 10;
	setLocX(x);
	int y = rand() % 5;
	setLocY(y);
	int prevX = 0;
	setPrevLocX(prevX);
	int prevY = 0;
	setPrevLocY(prevY);
	setHealth(100);
	setStatus(" ");
	setRestock(false);
}

//Returns the location of x. 
int Ship::getLocX() const
{
	return locX;
}

//Sets the location of x to int x. 
void Ship::setLocX(const int x)
{
	locX = x;
}

//Gets the locations of previous x. 
int Ship::getPrevLocX() const
{
	return prevLocX;
}

//Sets the location of previous x. 
void Ship::setPrevLocX(const int x)
{
	prevLocX = x;
}

//returns the location of y. 
int Ship::getLocY() const
{
	return locY;
}

//Sets the location of y. 
void Ship::setLocY(const int y)
{
	locY = y;
}

//returns the previous location of y. 
int Ship::getPrevLocY() const
{
	return prevLocY;
}

//Sets the previous location of y. 
void Ship::setPrevLocY(const int y)
{
	prevLocY = y;
}

//Returns the character or color of the ship. 
char Ship::getColor() const
{
	return color;
}

//returns the health of a ship. 
float Ship::getHealth() const
{
	return health;
}

//sets the health of the ship. 
void Ship::setHealth(const double _health)
{
	health = _health;
}

//returns the status of the ship. 
string Ship::getStatus() const
{
	return status;
}

//Sets the status of the ship. 
void Ship::setStatus(const string _status)
{
	
	status =_status;
}

bool Ship::getRestock() const
{
	return restock;
}

void Ship::setRestock(const bool _restock)
{
	restock = _restock;
}

/*
 * returns the new x of a ship for the next day. X can be subtracted 
 * add by one or remain the same. 
 * */
void Ship::nextShipXMove()
{
int move = rand() % 3;
	switch(move){
		case 0:
			prevLocX = getLocX();
			if(locX != 9)
			{
				setLocX(locX+=1);
			}
			break;
		case 1:
			prevLocX = getLocX();
			if(locX != 0)
			{
				setLocX(locX-=1);
			}
			break;
		case 2:
			break;
		default: 
			cout << "Invalid move" << endl;
	}

}

/*
 * returns the new y of a ship for the next day. Y can be subtracted 
 * add by one or remain the same. 
 * */
void Ship::nextShipYMove()
{
int move = rand() % 3;
	switch(move){
		case 0:
			prevLocY = getLocY();
			if(locY != 9 && locY != 4)
			{
				setLocY(locY+=1);
			}
			break;
		case 1:
			prevLocY = getLocY();
			if(locY != 0 && locY != 5)
			{
				setLocY(locY-=1);
			}
			break;
		case 2:
			break;
		default: 
			cout << "Invalid move" << endl;
	}

}

/*
 * Makes a string that represents a health bar based off the health of the 
 * ship.
 * */
string Ship::healthBar()
{
	string barOfHealth = "[";
	int bar = (int)health/5; 
	for(int i =0; i<bar; i++)
	{
		barOfHealth += "=";
	}
	barOfHealth += "]";
	return barOfHealth;
}

/*
 * Sets all the parameters of a sunken ship. 
 * */
void Ship::sunk()
{
	color = ' ';
	health = 0;
	status = "SUNK";
}


