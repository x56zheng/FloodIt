#include "controller.h"
#include <iostream>
#include <string>
using namespace std;

/************************** main ********************************
Purpose: Receive argument from command line to determine whether to 
  turn graphic mode on.  
Return: Zero if terminate successfully. Non-zero if terminate unsuccessfully.
Error: If receive invalid command line argument. An error message will be sent 
  to stderr and the program will be terminated unsuccessfully.
******************************************************************/
int main (int argc, char **argv) {
	if (argc == 1) {  // No graphic mode.
		Controller c(false);
		c.play();
		return 0;
	} else if (argc == 2 && string(argv[1]) == "-graphics") {  // Graphic mode.
		Controller c(true);
		c.play();
		return 0;
	} else {  // Invalid command line argument.
		cerr << "usage: ./flood or ./flood -graphics" << endl;
		return -1;
	}

}
