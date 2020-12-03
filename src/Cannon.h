/*
 * Name: Matt Duggan
 * Date: 11/15/2020 12:00am
 * Description: Header file for the Cannon object. Classifies all public 
 * and private methods of the object.  
 * 
 * Input Requirements:
 * N/A Refer to Cannon.cpp file for input requirements for the Cannon 
 * object and the methods. 
 * 
 * Output:
 * N/A Again refer to the documentation presented in the Cannon.cpp file. 
 * */

#ifndef CANNON_H
#define CANNON_H
#include <iostream>


class Cannon
{
	public:
		//default constructor
		Cannon();
		//getter for the x location
		int getLocX() const;
		//setter for the x location
		void setLocX(const int x);
		//getter for the y location
		int getLocY() const;
		//setter for the y location
		void setLocY(const int y);
		//getter for the type
		char getType() const;
		//setter for the type
		void setType(const char _type);
		
	protected:
		//location x
		int locX;
		//location y
		int locY;
		//char type, for example 'G' or 'B'
		char type;
};
#endif /* CANNON_CPP */
