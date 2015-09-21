#ifndef __GAME_H__
#define __GAME_H__
#include <iostream>
#include "cell.h"

/***************** GameNotification *******************
  Purpose: Abstract class to allow Game to send noticiations
    to a registered object.
 ******************************************************/
class GameNotification {
  public:
    virtual void notify(int r, int c, unsigned int state) = 0;
};

class Game {
  Cell **theGrid;  // The actual grid.
  int gridSize;    // Size of the grid.

  /*
   * The following field helps track how the game has progressed.
   * The field should track how many Cells of the grid are of each color.
   * Whenever a Cell changes color, the corresponding color count should
   * be updated.
   */
  unsigned int colours[5];
  GameNotification *notification;  // object registered for notifications

  /********************** clearGame **********************************
   Purpose: Frees the grid. Notify the controller that grid has been freed. 
     Reset the state tracker.
  ********************************************************************/
  void clearGame();

  /********************** isValid *************************************
  Purpose: Check if the coordinates and state is valid.
  Return: True if the coordinates and state are valid. Otherwise, return 
    false.
  *********************************************************************/
  bool isValid(int, int, unsigned int);
 public:
  Game();

  ~Game();

  /********************* notify ****************************************
  Purpose: Receive update notification from Cells, update the state tracker,
    and notify the controller the update information. 
  **********************************************************************/
  void notify(int r, int c, unsigned int oldState, unsigned int newState);
  
  /********************* isWon ********************************************
  Purpose: Determine if the game has been won.
  Return: True if the game has been won. Otherwise, return false.
  **********************************************************************/
  bool isWon();

  /********************* init ********************************************
  Purpose: Sets up an n x n grid. Clears old grid, if necessary.
  **********************************************************************/
  void init(int n, GameNotification *gameNotification); 

  /********************* change ********************************************
  Purpose: Changes (0,0) and all appropriate neighbours to c.
  **********************************************************************/ 
  void change(const int & c);  

  /********************* init ********************************************
  Purpose: Called by Controller. init in response to initialization requests 
    when game is in init mode. If the cell coordinate and the change of the 
    state is valid, the corresponding cell will change the state and the 
    controller will be notified.
  **********************************************************************/  
  void init(int r, int c, int change); 
};
#endif
