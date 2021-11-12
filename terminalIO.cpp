
/* File: terminalIO.cpp
 * Created By: Ryan Sommerville
 * Editted BY: -
 * Last Editted By: Ryan Sommerville
 * Created: June 10, 2020
 * Last Editted: June 15, 2020
 * Description: A program in the Term Project for ENSF 337 at the University of Calgary in the term Spring 2020.
 *    The program is designed as a flight record that is able to record passenger information and seats for a particular
 *    flight and display this information to the user of the program, as well as allow them to change it. This program is
 *    a cpp file that holds the function definitions for the functions that input and output to the terminal.
 */
 
 #include <iostream>
 #include <iomanip>
 #include <string>

 #include "flight_class.h"
 #include "passenger_class.h"
 #include "seat_class.h"
 #include "terminalIO.h"
 #include "file_IO.h"
 #include "data_manip_functions.h"

 
 using namespace std;
 
 
 void introduction() 
 {
	 cout << "\n Version 1.0\n";
	 cout << " Term Project - Flight Management Program in C++\n";
	 cout << " Created by: Ryan Sommerville\n";
	 cout << " --------------------------------------------------";
 }
 
 void wait() 
 {
	 cout<< "\n<<< Press Return to Continue>>>>\n";
	 char input = cin.get();
	 if(input != '\n' && input != EOF)
		 cleanBuffer();
 }
 
 void cleanBuffer() 
 {
	 char leftover;
	 cin.clear();
	 while(leftover != '\n' && leftover != EOF) 
	 {
		 leftover = cin.get();
	 }
 }
 
 int menu() 
 {
	 cout << "\n --------------------------------------------------\n";
	 cout << " Please choose one of the following options:\n";
	 cout << " 1) Show flight plan\n";
	 cout << " 2) List passengers\n";
	 cout << " 3) Add passenger\n";
	 cout << " 4) Remove passenger\n";
	 cout << " 5) Save in file\n";
	 cout << " 6) Exit program\n  ";
	 char input = cin.get();
	 cleanBuffer();
	 input = error10(input, 1, 6);
	 return (input - '0');
 }
 
 void displayFlightPlan(Flight& source) 
 {
	 cout << "\n\n";
	 int i, j;
	 cout << "     ";
	 for(i = 0; i < source.getcolumns(); i++)
		 cout << "   " << (char)('A' + i) << "  ";
	 cout << "\n     ";
	 for(i = 0; i < source.getcolumns(); i++)
		cout << "+-----";
	 cout << "+\n     ";
	 for(j = 0; j < source.getrows(); j++) 
	 {
		 for(int i = 0; i < source.getcolumns(); i++)
			cout << "|     ";
		 cout << "|\n  " << right << setw(2) << (j+1) << " ";
		 for(int i = 0; i < source.getcolumns(); i++)
		 {
			 cout << "|  ";
			 if(source.getpassengers().at(j).at(i).getfName().empty())
				 cout << " ";
			 else
				 cout << "X";
			 cout << "  ";
		 }
		 cout << "|\n     ";
		 for(int i = 0; i < source.getcolumns(); i++)
			cout << "|     ";
		 cout << "|\n     ";
		 for(int i = 0; i < source.getcolumns(); i++)
			cout << "+-----";
		 cout << "+\n     ";
	 }
	 cout << "\n";
 }
 
 void listPassengers(Flight& source) 
 {
	 cout << "\n\n";
	 cout << "  First Name            Last Name             Phone Number          ID        Seat \n";
	 cout << "  ------------------------------------------------------------------------------------\n";
	 for(int i = 0; i < source.getrows(); i++) 
		 for(int j = 0; j < source.getcolumns(); j++) 
			 if(!source.getpassengers().at(i).at(j).getfName().empty())
				 cout << left << "  " << setw(22) << source.getpassengers().at(i).at(j).getfName() << setw(22) << source.getpassengers().at(i).at(j).getlName()
					  << setw(22) << source.getpassengers().at(i).at(j).getphoneNum()<< setw(10) << source.getpassengers().at(i).at(j).getid()
					  << source.getpassengers().at(i).at(j).getpasSeat() -> getrow() << source.getpassengers().at(i).at(j).getpasSeat() -> getcolumn() << endl;
	 
 }
 
 
 
 
 
 //Error messages and options
 
 int error00(string& filename) 
 {
	cout << "\n ERROR 00: COULD NOT OPEN SOURCE FILE: " << filename << "\n";
	cout << "  Please choose one of the following options:\n";
	cout << "  1) Enter a new filename\n";
	cout << "  2) Exit program\n ";
	char input = cin.get();
	cleanBuffer();
	input = error10(input, 1, 2);
	if(input == '1') {
		cout << "\n  Please enter the new file name:\n ";
		cin >> filename;
		cleanBuffer();
	}
	return input - '0';
 }
 
 void error01() 
 {
	 cout << "\n ERROR 01: FAILURE TO READ FROM FILE. EXITING PROGRAM.\n";
	 exit(1);	 
 }
 
 void error02() 
 {
	 cout << "\n ERROR 02: FAILURE TO COLLECT DATA. ENDING DATA COLLECTION.\n";
 }
 
 char error10(char input, int start, int end) 
 {
	 while(input < (char)(start + '0') || input > (char)(end + '0')) 
	 {
		 cout << "\nERROR 10: INVALID INPUT TO TERMINAL\n\n  ";
		 input = cin.get();
		 cleanBuffer();
	 }
	 return input;
 }
 
 void error11(string & name) 
 {
	 while(cin.fail())
	 {
		 cout << "\n  ERROR 11: INVALID INPUT ON TERMINAL\n  ";
		 cin.clear();
		 getline(cin, name);
	 }
 }
 
 void error12(string & name)
 {
	 while(name.size() > 20)
	 {
		 cout << "\n  ERROR 12: INVALID INPUT ON TERMINAL\n  ";
		 cin.clear();
		 getline(cin, name);
	 }
 }
