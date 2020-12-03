/*
 * Name: Matt Duggan
 * Date: 11/15/2020 12:00am
 * 
 * Description: 
 * 
 * This is my version of a UI for the ship simulation. It uses some simple 
 * recursion to form an input repeat and validation for proper inputs 
 * from the user. It also allows the user to fast forward a certain number
 * of events while still being able to run the simulation each day as normal. 
 * 
 * Input Requirements:
 * 
 * The inputs required are only a 1, 2, or 3. All other inputs will be ignored 
 * and proper input will be repeatedly asked until 1, 2, or 3 are inputted. 
 * A user can quit anytime by pressing 3.  Since 25 is the set number to find a winner, 
 * a user cannot go past 25 but day 25 will automatically be fast forward to. 
 * 
 * Output:
 * 
 * A user will see a board of the simulation. Along with the board the user can 
 * choose to fire the cannons, fast forward an x amount of days, or quit. 
 * Once a user decides to see the cannons fire, A user may go to the next day, fast 
 * forward again or quit. Side note, a user can not see the cannons fire if they fast forward. 
 * They will only see the day they fast forward to along with information 
 * about each ship. 
 *   
 * */

#include "start.h"

/*
 * Default constructor. Sets the start not to quit. 
 * */
Start::Start()
{
	bool quit = false;
	
}

/*
 * Prints out a new board with the current contents of grid. 
 * */
void Start::printTheBoard()
{
	W.initGrid();
	W.PrintGrid();
}

/*
 * Displays the opening of the UI. Gives three options to fire, fast
 * forward a number of days or quit now and display the results of the
 * simulation. 
 * */
int Start::opening()
{
	cout << "CHOOSE ONE OF THE FOLLOWING" << endl;
	cout << "1) Fire the Cannons" << endl;
	cout << "2) Fast Forward X Number of Days (max 25)" << endl;
	cout << "3) Quit" << endl << endl;
	
	cin >> cont;
	
	cout<<endl;
	
	//A validation that the input of the user was an int. 
	if(cin.fail())
	{
		cout << "What you typed wasn't even an integer. Please choose an appropriate option."<<endl;
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		opening();
	}
	
	if(cont != 1 && cont != 2 && cont != 3)
	{
		cout << cont << endl;
		cout << "Invalid input. Must be '1', '2', or '3'. Try Again." << endl;
		cin.clear();
		opening(); 
	}
	return cont;
}

/*
 * Fast forwards through a certain amount of days which is inputted into
 * the function. 
 * */
void Start::fastForward(const int days)
{
	
	for(int i = 0; i < days; i++)
	{
		W.fire();
		W.nextMove();
		quit = W.checkTerminate();
		
			if(!quit)
			{
				W.DeleteShipsAndCannons();
				break;
			}
	}
	
	if(!alreadyDisplayed)
	{
		W.displayGreenSunkenShips();
		W.PrintGrid();
		W.displayBlueSunkenShips();
	}
	
}

/*
 * Displays the UI interface options after firing the cannons. A user may
 * go to the next day, fast forward or quit again displaying the results
 * of the simulation. 
 * */
void Start::nextDay()
{
	cout << "CHOOSE ONE OF THE FOLLOWING" << endl;
	cout << "1) Continue to the next day" << endl;
	cout << "2) Fast Forward X Number of Days (max 25)" << endl;
	cout << "3) Quit" << endl << endl;
	cin >> cont;
	
	cout << endl;
	
	//checks the cin on whether it is an int. Fixed infinite loop with incorrect input. 
	if(cin.fail())
	{
		cout << "What you typed wasn't even an integer. Please choose an appropriate option."<<endl;
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		nextDay();
	}
	
	switch(cont)
	{
		//the first option to go to the next day. 
		case 1:
		
			
			W.UpdateGrid();
			W.nextMove();
			quit = W.checkTerminate();
		
			if(!quit)
			{
				W.DeleteShipsAndCannons();
				quit = true;
				break;
			}
			W.printNextDayHeader();
			//~ W.printNextDayHeader();
			//~ W.PrintGrid();
			W.displayGreenSunkenShips();
			printTheBoard();
			W.displayBlueSunkenShips();
			
			start();
			break;
			
		//the second option to fast forward
		case 2:
			days = 0;
			cout << "Amount of Days: ";
			cin >> days;
			
			cout << endl;
				
			if(W.getDay() + days > 24)
			{
				cout << endl << "Max Number of Days is 25. Fast Forwarding to End of Simulation" << endl << endl;
				alreadyDisplayed = false;
				days = 24 - W.getDay();
				if(days > 0)
				{
					fastForward(days);
					W.terminate();
				}
				break;
			}
			fastForward(days);
			W.UpdateGrid();
			start();
			break;
		//the third option to quit.
		case 3:
			W.terminate();
			break;
		//recursively goes back to beginning in int inserted is invalid. 
		default:
			cout << "Invalid Operation, try again." << endl;
			nextDay();
	}
}

/*
 * The options presented at the opening. This is set to three funtions, but 
 * could be open to more, such as add another ship in the middle of a day 
 * or bypass the 25 day limit. 
 * */
void Start::fireCans(const int num)
{
	
	switch(num)
	{
			//Fires the cannons and checks to see if the game needs to quit.
			case 1:
				W.transition();
				W.fire();
		
				W.printGreenHealth();
				W.PrintGrid();
				W.printBlueHealth();
				quit = W.checkTerminate();
		
				if(!quit)
				{
					W.DeleteShipsAndCannons();
					break;
				}
				//recursively goes back to next day. 
				nextDay();
			
				break;
			//Fast forward a number of days. Can not go past 25 days. 
			case 2:
				days = 0;
				cout << "Amount of Days: ";
				cin >> days;
				
				if(W.getDay() + days > 24)
				{
					cout << endl << "Max Number of Days is 25. Fast Forwarding to End of Simulation" << endl << endl;
					days = 24 - W.getDay();
					if(days > 0)
					{
						fastForward(days);
						W.terminate();
					}
					break;
				}
				fastForward(days);
				W.UpdateGrid();
				
				start();
				break;
				//quit
			case 3:
				W.terminate();
				break;
			//if an invalid int we recall the function. 
			default:
				cout << "Invalid Operation, try again." << endl;
				start();
				
	}
}
//Fixes randomization issue of the first board
void Start::randomInit()
{
	for(int i = 0; i < 100; i++)
	{
		W.randInit();
	}
	printTheBoard();
}

//Starts the "UI". 
void Start::start()
{
	int command;
	command = opening();
	fireCans(command);
}
