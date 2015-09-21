#include "controller.h"
#include "game.h"
#include "textdisplay.h"
#include "graphicdisplay.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

void Controller::init(istream & input, Game & g) {
  int r = -2;
  int c = -2;
  unsigned int state = -1;
  // Read the coordinates and state of the cell to be initialized.
  // While loop has two exits: When receiving the end signal or the
  // read fails.
  while (input >> r >> c) {
    if (r == -1 && c == -1) {
      break;
    }
    input >> state;
    g.init(r, c, state);  
  }
  // Input is not integers.
  if (!((r == -1 && c == -1) || input.eof())) {  
    cerr << "Invalid input." << endl;
    return;
  }
}

bool Controller::checkWin(int movesLeft) {
  if(game->isWon() && movesLeft != 0) {
    cout << "Won" << endl;
    return true;
  }
  return false;
}

Controller::Controller(bool isGraphic): isGraphic(isGraphic) {
    game = new Game();
    td = NULL;
    gd = NULL;
}

Controller::~Controller() {
  delete game;
  delete td;
  delete gd;
}

void Controller::play() {
  srand(time(NULL));
  int moves = 0;
  string cmd;
  bool playing = false;
  while (cin >> cmd) {
    if (cmd == "new") {
      int n;
      cin >> n; 
      game->init(n, this);
      delete td;
      td = new TextDisplay(n);
      if (isGraphic) {
        gd = new GraphicDisplay(n);        
      }
      moves = 0; 
    } 
    else if (cmd == "?") {  // Show the colour mapping.
      cout << "White: 0" << endl;
      cout << "Black: 1" << endl;
      cout << "Red:   2" << endl;
      cout << "Green: 3" << endl;
      cout << "Blue:  4" << endl;
    }
    else if (cmd == "init") {
      init(cin, *game);
      #if DEBUG
      cout << "Done initialization" << endl;
      #endif
      td->print(cout);
      if (checkWin(moves)){
        break;
      }
    }
    else if (cmd == "include"){
       string file;
       cin >> file;
       ifstream input(file.c_str());
       init(input, *game);
       td->print(cout);
       if (checkWin(moves)){
        break;
      }
    }
    else if (cmd == "switch") {
      if (checkWin(moves)){
        break;
      }
      if(moves > 0){
        int next;
        if (cin >> next && (next >= 0 || next <= 4)){
          game->change(next);
          td->print(cout);
          --moves;
         if (moves == 1) {
          cout << moves << " move left" << endl;
         }
         else {
          cout << moves << " moves left" << endl;
         }
         if(game->isWon()){
           cout << "Won" << endl;
           break;
         }
         if(moves == 0){
             cout << "Lost" << endl;
           break;
         }
        }
        else cerr << "Invalid move" << endl;
      }
    }
    else if (cmd == "game" && !playing){
      cin >> moves;
      if (moves < 0) {
        moves = 0;
      } 
      else if (moves == 1) {
        cout << moves << " move left" << endl;
      }
      else { 
        cout << moves << " moves left" << endl;
      }
      if (checkWin(moves)){
        break;
      }  // if
    }  // else if
  }  // while
}  // play

void Controller::notify(int r, int c, unsigned int state) {
  td->notify(r, c, '0' + state);
  if(isGraphic) {
    gd->notify(r, c, '0' + state);
  }
}

