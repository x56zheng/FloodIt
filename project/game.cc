#include <iostream>
#include "cell.h"
#include "game.h"

using namespace std;

void Game::clearGame() {  // Frees the grid.
  for (int i = 0; i < gridSize; ++i) {
    delete [] theGrid[i]; 
  }
  delete [] theGrid;
  theGrid = NULL;
  // Notify the View the grid has been freed
  for (int r = 0; r < gridSize; ++r) {
    for (int c = 0; c < gridSize; ++c) {
      notification->notify(r, c, 0);
    }
  }
  // Reset the state tracker
  for(int i = 0; i < 5; ++i) {
      colours[i] = 0;
    }
    // By default, all the cells are in state 0
    colours[0] = gridSize * gridSize; 
}   

//public
Game::Game(): theGrid(NULL), gridSize(0), colours(), notification(NULL) {}
Game::~Game(){
  for (int i = 0; i < gridSize; ++i) {
    delete [] theGrid[i]; 
  }
  delete [] theGrid;
  theGrid = NULL;
}

void Game::notify(int r, int c, unsigned int oldState, unsigned int newState) {
  colours[oldState]--;
  colours[newState]++;
  notification->notify(r, c, newState);
}
  
bool Game::isWon() { 
  for (int i = 0; i < 5; ++i) {
    if (colours[i] == gridSize * gridSize) {
      return true;
    } 
  }
  return false;
}

void Game::init(int n, GameNotification *gameNotification) {
    // clear old grid
    if (theGrid) {
      clearGame();
    }
    // create an empty grid
    gridSize = n;
    theGrid = new Cell*[gridSize];
    for (int i = 0; i < gridSize; ++i) {
      theGrid[i] = new Cell[gridSize];
    }

    notification = gameNotification;
    
    for(int i = 0; i < 5; ++i) {
      colours[i] = 0;
    }
    // By default, all the cells are in state 0
    colours[0] = n * n; 

    // Set coordinate of each cell
    for (int r = 0; r < gridSize; ++r) {
      for (int c = 0; c < gridSize; ++c) {
        theGrid[r][c].setCoords(r, c);
        theGrid[r][c].setGame(this);
        if (r == 0) {
          // The first row
          if (c == 0) {
            // (0, 0) neighbour: (0, 1), (1, 0)
            theGrid[r][c].addNeighbour(theGrid[r] + 1); 
            theGrid[r][c].addNeighbour(theGrid[r + 1]);
          } else if (c == gridSize - 1) {
            // (0, n - 1) neighbour: (0, n-2), (1, n - 1)
            theGrid[r][c].addNeighbour(theGrid[r] + c - 1);
            theGrid[r][c].addNeighbour(theGrid[r + 1] + c);
          } else {
            // (0, x) neighbour: (0, x-1), (1, x), (0, x+1)
            theGrid[r][c].addNeighbour(theGrid[r] + c - 1);
            theGrid[r][c].addNeighbour(theGrid[r + 1] + c);
            theGrid[r][c].addNeighbour(theGrid[r] + c + 1);
          }
        } else if (r == gridSize - 1) {
          // The last row
          if (c == 0) {
            // (n - 1, 0) neighbour: (n - 2, 0), (n - 1, 1)
            theGrid[r][c].addNeighbour(theGrid[r - 1] + c); 
            theGrid[r][c].addNeighbour(theGrid[r] + c + 1);
          } else if (c == gridSize - 1) {
            // (n - 1, n - 1) neighbour: (n - 1, n - 2), (n - 2, n - 1)
            theGrid[r][c].addNeighbour(theGrid[r] + c - 1);
            theGrid[r][c].addNeighbour(theGrid[r - 1] + c);
          } else {
            // (n - 1, x) neighbour: (n - 1, x-1), (n - 2, x), (n - 1, x+1)
            theGrid[r][c].addNeighbour(theGrid[r] + c - 1);
            theGrid[r][c].addNeighbour(theGrid[r - 1] + c);
            theGrid[r][c].addNeighbour(theGrid[r] + c + 1);
          }
        } else if (c == 0) {
          // First column inner row
          // (x, 0) neighbour: (x - 1, 0), (x, 1), (x + 1, 0)
          theGrid[r][c].addNeighbour(theGrid[r - 1] + c);
          theGrid[r][c].addNeighbour(theGrid[r] + c + 1);
          theGrid[r][c].addNeighbour(theGrid[r + 1] + c);
        } else if (c == gridSize - 1) {
          // Last column inner row
          // (x, n - 1) neighbour: (x - 1, n - 1), (x, n - 2), (x + 1, n - 1)
          theGrid[r][c].addNeighbour(theGrid[r - 1] + c);
          theGrid[r][c].addNeighbour(theGrid[r] + c - 1);
          theGrid[r][c].addNeighbour(theGrid[r + 1] + c);
        } else {
          // Inner cell
          // (r, c) neighbour: (r - 1, c), (r + 1, c), (r, c - 1), (r, c + 1)
          theGrid[r][c].addNeighbour(theGrid[r - 1] + c);
          theGrid[r][c].addNeighbour(theGrid[r + 1] + c);
          theGrid[r][c].addNeighbour(theGrid[r] + c - 1);
          theGrid[r][c].addNeighbour(theGrid[r] + c + 1);
        }
      }  // for c
    }  // for r
}

void Game::change(const int & c) {  
  theGrid[0][0].notify(c);
}  

bool Game::isValid(int r, int c, unsigned int state) {
  if (r < 0 || r >= gridSize || c < 0 || c >= gridSize) {
    return false;
  } else if (state > 4) {
    return false;
  }
  return true;
}

void Game::init(int r, int c, int change){
  if (isValid(r, c, change)) {
    // Set the initial state for the cell
    theGrid[r][c].setState(change);
    if (change != 0) {
      colours[0]--;
      colours[change]++;
    }
    // Notify the view the change of the state
    notification->notify(r, c, change);
  }
} 

