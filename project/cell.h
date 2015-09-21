#ifndef __CELL_H__
#define __CELL_H__
#include <iostream>

class Game;

const int maxNeighbours = 4;


class Cell {
  int state;        //current state of the cell
  int prevState;    //previous state of the cell
  int numNeighbours;   //number of neighbors
  Cell *neighbours[maxNeighbours];   //pointers to neighbors
  int r, c;                   //co-ordinates of the cell
  Game * game;                //pointer to game
  
  
  /***************************** notifyNeighbours ******************************
   Purpose: Tell all of my neighbours that I have been switched.
  ******************************************************************************/
  void notifyNeighbours();   

  /**************************** notifyGame *************************************
   Purpose: Notify the game and registered notification object of the change.
   *****************************************************************************/
  void notifyGame();	   

 public:
  Cell();                                   

  /**************************** getState *************************************
   Purpose: Getter for private state.
  *****************************************************************************/
  int getState();        

  /**************************** setState *************************************
   Purpose: Setter for private state.
  *****************************************************************************/                     
  void setState(const int& change);       

  /**************************** setCoords *************************************
   Purpose: Setter for private co-ordinates of cell.
  *****************************************************************************/ 
  void setCoords(const int r, const int c);		    

  /**************************** setGame *************************************
   Purpose: Setter for game.
  *****************************************************************************/ 
  void setGame(Game * game);  

  /**************************** addNeighbour *************************************
   Purpose: Add a neighbouring cell.
   Error: The number of neighbours is greater than 4. An error message will be sent 
     to stderr.
  *****************************************************************************/ 
  void addNeighbour(Cell *neighbour);      

  /**************************** notify *******************************************
   Purpose: Intended to be called only by the game class for changing the state of 
     the (0, 0) cell.
   *******************************************************************************/
  void notify( const int & change);

  /**************************** notify *******************************************
   Purpose: Intended to be called by Cells to notify their neighbors and notify the
     game its change.
     current: this cells current(new) state 
     previous: this cells past state
   *******************************************************************************/
  void notify( const int & current, const int & previous); 
};
#endif
