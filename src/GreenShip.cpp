/*
 * Name: Matt Duggan
 * Date: 11/15/2020 12:00am
 * 
 * Description: 
 * 
 * This is an child class of Ship and is currently only a default constructor. 
 * Again, addition of different kinds of ships, such as battle ships may
 * be a place for current expansion to this program.   
 * 
 * Input Requirements:
 * 
 * N/A Must call Green ship constructor. 
 * 
 * Output:
 * 
 *	N/A A character G will be displayed in the grid. 
 *   
 * */

#include "GreenShip.h"

/*
 * Default constructor for a green ship. Sets the char type to G and 
 * the health to 100. 
 * */
GreenShip::GreenShip()
{
	color = 'G';
	setHealth(100);
}	

/*
 * Overload operator for == with two greenships to see if they are next to each other.
 * */
bool GreenShip::operator ==(GreenShip& greenship) const
{	
	int diffInX = locX - greenship.getLocX();
	int diffInY = locY - greenship.getLocY();
	
	if(diffInY == -1 && diffInX == 0 && locY != 4)
	{
		return true;
	}
	else if(diffInY == 1 && diffInX == 0 && locY != 0)
	{
		return true;
	}
	else if(diffInY == 0 && diffInX == -1 && locX != 9)
	{
		return true;
	}
	else if(diffInY == 0 && diffInX == 1 && locX != 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
/*
 * Overloaded operator to make ship lose health if on the side of the map. 
 * */
void GreenShip::operator --()
{
	if(locY == 0 || locY == 4)
	{
		setHealth(getHealth() - (getHealth() * 0.1));
		if(health < 0)
		{
			health == 0;
		}
		if(status == " ")
		{
			status = status + "Hit the top/bottom wall";
		}
		else if(status != "SUNK")
		{
			status = status + ", Hit the top/bottom wall";
		}
	}
	if(locX == 0 || locX == 9)
	{
		setHealth(getHealth() - (getHealth() * 0.1));
		if(health < 0)
		{
			health == 0;
		}
		if(status == " ")
		{
			status = status + "Hit the side wall";
		}
		else if(status != "SUNK")
		{
			status = status + ", Hit the side wall";
		}
	}
}


