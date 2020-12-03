/*
 * Name: Matt Duggan
 * Date: 11/15/2020 12:00am
 * 
 * Description: 
 * 
 * Simulation of a play off of battle ship. Each team has 
 * five ships to start off with. Every day ships can fire a cannon at the 
 * opposing side. When the last ship is sunk or at the end of 25 days 
 * We determine a winner by the most ships standing. 
 * 
 * Input Requirements:
 * 
 * After running the execution file, you will be prompted on whether you
 * would like to fire the cannons, fast forward an x number of days, or
 * end the simulation where you are. You can choose based off the respective
 * number 1,2,3. 
 * 
 * Output:
 * 
 * A simulation of battle ship. This is a ten by ten grid with a UI
 * asking the user for an appropriate action of what to do next.  
 * */

#include "Board.h"

/*
 * default constructor. Sets day equal to 0 and sets grid to ' '.
 * */
Board::Board()
{
	Green = new GreenShip[NUMBEROFSHIPS];
	Blue = new BlueShip[NUMBEROFSHIPS];
	greenCan = new GreenCannon[NUMBEROFSHIPS];
	blueCan = new BlueCannon[NUMBEROFSHIPS];
	day = 0;
	didSetShips = false;
	UpdateGrid();
	deallocated =false;
}

/*
 * Looks to see if the x and y locations of the ships are within range
 * of the grid. Ensures no out of bounds exceptions. 
 * */
bool Board::checkBounds(int x, int y)
{
	if(x > 9 || x < 0)
	{
		cout << "INVALID X: OUT OF BOUNDS" << endl;
		return false;
	}
	if(y > 9 || y < 0)
	{
		cout << "INVALID Y: OUT OF BOUNDS" << endl;
		return false;
	}
	return false;
}

/*
 * Returns the day the board is on. How many times the cannons have 
 * fired plus 1. 
 * */	
int Board::getDay() const
{
	return day;
}

/*
 * Prints out the standard format of the map along with the contents
 * of the grid. 
 * */
void Board::PrintGrid()
{
	cout << endl << "       1   2   3   4   5   6   7   8   9  10 " << endl;
	for(int i = 0; i < rows; i++)
	{
		if(i == rows/2)
		{
			cout << "     =========================================" << endl << endl;
			cout << "     ~~~~~~~~~~~~~~~~~ DAY: " << day + 1 << " ~~~~~~~~~~~~~~~~" << endl;  
			cout << endl << "     =========================================" << endl;
		}
		else
		{
			cout << "      ---+---+---+---+---+---+---+---+---+--- " << endl;
		}
		if(i<9)
		{
			cout << "  " << i + 1 << "  ";
		}
		else
		{
			cout << " " << i + 1 << "  ";
		}
		for(int j = 0; j < cols;j++)
		{
			cout <<"| " << grid[i][j] << " ";
		}
		cout << "|" << endl;
	}
	cout << "      ---+---+---+---+---+---+---+---+---+--- " << endl << endl;
}

/*
 * Initializes the grid for the following day. Places each teams ship 
 * by randomely choosing to move x or y by one or not. Remaining grid 
 * coordinates are reset back to ' '.  
 * */
void Board::initGrid()
{
	
	placeBlueShips(Blue);

	placeGreenShips(Green);
	
	for(int i = 0; i < rows; i++)
	{
		for(int j = 0; j < cols;j++)
		{
			if(grid[i][j] == ' ')
			grid[i][j] = ' ';
		}
	}
}

/*
 * Resets the entire 2D array back to ' '. 
 * */
void Board::UpdateGrid()
{
	for(int i = 0; i < rows; i++)
	{
		for(int j = 0; j < cols;j++)
		{
			grid[i][j] = ' ';
		}
	}
}

/*
 * Replaces the coordinates of the newly placed green ship with the char
 * representing that teams ship 'G'. Checks ships to make sure they are not 
 * equal.
 * */
void Board::placeGreenShips(GreenShip* green) 
{
	checkShips(green);
	
	for(int i = 0; i < NUMBEROFSHIPS; i++)
	{
		grid[green[i].getLocY()][green[i].getLocX()] = green[i].getColor();
	}
}

/*
 * Replaces the coordinates of the newly placed blue ship with the char
 * representing that teams ship 'B'. Checks ships to make sure they are not 
 * equal.
 * */
void Board::placeBlueShips(BlueShip* blue)
{
	checkShips(blue);
	
	for(int i = 0; i < NUMBEROFSHIPS; i++)
	{
		grid[blue[i].getLocY()][blue[i].getLocX()] = blue[i].getColor();
	}
}

/*
 * Checks to see if two ships are equal. If they are then a new coordinate
 * is randomely chosen. The list of ships is then bubble sorted to 
 * check for any duplicate coordinates. 
 * */
void Board::checkShips(Ship* ship)
{	
	int mainCount;
	while(true)
	{
		mainCount = 0;
		sortShips(ship);
		int count;
		while(true)
		{
			count = 0;
			for(int i = 0; i < NUMBEROFSHIPS - 1; i++)
			{
				if(ship[i].getLocX() == ship[i+1].getLocX() && ship[i].getLocY() == ship[i+1].getLocY() && !didSetShips)
				{
					if(ship[i].getLocY() < 5)
					{
						ship[i].setLocX(rand() % 10);
						ship[i].setLocY((rand() % 5));
						count++;
					}
					else
					{
						ship[i].setLocX(rand() % 10);
						ship[i].setLocY((rand() % 5)+ 5);
						count++;
						mainCount++;
					}
				}
				else if(ship[i].getLocX() == ship[i+1].getLocX() && ship[i].getLocY() == ship[i+1].getLocY() && didSetShips)
				{
					int prevX = ship[i].getPrevLocX();
					ship[i].setLocX(prevX);
					int prevY = ship[i].getPrevLocY();
					ship[i].setLocY(prevY);
				}
			}
			if(count == 0)
			{
				break;
			}
		}
		if(mainCount == 0)
		{
			break;
		}
	}
	didSetShips == true;
}

/*
 * Bubble sorts a dynamic array of ships first by their x values. Once the 
 * x values are sorted, we check for duplicate x values. These dublicates are 
 * sorted based on their y values to ensure no two ships can be in one square at 
 * one time. 
 * */
void Board::sortShips(Ship* ship)
{

	int count;
	int tempX;
	int tempY;
	
	while(true)
	{
		count = 0;
		for(int i = 0; i < NUMBEROFSHIPS - 1; i++)
		{
			if(ship[i].getLocX() > ship[i+1].getLocX())
			{
				tempX = ship[i].getLocX();
				ship[i].setLocX(ship[i+1].getLocX());
				ship[i+1].setLocX(tempX);
				
				tempY = ship[i].getLocY();
				ship[i].setLocY(ship[i+1].getLocY());
				ship[i+1].setLocY(tempY);
				count++;
			}
		}
		if(count==0)
		{
			break;
		}
	}
	while(true)
	{
		count = 0;
		for(int i = 0; i < NUMBEROFSHIPS - 1; i++)
		{
			if(ship[i].getLocY() > ship[i+1].getLocY() && ship[i].getLocX() == ship[i+1].getLocX())
			{
				int tempY = ship[i].getLocY();
				ship[i].setLocY(ship[i+1].getLocY());
				ship[i+1].setLocY(tempY);
				count++;
			}
		}
		if(count==0)
		{
			break;
		}
	}
}

/*
 * Moves ships to new location. A ship can only move one square 
 * every day. The day increases by one with every ship movement. 
 * */	
void Board::nextMove()
{
	moveShips(Blue);
	moveShips(Green);

	day++;
}

/*
 * Moves the ship 100 times to randomize board. 
 * */
void Board::randInit()
{
	moveShips(Blue);
	moveShips(Green);
}

/*
 * Simple display header to show that it is the next day. 
 * */
void Board::printNextDayHeader() const
{
	cout << endl << "               ||||||||||||||||||" << endl;
	cout << "               |||| NEXT DAY ||||"<<endl ;
	cout << "               ||||||||||||||||||" << endl<< endl;
}

/*
 * A ships health with automatically decrease by ten percent every day below 
 * 50% by 10%. Any ship that has greater than 50% health will gain 5% 
 * since ships have time to repair minor damage. 
 * */
void Board::editHealth(Ship* ship)
{
	for(int i = 0; i < NUMBEROFSHIPS; i++)
	{	
	
	//~ for(int i = NUMBEROFSHIPS; i > 1; i--)
	//~ {
		//~ newHealth = Blue[i] + Blue[i-1];
		//~ Blue[i-1].setHealth(newHealth);
	//~ }
		
		if(ship[i].getHealth() < 50)
		{
			ship[i].setHealth(ship[i].getHealth() - (ship[i].getHealth() * 0.1));
		}
		if(ship[i].getHealth() > 50 && ship[i].getHealth() != 100)
		{
			ship[i].setHealth(ship[i].getHealth() + (ship[i].getHealth() * 0.05));
			if(ship[i].getHealth()>100)
			{
				ship[i].setHealth(100);
			}
		}
	}
}

/*
 * Simple display showing that the ships have fired cannons. 
 * */
void Board::transition() const
{
	cout << endl << "               ||||||||||||||||||" << endl;
	cout << "               |||||| FIRE ||||||"<<endl ;
	cout << "               ||||||||||||||||||" << endl<< endl;
}

/*
 * Moves the X and Y locations of the ship. Checks to ensure that no two ships
 * are in the same location, if they are one ships stays where it is. 
 * The status of the ships are renewed and we initialize a new grid with 
 * the new ship locations. 
 * */
void Board::moveShips(Ship* ship)
{
	for(int i = 0; i < NUMBEROFSHIPS; i++)
	{
		ship[i].nextShipXMove();
		ship[i].nextShipYMove();
	}
	checkShips(ship);
	UpdateGrid();
	resetStatus(Green);
	resetStatus(Blue);
	
	checkIfSunk(Green);
	checkIfSunk(Blue);
	initGrid();
}

/*
 * This looks through every ship and will sink the ship if below 10% health. 
 * */
void Board::checkIfSunk(Ship* ship) const
{
	for(int i = 0; i < NUMBEROFSHIPS; i++)
	{
		if(ship[i].getHealth() < 10)
		{
			ship[i].sunk();
		}
	}
	
}

/*
 * Resets the status of the ships. For everyday tehy reset to get the 
 * new display of where a ship was hit. 
 * */
void Board::resetStatus(Ship* ship) const
{
	for(int i =0; i<NUMBEROFSHIPS; i++)
	{
		ship[i].setStatus(" ");
	}
}

/*
 * Fires cannons on opposing sides of the board. The number of cannons
 * is determined by the amount of ships on each side. 1 ship = 1 cannon. 
 * Edits the health of the ship with the new health after firing the cannons. 
 * */
void Board::fire()
{
	moveBlueCannons();
	moveGreenCannons();
	int numBlueShips = checkQuit(Blue);
	int numGreenShips = checkQuit(Green);
	
	fireCannons(blueCan, numBlueShips, Blue);
	
	fireCannons(greenCan, numGreenShips, Green);
	
	checkBlueRestock();
	checkGreenRestock();
	
	checkBlueHitWall();
	checkGreenHitWall();
	
	editHealth(Blue);
	editHealth(Green);
}
/*
 * Checks to see if the blue ship is on the sides of the map. 
 * */
void Board::checkBlueHitWall() const
{
	for(int i = 0; i < NUMBEROFSHIPS; i++)
	{
		--Blue[i];
	}
}
/*
 * Checks to see if the green ship is on the sides of the map. 
 * */
void Board::checkGreenHitWall() const
{
	for(int i = 0; i < NUMBEROFSHIPS; i++)
	{
		--Green[i];
	}
}

void Board::checkGreenRestock()
{
	for(int i = 0; i < NUMBEROFSHIPS; i++)
	{	
		for(int j = 0; j <NUMBEROFSHIPS; j++)
		{
			//cout<<"Are the next to Each other I: " << i << " and J: " << j << " " << (Blue[i] == Blue[j]) <<endl;
			if (Green[i] == Green[j] && i != j)
			{
				if(Green[j].getHealth() < Green[i].getHealth() && Green[j].getRestock() == false)
				{
					
					Green[j].setHealth(Green[j].getHealth() + (Green[j].getHealth() * 0.5));
					if(Green[j].getHealth() > 100)
					{
						Green[j].setHealth(100);
					}
					if(Green[j].getStatus() == " ")
					{
						Green[j].setStatus(Green[j].getStatus()+"Ration Restock from Ship " + to_string(i + 1));
					}
					else
					{
						Green[j].setStatus(Green[j].getStatus()+", Ration Restock from Ship " + to_string(i + 1));
					}
					Green[j].setRestock(true);
				}
				else
				{
					if(Green[i].getRestock() == false && Green[j].getRestock() == false)
					{
						Green[i].setHealth(Green[i].getHealth() + (Green[i].getHealth() * 0.5));
						if(Green[i].getHealth() > 100)
						{
							Green[i].setHealth(100);
						}
						if(Green[i].getStatus() == " ")
						{
							Green[i].setStatus(Green[i].getStatus()+"Ration Restock from Ship " + to_string(j + 1));
						}
						else
						{
							Green[i].setStatus(Green[i].getStatus()+", Ration Restock from Ship " + to_string(j + 1));
						}
						Green[i].setRestock(true);
					}
				}
			}
		}
	}
}

void Board::checkBlueRestock()
{
	for(int i = 0; i < NUMBEROFSHIPS; i++)
	{	
		for(int j = 0; j <NUMBEROFSHIPS; j++)
		{
			//cout<<"Are the next to Each other I: " << i << " and J: " << j << " " << (Blue[i] == Blue[j]) <<endl;
			if (Blue[i] == Blue[j] && i != j)
			{
				if(Blue[j].getHealth() < Blue[i].getHealth() && Blue[j].getRestock() == false)
				{
					
					Blue[j].setHealth(Blue[j].getHealth() + (Blue[j].getHealth() * 0.5));
					if(Blue[j].getHealth() > 100)
					{
						Blue[j].setHealth(100);
					}
					if(Blue[j].getStatus() == " ")
					{
						Blue[j].setStatus(Blue[j].getStatus()+"Ration Restock from Ship " + to_string(i + 1));
					}
					else
					{
						Blue[j].setStatus(Blue[j].getStatus()+", Ration Restock from Ship " + to_string(i + 1));
					}
					Blue[j].setRestock(true);
				}
				else
				{
					if(Blue[i].getRestock() == false && Blue[j].getRestock() == false)
					{
						Blue[i].setHealth(Blue[i].getHealth() + (Blue[i].getHealth() * 0.5));
						if(Blue[i].getHealth() > 100)
						{
							Blue[i].setHealth(100);
						}
						if(Blue[i].getStatus() == " ")
						{
							Blue[i].setStatus(Blue[i].getStatus()+"Ration Restock from Ship " + to_string(j + 1));
						}
						else
						{
							Blue[i].setStatus(Blue[i].getStatus()+", Ration Restock from Ship " + to_string(j + 1));
						}
						Blue[i].setRestock(true);
					}
				}
			}
		}
	}
}

/*
 * Sets new cannon locations on the green side of the grid. 
 * */
void Board::moveGreenCannons()
{
	int numGreenShips = checkQuit(Green);
	for(int i = 0; i < numGreenShips; i++)
	{
		greenCan[i].setLocX(rand() % 10);
		greenCan[i].setLocY(rand() % 5);
	}
}

/*
 * Sets new cannon locations on the blue side of the grid. 
 * */
void Board::moveBlueCannons()
{
	int numBlueShips = checkQuit(Blue);
	for(int i = 0; i < numBlueShips; i++)
	{
		blueCan[i].setLocX(rand() % 10);
		blueCan[i].setLocY((rand() % 5) + 5);
	}
}

/*
 * Fires the cannon and makes a three by three grid around each cannon location.
 * If a ship is in this grid different amounts of health 
 * are taken off and where the ship gets hit will be displayed
 * in the status after cannons are fired. 
 * */
void Board::fireCannons(Cannon* cannon, const int num, Ship* ship)
{
	
	// For each cannon we need to check the coords at the cannon and around it for a hit
	for(int i = 0; i < num; i++)
	{
		//If the cannon is is at a spot that is empty or has its type (a X or O) then it will make that spot its type
		if(grid[cannon[i].getLocY()][cannon[i].getLocX()] == ' ')
		{
			grid[cannon[i].getLocY()][cannon[i].getLocX()] = cannon[i].getType();
		}
		//If a cannon lands where a color is, this is a direct hit. -40% of health. 
		else if(grid[cannon[i].getLocY()][cannon[i].getLocX()] == ship[i].getColor())
		{
			grid[cannon[i].getLocY()][cannon[i].getLocX()] = 'H';
			ship[i].setHealth(ship[i].getHealth() - (ship[i].getHealth() * 0.4));
			
			if(ship[i].getStatus() != " ")
			{
				ship[i].setStatus(ship[i].getStatus() + ", ");
			}
			ship[i].setStatus(ship[i].getStatus() + "Critical Hit!");
		}
		
		//If the cannon is at a spot that is empty or has its type (a X or O) then it will make that spot its type
		if(cannon[i].getLocY() != 9 && cannon[i].getLocY() != 4 && cannon[i].getLocX() != 9)
		{
			if(grid[cannon[i].getLocY() + 1][cannon[i].getLocX() + 1] == ' ' || grid[cannon[i].getLocY() + 1][cannon[i].getLocX() + 1] == cannon[i].getType())
			{
				grid[cannon[i].getLocY() + 1][cannon[i].getLocX() + 1] = cannon[i].getType();
			}
			/*
			 * XXX
			 * XXX  H -> place where ship is. 
			 * XXH
			 * */
			else if(grid[cannon[i].getLocY() + 1][cannon[i].getLocX() + 1] == ship[i].getColor())
			{
				grid[cannon[i].getLocY() + 1][cannon[i].getLocX() + 1] = 'H';
				ship[i].setHealth(ship[i].getHealth() - (ship[i].getHealth() * 0.1));
				
				if(ship[i].getStatus() != " ")
				{
					ship[i].setStatus(ship[i].getStatus() + ", ");
				}
				
				ship[i].setStatus(ship[i].getStatus() + "Hit on the Portside Bow");
			}
		}
		//If the cannon is at a spot that is empty or has its type (a X or O) then it will make that spot its type
		if(cannon[i].getLocY() != 9 && cannon[i].getLocY() != 4)
		{
			if(grid[cannon[i].getLocY() + 1][cannon[i].getLocX()] == ' ')
			{
				grid[cannon[i].getLocY() + 1][cannon[i].getLocX()] = cannon[i].getType();
			}
			/*
			 * XXX
			 * XXX  H -> place where ship is. 
			 * XHX
			 * */
			else if(grid[cannon[i].getLocY() + 1][cannon[i].getLocX()] == ship[i].getColor())
			{
				grid[cannon[i].getLocY() + 1][cannon[i].getLocX()] = 'H';
				ship[i].setHealth(ship[i].getHealth() - (ship[i].getHealth() * 0.25));

				if(ship[i].getStatus() != " ")
				{
					ship[i].setStatus(ship[i].getStatus() + ", ");
				}
				
				ship[i].setStatus(ship[i].getStatus() + "Hit on the Bow");
			}
		}
		//If the cannon is at a spot that is empty or has its type (a X or O) then it will make that spot its type
		if(cannon[i].getLocY() != 9 && cannon[i].getLocY() != 4 && cannon[i].getLocX() != 0)
		{
			if(grid[cannon[i].getLocY() + 1][cannon[i].getLocX() - 1] == ' ')
			{
				grid[cannon[i].getLocY() + 1][cannon[i].getLocX() - 1] = cannon[i].getType();
			}
			/*
			 * XXX
			 * XXX  H -> place where ship is. 
			 * HXX
			 * */
			else if(grid[cannon[i].getLocY() + 1][cannon[i].getLocX() - 1] == ship[i].getColor())
			{
				grid[cannon[i].getLocY() + 1][cannon[i].getLocX() - 1] = 'H';
				ship[i].setHealth(ship[i].getHealth() - (ship[i].getHealth() * 0.1));
				
				if(ship[i].getStatus() != " ")
				{
					ship[i].setStatus(ship[i].getStatus() + ", ");
				}
				
				ship[i].setStatus(ship[i].getStatus() + "Hit on the Starboard Bow");
			}
		}
		//If the cannon is at a spot that is empty or has its type (a X or O) then it will make that spot its type
		if(cannon[i].getLocX() != 0)
		{
			if(grid[cannon[i].getLocY()][cannon[i].getLocX() - 1] == ' ')
			{
				grid[cannon[i].getLocY()][cannon[i].getLocX() - 1] = cannon[i].getType();
			}
			/*
			 * XXX
			 * HXX  H -> place where ship is. 
			 * XXX
			 * */
			else if(grid[cannon[i].getLocY()][cannon[i].getLocX() - 1] == ship[i].getColor())
			{
				grid[cannon[i].getLocY()][cannon[i].getLocX() - 1] = 'H';
				ship[i].setHealth(ship[i].getHealth() - (ship[i].getHealth() * 0.25));
				
				if(ship[i].getStatus() != " ")
				{
					ship[i].setStatus(ship[i].getStatus() + ", ");
				}
				
				ship[i].setStatus(ship[i].getStatus() + "Hit on Starboard");
			}
		}
		//If the cannon is at a spot that is empty or has its type (a X or O) then it will make that spot its type
		if(cannon[i].getLocY() != 0 && cannon[i].getLocY() != 5 && cannon[i].getLocX() != 0)
		{
			if(grid[cannon[i].getLocY() - 1][cannon[i].getLocX() - 1] == ' ')
			{
				grid[cannon[i].getLocY() - 1][cannon[i].getLocX() - 1] = cannon[i].getType();
			}
			/*
			 * HXX
			 * XXX  H -> place where ship is. 
			 * XXX
			 * */
			else if(grid[cannon[i].getLocY() - 1][cannon[i].getLocX() - 1] == ship[i].getColor())
			{
				grid[cannon[i].getLocY() - 1][cannon[i].getLocX() - 1] = 'H';
				ship[i].setHealth(ship[i].getHealth() - (ship[i].getHealth() * 0.1));
				
				if(ship[i].getStatus() != " ")
				{
					ship[i].setStatus(ship[i].getStatus() + ", ");
				}
				
				ship[i].setStatus(ship[i].getStatus() + "Hit on the Starboard Stern");
			}
		}
		//If the cannon is at a spot that is empty or has its type (a X or O) then it will make that spot its type
		if(cannon[i].getLocY() != 0 && cannon[i].getLocY() != 5)
		{
			if(grid[cannon[i].getLocY() - 1][cannon[i].getLocX()] == ' ')
			{
				grid[cannon[i].getLocY() - 1][cannon[i].getLocX()] = cannon[i].getType();
			}
			/*
			 * XHX
			 * XXX  H -> place where ship is. 
			 * XXX
			 * */
			else if(grid[cannon[i].getLocY() - 1][cannon[i].getLocX()] == ship[i].getColor())
			{
				grid[cannon[i].getLocY() - 1][cannon[i].getLocX()] = 'H';
				ship[i].setHealth(ship[i].getHealth() - (ship[i].getHealth() * 0.25));
			
				if(ship[i].getStatus() != " ")
				{
					ship[i].setStatus(ship[i].getStatus() + ", ");
				}
				
				ship[i].setStatus(ship[i].getStatus() + "Hit on the Stern");
			}
		}
		//If the cannon is at a spot that is empty or has its type (a X or O) then it will make that spot its type
		if(cannon[i].getLocY() != 0 && cannon[i].getLocY() != 5 && cannon[i].getLocX() != 9)
		{
			if(grid[cannon[i].getLocY() - 1][cannon[i].getLocX() + 1] == ' ')
			{
				grid[cannon[i].getLocY() - 1][cannon[i].getLocX() + 1] = cannon[i].getType();
			}
			/*
			 * XXH
			 * XXX  H -> place where ship is. 
			 * XXX
			 * */
			else if(grid[cannon[i].getLocY() - 1][cannon[i].getLocX() + 1] == ship[i].getColor())
			{
				grid[cannon[i].getLocY() - 1][cannon[i].getLocX() + 1] = 'H';
				ship[i].setHealth(ship[i].getHealth() - (ship[i].getHealth() * 0.1));
				
				if(ship[i].getStatus() != " ")
				{
					ship[i].setStatus(ship[i].getStatus() + ", ");
				}
				
				ship[i].setStatus(ship[i].getStatus() + "Hit on the Portside Stern");
			}
		}
		//If the cannon is at a spot that is empty or has its type (a X or O) then it will make that spot its type
		if(cannon[i].getLocX() != 9)
		{
			if(grid[cannon[i].getLocY()][cannon[i].getLocX() + 1] == ' ')
			{
				grid[cannon[i].getLocY()][cannon[i].getLocX() + 1] = cannon[i].getType();
			}
			/*
			 * XXX
			 * XXH  H -> place where ship is. 
			 * XXX
			 * */
			else if(grid[cannon[i].getLocY()][cannon[i].getLocX() + 1] == ship[i].getColor())
			{
				grid[cannon[i].getLocY()][cannon[i].getLocX() + 1] = 'H';
				ship[i].setHealth(ship[i].getHealth() - (ship[i].getHealth() * 0.25));
				
				if(ship[i].getStatus() != " ")
				{
					ship[i].setStatus(ship[i].getStatus() + ", ");
				}
				
				ship[i].setStatus(ship[i].getStatus() + "Hit on Portside");
			}
		}
	}
}

/*
 * Displays all the ships along with their health in a number and 
 * healthbar format. This status is displayed as well which describes
 * where and how a ship was hit. Coordinates are displayed as well to help identify.
 * */
void Board::printGreenHealth()
{
	for(int i = 0; i < NUMBEROFSHIPS; i++)
	{
		cout << "Green Ship " << i+1 <<": " << endl;
		cout << "	Health: " << Green[i].getHealth() << "% " << Green[i].healthBar() << endl;
		
		checkStatus(Green, NUMBEROFSHIPS);
		cout << "	Status:" << Green[i].getStatus() << endl;
		
		if(Green[i].getStatus() != "SUNK")
		{
			cout << "	Coords: (" << Green[i].getLocX() + 1 << ", " << Green[i].getLocY() + 1 << ")" << endl;
		}
	}
}

/*
 * Displays all the ships along with their health in a number and 
 * healthbar format. This status is displayed as well which describes
 * where and how a ship was hit. Coordinates are displayed as well to help identify.
 * */
void Board::printBlueHealth()
{
		
	for(int i = 0; i < NUMBEROFSHIPS; i++)
	{
		cout << "Blue Ship " << i+1 <<": " << endl;
		
		
		checkStatus(Blue, NUMBEROFSHIPS);
		
		
		cout << "	Health: " << Blue[i].getHealth() << "% " << Blue[i].healthBar() << endl;
		cout << "	Status:" << Blue[i].getStatus() << endl;
		
		if(Blue[i].getStatus() != "SUNK")
		{
			cout << "	Coords: (" << Blue[i].getLocX() + 1 << ", " << Blue[i].getLocY() + 1 << ")" << endl;
		}
	}
	cout << endl;
}

/*
 * Checks the health of each ship and displays whether the ship avoided 
 * fire and whether after losing ten percent was still able to float. 
 * */
void Board::checkStatus(Ship* ship, const int num)
{
	
	for(int i =0; i<num; i++)
	{
		if(ship[i].getStatus() == " ")
		{
			ship[i].setStatus(" Avoided Fire");
		}
		
		if(ship[i].getHealth() < 10)
		{
			if(ship[i].getStatus() == " Avoided Fire")
			{
				ship[i].setStatus(" Avoided Fire, But Is Too Weak");
			}
		}
	}
}

/*
 * This terminates the program. Displays who the winner of the game is
 * and deallocates the memory of the ships and cannons. 
 * */
void Board::terminate()
{
	int blue = checkQuit(Blue);
	int green = checkQuit(Green);
	
	displayGreenSunkenShips();
	PrintGrid();
	displayBlueSunkenShips();
	
	cout << "RESULTS: ";
	
	if(day >= 24)
	{
		if(blue < green)
		{
			cout << "Time over: GREEN WINS!" << endl;
		}
		else if(green < blue)
		{
			cout << "Time over: BLUE WINS!" << endl;
		}
		else
		{
			cout << "Time over: IT IS A DRAW" << endl;
		}
	}
	else
	{
		if(blue == green)
		{
			cout << "IT IS A DRAW" << endl;
		}
		else if(blue < green)
		{
			cout << "GREEN WINS!" << endl;
		}
		else if(green < blue)
		{
			cout << "BLUE WINS!" << endl;
		}
	}
	
	DeleteShipsAndCannons();
}

/*
 * Checks to make sure that both ships still have ships after each day. 
 * If a ship loses all of its ships. Then the other team automatically 
 * wins. 
 * */
bool Board::checkTerminate()
{
	int blue = checkQuit(Blue);
	int green = checkQuit(Green);
	
	if(day >= 24)
	{
		terminate();
		return false;
	}
	
	if(blue == 0 || green == 0)
	{
		terminate();
		return false;
	}
	else
	{
		return true;
	}

}

/*
 * Counts the ammount of sunken ships of the inputted array of ships. 
 * */
const int Board::checkQuit(Ship* ship) const
{
	int count = NUMBEROFSHIPS;
	for (int i = 0; i < NUMBEROFSHIPS; i++)
	{
		if(ship[i].getStatus() == "SUNK")
		{
			count--;
		}
	}
	return count;
}

/*
 * Displays the number of blue ships sunken. It also displays the number of
 * the ships that have sank in a list on the blue team. 
 * */
void Board::displayBlueSunkenShips() const
{
	int num = checkQuit(Blue);
	cout << "Number of Sunken Blue Ships: " << 5 - num << endl;
	
	if(num != 5)
	{
		cout << "The ships that sank: ";
		for (int i = 0; i < NUMBEROFSHIPS; i++)
		{
			if(Blue[i].getStatus() == "SUNK")
			{
				cout << i+1 << " ";
			}
		}
		cout << endl;
	}
	cout << endl;
}

/*
 * Displays the number of blue ships sunken. It also displays the number of
 * the ships that have sank in a list on the green team. 
 * */
void Board::displayGreenSunkenShips() const
{
	int num = checkQuit(Blue);
	cout << "Number of Sunken Green Ships: " << 5 - num << endl;
	
	if(num != 5)
	{
		cout << "The ships that sank: ";
		for (int i = 0; i < NUMBEROFSHIPS; i++)
		{
			if(Green[i].getStatus() == "SUNK")
			{
				cout << i+1 << " ";
			}
		}
		cout << endl;
	}
	cout << endl;
}

/*
 * Deallocates all the memory and ends the program. 
 * */
void Board::DeleteShipsAndCannons()
{
	delete [] Blue;
	delete [] Green;
	delete [] greenCan;
	delete [] blueCan;

	cout << endl << "End of Simulation" << endl;
	exit(0);
}


