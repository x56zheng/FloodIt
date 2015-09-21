#include <iostream>
#include "cell.h"
#include "game.h"

using namespace std;

void Cell::notifyNeighbours() {
  for (int i = 0; i < numNeighbours; ++i) {
    if (neighbours[i]) {
       neighbours[i]->notify(state, prevState);
    }
  }
}

void Cell::notifyGame() {
  game->notify(r, c, prevState, state);
}	     

//public
Cell::Cell(): state(0), prevState(0), numNeighbours(0), neighbours(), r(0), c(0), game(NULL) {}

int Cell::getState() {
 return state;
}                          

void Cell::setState(const int& change) {
  prevState = state; 
  state = change;
}        

void Cell::setCoords(const int r, const int c) {
  this->r = r;
  this->c = c;   
}		 

void Cell::setGame(Game * game) {
  this->game = game; 
}  
void Cell::addNeighbour(Cell *n) {  //add a neighbouring cell
  for (int i = 0; i < maxNeighbours; ++i) {
    if (!neighbours[i]) {
      neighbours[i] = n;
      ++numNeighbours;
      return;
    }
  }
  cerr << "wrong number of neighbours." << endl;
}       

  void Cell::notify( const int & change) {
    // If (0, 0) does not change, then does not need to notify neighbours.
    if (change == state) {
      return;
    }
    prevState = state;
    state = change; 
    notifyNeighbours();
    notifyGame();
  }

  void Cell::notify( const int & current, const int & previous) {
    // If a cell was in the same state as its neighbouring cell which switched state
    // Then this cell also switched state
    if (state == previous) {
      prevState = state;
      state = current;
      notifyGame();
      notifyNeighbours();
    }
  }

