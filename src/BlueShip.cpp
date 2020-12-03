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
 * N/A Must call Blue ship constructor. 
 * 
 * Output:
 * 
 *	N/A A character B will be displayed in the grid. 
 *   
 * */

#include "BlueShip.h"

/*
 * Default Constructor of blue. Sets the characters to B and keps blue on the 
 * bottom of the grid. 
 * */
BlueShip::BlueShip()
{
	locY += 5;
	color = 'B';
	setHealth(100);
}

/*
 * Overload operator for == with two blueships to see if tehy are next to each other.
 * */
bool BlueShip::operator ==(BlueShip& blueship) const
{	
	int diffInX = locX - blueship.getLocX();
	int diffInY = locY - blueship.getLocY();
	
	if(diffInY == -1 && diffInX == 0 && locY != 9)
	{
		return true;
	}
	else if(diffInY == 1 && diffInX == 0 && locY != 5)
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
 * Overload operator for == with two greenships to see if they are next to each other.
 * */
void BlueShip::operator --()
{
	if(locY == 5 || locY == 9)
	{
		setHealth(getHealth() - (getHealth() * 0.1));
		if(health < 0)
		{
			health == 0;
		}
		if(status == " " )
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



