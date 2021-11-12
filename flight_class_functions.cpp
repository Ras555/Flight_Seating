
/* File: flight_class_functions.cpp
 * Created By: Ryan Sommerville
 * Editted BY: -
 * Last Editted By: Ryan Sommerville
 * Created: June 11, 2020
 * Last Editted: June 15, 2020
 * Description: A program in the Term Project for ENSF 337 at the University of Calgary in the term Spring 2020.
 *    The program is designed as a flight record that is able to record passenger information and seats for a particular
 *    flight and display this information to the user of the program, as well as allow them to change it. This file is
 *    a cpp file that holds the function definitions for the member functions of the flight class.
 */
 
#include "flight_class.h"
#include "passenger_class.h"
#include "seat_class.h"
#include "terminalIO.h"
#include "file_IO.h"
#include "data_manip_functions.h"
#include <iostream>

 using namespace std;
 Flight::Flight() 
 {
	 rows = 0;
	 columns = 0;
 }
 
 Flight::~Flight() 
 {
	 for(int i = 0; i < rows; i++)
	 {
		 for(int j = 0; j < columns; j++) 
			 delete passengerList.at(i).at(j).getpasSeat();
	 }
 }
 
 void Flight::setpassenger(int r, int c, Passenger& pass) 
 {
	 passengerList.at(r).at(c) = pass;
 }
 
 void Flight::setrows(int r) 
 {
	 rows = r;
	 passengerList.resize(r);
	 for(int i = 0; i < r; i++)
		 passengerList.at(i).resize(columns);
 }
 
 void Flight::setcolumns(int c) 
 {
	 columns = c;
	 for(int i = 0; i < rows; i++)
		 passengerList.at(i).resize(c);
 }

void Flight::removepassenger(int r, int c)
{
	passengerList.at(r).at(c).blank();
}