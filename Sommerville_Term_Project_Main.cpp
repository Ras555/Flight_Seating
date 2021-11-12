
/* File: Sommerville_Term_Project_Main.cpp
 * Created By: Ryan Sommerville
 * Editted BY: -
 * Last Editted By: Ryan Sommerville
 * Created: June 10, 2020
 * Last Editted: June 15, 2020
 * Description: The main program in the Term Project for ENSF 337 at the University of Calgary in the term Spring 2020.
 *    The program is designed as a flight record that is able to record passenger information and seats for a particular
 *    flight and display this information to the user of the program, as well as allow them to change it. This main program
 *    holds a loop that calls a menu to display different options and then calls functions based on which object is chosen.
 */

#include "flight_class.h"
#include "passenger_class.h"
#include "seat_class.h"
#include "terminalIO.h"
#include "file_IO.h"
#include "data_manip_functions.h"



#include <iostream>
using std::cout;
using std::cin;

int main(void) 
{
	
	Flight flightData;
	
	introduction();
	wait();
	readFromFile(flightData);
	while(1) 
	{
		int choice = menu();
		if(choice == 1) 
		{
			displayFlightPlan(flightData);
			wait();
		}
		else if(choice == 2) 
		{
			listPassengers(flightData);
			wait();
		}
		else if(choice == 3) 
		{
			addPassenger(flightData);
			wait();
		}
		else if(choice == 4)
		{
			removePassenger(flightData);
		}
		else if(choice == 5)
		{
			saveInFile(flightData);
			wait();
		}
		else if(choice == 6)
			exit(1);
		else
			cout << "\n Invalid input\n";		
	}
}