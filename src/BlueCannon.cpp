/*
 * Name: Matt Duggan
 * Date: 11/15/2020 12:00am
 * 
 * Description: 
 * 
 * This is an child class of Cannon and is currently only a default constructor. 
 * It would be cool to add decorators, like in mario to have different types
 * of weapons. Future note.  
 * 
 * Input Requirements:
 * 
 * N/A Must call Blue cannon constructor. 
 * 
 * Output:
 * 
 *	N/A A character O will be displayed in the grid. 
 *   
 * */

#include "BlueCannon.h"

BlueCannon::BlueCannon()
{
	locY += 5;
	type = 'O';
}
