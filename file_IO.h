
/* File: file_IO.h
 * Created By: Ryan Sommerville
 * Editted BY: -
 * Last Editted By: Ryan Sommerville
 * Created: June 15, 2020
 * Last Editted: June 15, 2020
 * Description: A program in the Term Project for ENSF 337 at the University of Calgary in the term Spring 2020.
 *    The program is designed as a flight record that is able to record passenger information and seats for a particular
 *    flight and display this information to the user of the program, as well as allow them to change it. This file is a
 *	  header file that contains the function definitions for the file input and output functions used in the program.
 */
 
 #ifndef file_IO
 #define file_IO
 
 void readFromFile(Flight& source);
 void saveInFile(Flight& source);
 
 
 #endif