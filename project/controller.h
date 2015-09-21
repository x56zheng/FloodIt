#ifndef __CONTROLLER_H__
#define __CONTROLLER_H__

#include <iostream>
#include "game.h"
#include "view.h"

class Controller : public GameNotification {

    View *td; // The text display.
    View *gd; // The graphic display.
    bool isGraphic;  // A flag to identify if the graphic made is on
    Game *game;
    
    /******************** init *********************
     Purpose: Set the initial state of each cell. 
     Return: Nothing.
     Errors: Input is not integers. Error message is 
       sent to stderr and function exits.
    ***********************************************/
    void init(std::istream & input, Game & g);

    /******************** checkWin ******************
    Purpose: Helper to check if the game is in a win state.
    Return: Ture and prints "Won" to stdout if the game is i
      in a win state. Otherwise, returns false
    *************************************************/
     bool checkWin(int movesLeft);

  public:
    Controller(bool);
   
    ~Controller();
   
    /******************** play *************************
     Purpose: Receives command from users and execute corresponding
       actions.
     Return: Nothing.
     Error: If move is invalid, send error message to stderr.
    *****************************************************/
    void play();
    
    /******************** notify *************************
     Purpose: Update the View(s) to indicate the new game state.
    *****************************************************/
    void notify(int r, int c, unsigned int state);   
};

#endif
