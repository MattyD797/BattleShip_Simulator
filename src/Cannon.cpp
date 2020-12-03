/*
 * Name: Matt Duggan
 * Date: 11/15/2020 12:00am
 * 
 * Description: 
 * 
 * This is an parent class of Blue and Green Cannon.  
 * Cannon has getters and setters to manipulate its contents and change the 
 * locations for each sides cannons. They act independently from the ships 
 * currently. So the location of the ships do not affect the locations of the cannons. 
 * Cannons may also hit anywhere, even teh same locations. Only one cannon 
 * is fired for every ship still floating. 
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

#include "Cannon.h"

/*
 * Default constructor for a cannon. Sets the location. 
 * */
Cannon::Cannon()
{
	int x = rand() % 10;
	setLocX(x);
	int y = rand() % 5;
	setLocY(y);
}
/*
 * returns the x location of a cannon. 
 * */
int Cannon::getLocX() const
{
	return locX;
}

/*
 * sets the x location of a cannon.
 * */
void Cannon::setLocX(const int x)
{
	locX = x;
}

/*
 * returns the y location of the cannon.
 * */
int Cannon::getLocY() const
{
	return locY;
}

/*
 * sets the y location of a cannon.
 * */
void Cannon::setLocY(const int y)
{
	locY = y;
}

/*
 * return the char type of the cannon. 
 * */
char Cannon::getType() const
{
	return type;
}

/*
 * sets the char type of the cannon. 
 * */
void Cannon::setType(const char _type)
{
	type = _type;
}




