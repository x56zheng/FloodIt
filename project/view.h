#ifndef __VIEW_H__
#define __VIEW_H__
#include <iostream>
#include <sstream>

/***************** View *******************
  Purpose: Abstract class to allow controller 
    to communicate with the display.
 ******************************************/
class View {
  protected:
    const int gridSize;
  public:
    View(int n);  // Set the gridSize to be n.
    
 /****************** notify *******************
 Purpose: The Controller calls notify to update 
   the (r,c) location to be ch.
 **********************************************/
 virtual void notify(int r, int c, char ch) = 0;

 /****************** print *******************
 Purpose: The Controller calls print to print the
   grid.
 **********************************************/
 virtual void print(std::ostream &out) = 0;
    
 virtual ~View() = 0;
};

#endif
