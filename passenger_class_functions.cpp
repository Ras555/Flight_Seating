
/* File: passenger_class_functions.cpp
 * Created By: Ryan Sommerville
 * Editted BY: -
 * Last Editted By: Ryan Sommerville
 * Created: June 15, 2020
 * Last Editted: June 15, 2020
 * Description: A program in the Term Project for ENSF 337 at the University of Calgary in the term Spring 2020.
 *    The program is designed as a flight record that is able to record passenger information and seats for a particular
 *    flight and display this information to the user of the program, as well as allow them to change it. This file is
 *    a cpp file that contains the deffinitions of the passenger class member functions.
 */
 
 #include "flight_class.h"
 #include "passenger_class.h"
 #include "seat_class.h"
 #include "terminalIO.h"
 #include "file_IO.h"
 #include "data_manip_functions.h"

 
 Passenger& Passenger::operator =(Passenger& source) {
	 fName = source.getfName();
	 lName = source.getlName();
	 phoneNum = source.getphoneNum();
	 id = source.getid();
	 if(pasSeat != nullptr)
		delete pasSeat;
	 pasSeat = source.getpasSeat();
	 return *this;
 }
 
 Passenger::Passenger() {
	 pasSeat = nullptr;
	 id = 0;
 }

void Passenger::blank() {
	delete pasSeat;
	pasSeat = nullptr;
	id = 0;
	fName.clear();
	lName.clear();
}