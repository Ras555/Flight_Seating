
/* File: passenger_class.h
 * Created By: Ryan Sommerville
 * Editted BY: -
 * Last Editted By: Ryan Sommerville
 * Created: June 12, 2020
 * Last Editted: June 15, 2020
 * Description: A program in the Term Project for ENSF 337 at the University of Calgary in the term Spring 2020.
 *    The program is designed as a flight record that is able to record passenger information and seats for a particular
 *    flight and display this information to the user of the program, as well as allow them to change it. This file is
 *    a header file that contains the deffinitions of the passenger class used in the program.
 */

#ifndef passenger_class
#define passenger_class

#include "seat_class.h"
#include <string>
#include <iostream>
using std::string;
using namespace std;

class Passenger 
{
	private:
		string fName;
		string lName;
		string phoneNum;
		int id;
		Seat* pasSeat;
	public:
		Passenger();
		string getfName() const { return fName; }
		string getlName() const { return lName; }
		string getphoneNum() const { return phoneNum; }
		int getid() const { return id; }
		Seat* getpasSeat() const { return pasSeat; }
		void setfName(const string& name) { fName = name; }
		void setlName (const string& name) { lName = name; }
		void setphoneNum(const string& num) { phoneNum = num;}
		void setid(const int a) { id = a;}
		void setSeat(Seat* newSeat) { pasSeat = newSeat; }
		Passenger& operator =(Passenger& source);
		void blank();
};


#endif