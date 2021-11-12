
/* File: terminalIO.h
 * Created By: Ryan Sommerville
 * Editted BY: -
 * Last Editted By: Ryan Sommerville
 * Created: June 10, 2020
 * Last Editted: June 15, 2020
 * Description: A program in the Term Project for ENSF 337 at the University of Calgary in the term Spring 2020.
 *    The program is designed as a flight record that is able to record passenger information and seats for a particular
 *    flight and display this information to the user of the program, as well as allow them to change it. This program is
 *    a header file that contains the statements for the global functions used in the Project.
 */
 
 #ifndef terminalIO
 #define terminalIO
 
 void introduction();
 /* Created By: Ryan Sommerville
  * Created On: June 10, 2020
  * Requires: -
  * Promises: Prints an introduction to the program onto the terminal
  */
  
 void wait();
 /* Created By: Ryan Sommerville
  * Created On: June 10, 2020
  * Requires: -
  * Promises: Pauses the program until the user presses enter
  */
 
 int menu();
 /* Created By: Ryan Sommerville
  * Created On: June 10, 2020
  * Requires: -
  * Promises: Prints a list of options to the terminal and recieves an input in the form of a number.
  */
 
 void cleanBuffer();
 /* Created By: Ryan Sommerville
  * Created On: June 10, 2020
  * Requires: -
  * Promises: Empties buffer of the terminal of all extra characters.
  */
  
 void displayFlightPlan(Flight& source);
 /* Created By: Ryan Sommerville
  * Created On: June 12, 2020
  * Requires: source should have at least one row and column for it to display properly.
  * Promises: Displays a grid on the terminal to show what seats are occupied and which ones aren't.
  */
  
  void listPassengers(Flight& source);
 /* Created By: Ryan Sommerville
  * Created On: June 13, 2020
  * Requires: -
  * Promises: Prints a list of all passenger info, including their name, id, and seat, to the terminal.
  */
  
  
  
  
  
  /*Error messages and options*/
  
  int error00(string& filename);
  void error01();
  void error02();
  char error10(char input, int start, int end);
  void error11(string& name);
  void error12(string& name);
  
 
 
 #endif