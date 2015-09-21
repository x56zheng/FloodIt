#ifndef __GRAPHICDISPLAY_H__
#define __GRAPHICDISPLAY_H__
#include "view.h"
#include "window.h"
class GraphicDisplay: public View {
  Xwindow xw;  // the graphic window

 public:  
 	GraphicDisplay(int n);  // //one arg constructor where the parameter is the gridSize
 	~GraphicDisplay(); // dtor
    
    /****************** notify *******************
     Purpose: The Controller calls notify to update 
       the (r,c) location to be ch. Change the colour 
       of the cell accordingly.
    **********************************************/
 	virtual void notify(int r, int c, char ch);

    /****************** print *********************
    Purpose: Inherit from base class View. Do nothing 
       but still needs to be concrete.
    ***********************************************/
 	virtual void print(std::ostream &);
};




#endif
