
/* File: file_IO.cpp
 * Created By: Ryan Sommerville
 * Editted BY: -
 * Last Editted By: Ryan Sommerville
 * Created: June 15, 2020
 * Last Editted: June 15, 2020
 * Description: A program in the Term Project for ENSF 337 at the University of Calgary in the term Spring 2020.
 *    The program is designed as a flight record that is able to record passenger information and seats for a particular
 *    flight and display this information to the user of the program, as well as allow them to change it. This file
 *	  is a cpp file that contains the function definitions for file input and output.
 */
 
 #include <iostream>
 #include <fstream>
 #include <string>
 #include <iomanip>
 
 #include "flight_class.h"
 #include "passenger_class.h"
 #include "seat_class.h"
 #include "terminalIO.h"
 #include "file_IO.h"
 #include "data_manip_functions.h"
 
 using namespace std;
 
 
 void readFromFile(Flight& source) 
 {
	 string filename = "flight_info.txt";
	 ifstream in;
	 in.open(filename);
	 if(in.fail()) 
	 {
		 int option = error00(filename);
		 if(option == 1) 
		 {
			 in.clear();
			 in.open(filename);
			 if(in.fail()) 
			 {
				 cout << "\nERROR 00.1: COULD NOT OPEN SOURCE FILE: " << filename << "\n";
				 exit(1);
			 }
		 }
		 else
			 exit(1);
	 }
	 Passenger p;
	 
	 string id;
	 int r, c;
	 in >> id;
	 if(in.eof())
		 error01();
	 in >> r;
	 if(in.eof())
		 error01();
	 in >> c;
	 if(in.fail())
		 error01();
	 if(in.eof())
		 return;

	 source.setid(id);
	 source.setrows(r);
	 source.setcolumns(c);
	 
	 string firstname;
	 string lastname;
	 string phonenum;
	 int seatn;
	 char seatl;
	 int passid;
	 char junk [100];
	 in.getline(junk, 100);
	 while(1)
	 {
		 char a[20];
		 in.get(a, 21);
		 firstname = a;
		 if(in.fail()||in.eof()) 
		 {
			 in.close();
			 break;
		 }
		 in.get(a, 21);
		 lastname = a;
		 if(in.fail()||in.eof()) 
		 {
			 error02();
			 in.close();
			 break;
		 }
		 in.get(a, 21);
		 phonenum = a;
		 if(in.fail()||in.eof()) 
		 {
			 error02();
			 in.close();
			 break;
		 }
		 in >> seatn >> seatl;
		 if(in.fail()||in.eof()) 
		 {
			 error02();
			 in.close();
			 break;
		 }
		 in >> passid;
		 if(in.fail()) 
		 {
			 error02();
			 in.close();
			 break;
		 }	
		 Seat* newSeat = new Seat(seatn, seatl);
		 p.setfName(firstname);
		 p.setlName(lastname);
		 p.setphoneNum(phonenum);
		 p.setSeat(newSeat);
		 p.setid(passid);
		 source.setpassenger(seatn - 1, seatl - 'A', p);
		 in.getline(junk, 100);
		 if(in.eof()) 
		 {
			 in.close();
			 break;
		 }
	 }	 

 }
 
 void saveInFile(Flight& source)
 {
	 string filename = "flight_info.txt";
	 ofstream out;
	 out.open(filename);
	 out << left << setw(9) << source.getid() << setw(6) << source.getrows() << setw(6) << source.getcolumns() << "\n";
	 double lowest;
	 int i, j, _i, _j;
	 char seat [4] = "   ";
	 while(1)
	 {
		 lowest = 1000000;
		 for(i = 0; i < source.getrows(); i++)
		 {
			 for(j = 0; j < source.getcolumns(); j++)
			 {
				 if(!source.getpassengers().at(i).at(j).getfName().empty() && source.getpassengers().at(i).at(j).getid() < lowest)
				 {
					 lowest = source.getpassengers().at(i).at(j).getid();
					_i = i;
					_j = j;
				 }
			 }
		 }
		 if(lowest == 1000000)
			 break;
		 for(int k = 0; k < 3; k++)
			 seat[k] = ' ';
		 if(_i + 1 >= 10) 
		 {
			 seat[0] = _i/10 + '0';
			 seat[1] = _i % 10 + '1';
			 seat[2] = _j + 'A';
		 }
		 else 
		 {
			 seat[0] = _i + '1';
			 seat[1] = _j + 'A';
		 }
		 string seatstring = seat;
		 
		 out << setw(20) << source.getpassengers().at(_i).at(_j).getfName() << setw(20) << source.getpassengers().at(_i).at(_j).getlName() 
			 << setw(20) << source.getpassengers().at(_i).at(_j).getphoneNum() << setw(4) << seatstring << lowest << endl;
		 source.removepassenger(_i, _j);
	 }
	 cout << "  Saving Successful" << endl;
 }
		 
	 