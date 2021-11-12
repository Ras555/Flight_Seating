
/* File: seat_class.h
 * Created By: Ryan Sommerville
 * Editted BY: -
 * Last Editted By: Ryan Sommerville
 * Created: June 12, 2020
 * Last Editted: June 15, 2020
 * Description: A program in the Term Project for ENSF 337 at the University of Calgary in the term Spring 2020.
 *    The program is designed as a flight record that is able to record passenger information and seats for a particular
 *    flight and display this information to the user of the program, as well as allow them to change it. This file is
 *    a header file that contains the deffinitions of the seat class used in the program.
 */

#ifndef seat_class
#define seat_class

class Seat 
{
	private:
		char column;
		int row;
	public:
		Seat(int a, char b) { column = b; row = a; }
		int getrow() const { return row;}
		char getcolumn() const { return column; }
		void setrow(const int r) { row = r; }
		void setcolumn(const char c) { column = c; }
};

#endif