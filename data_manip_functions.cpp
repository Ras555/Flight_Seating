
/* File: data_manip_functions.cpp
 * Created By: Ryan Sommerville
 * Editted BY: -
 * Last Editted By: Ryan Sommerville
 * Created: June 15, 2020
 * Last Editted: June 15, 2020
 * Description: A program in the Term Project for ENSF 337 at the University of Calgary in the term Spring 2020.
 *    The program is designed as a flight record that is able to record passenger information and seats for a particular
 *    flight and display this information to the user of the program, as well as allow them to change it. This file is a
 *	  cpp file that contains function deffinitions for functions that manipulate data used in the program.
 */
 
 
 
 #include "flight_class.h"
 #include "passenger_class.h"
 #include "seat_class.h"
 #include "terminalIO.h"
 #include "file_IO.h"
 #include "data_manip_functions.h"
 
 #include <iostream>
 #include <string>
 
 using namespace std;
 
 void addPassenger(Flight& source) {
	 Passenger p;
	 
	 cout << "\n  Please enter the passengers first name(max 20 characters):\n   ";
	 string firstname;
	 getline(cin, firstname, '\n');
	 if(cin.fail())
		 error11(firstname);
	 error12(firstname);
	 p.setfName(firstname);
	 
	 cout <<  "\n  Please enter the passengers last name(max 20 characters):\n   ";
	 string lastname;
	 getline(cin, lastname, '\n');
	 if(cin.fail())
		 error11(firstname);
	 error12(lastname);
	 p.setlName(lastname);
	 
	 cout << "\n  Please enter passengers phone number(XXX-XXX-XXXX//XXX XXX XXXX):\n   ";
	 string phonenum;
	 getline(cin, phonenum, '\n');

	 if(cin.fail())
		 error11(phonenum);
	 p.setphoneNum(phonenum);
	 
	 cout << "\n  Please enter the passengers id number:\n   ";
	 int id;
	 cin >> id;
	 cleanBuffer();
	 if(cin.fail())
		 error11(phonenum);
	 p.setid(id);
	 
	 displayFlightPlan(source);
	 cout <<  "\n  Please enter the passengers seat row and letter (ex: 24F):\n   ";
	 string seat;
	 int row;
	 char column;
	 getline(cin, seat, '\n');
	 if( id == EOF)
		 return;
	 if(cin.fail())
		error11(phonenum);
	 row = 0;
	 int i;
	 for(i = 0; !isalpha(seat.at(i)); i++)
		 row = row * 10 + seat.at(i) -'0';
	 column = seat.at(i);
	 if(islower(column))
		 column = toupper(column);
	 Seat* newSeat = new Seat(row, column);
	 p.setSeat(newSeat);
	 source.setpassenger(row -1, column - 'A', p);
 }
 
 void removePassenger(Flight & source) {
	 listPassengers(source);
	 int id;
	 cout << "\n   Please enter the id of the passenger you want to remove:\n";
	 cin >> id;
	 cleanBuffer();
	 for(int i = 0; i < source.getrows(); i++)
	 {
		 for(int j = 0; j < source.getcolumns(); j++)
		 {
			 if(source.getpassengers().at(i).at(j).getid() == id)
			 {
				 source.removepassenger(i, j);
				 return;
			 }
		 }
	 }
	 cout << "  ERROR 20: COULD NOT FIND PASSENGER";	 
 }
 
 
 