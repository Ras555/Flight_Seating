
/* File: flight_class.h
 * Created By: Ryan Sommerville
 * Editted BY: -
 * Last Editted By: Ryan Sommerville
 * Created: June 10, 2020
 * Last Editted: June 15, 2020
 * Description: A program in the Term Project for ENSF 337 at the University of Calgary in the term Spring 2020.
 *    The program is designed as a flight record that is able to record passenger information and seats for a particular
 *    flight and display this information to the user of the program, as well as allow them to change it. This file is
 *    a header file that contains the deffinitions of the flight class used in the program.
 */

 
 #ifndef flight_class
 #define flight_class
 
 #include <string>
 #include <vector>
 #include "passenger_class.h"
 
 using std::vector;
 using std::string;
 typedef vector <vector <Passenger>> flightPlan;
 
 class Flight 
 {
	 private:
		string flightID;
		int rows;
		int columns;
		flightPlan passengerList;
		
	public:
		Flight(); //Constructor that takes ints for rows and columns as it's arguements.
		~Flight();
		
		string getid() const { return flightID; }
		int getrows() const { return rows; }
		int getcolumns() const { return columns; }
		flightPlan& getpassengers() { return passengerList; }
		void setrows(int r);
		void setcolumns(int c);
		void setpassenger(int r, int c, Passenger& pass);
		void setid(const string & id) { flightID = id; }
		void removepassenger(int r, int c);
};
#endif
	 
	 
	 
	 
	 
	 