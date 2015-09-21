#include <iostream>
#include <sstream>
#include "view.h"
#include "textdisplay.h"

using namespace std;

//public
TextDisplay::TextDisplay(int n): View(n) {
  theDisplay = new char* [n];
  for (int i = 0; i < n; ++i) {  
    theDisplay[i] = new char[n];
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      theDisplay[i][j] = '0';
    }
  }
} 

TextDisplay::~TextDisplay() {
  for (int i = 0; i < gridSize; ++i) {
    delete [] theDisplay[i]; 
  }
  delete [] theDisplay;
  theDisplay = NULL;
}

void TextDisplay::notify(int r, int c, char ch) {
    theDisplay[r][c] = ch;
}

void TextDisplay::print(std::ostream &out) {
    for (int r = 0; r < gridSize; ++r) {
      for (int c = 0; c < gridSize; ++c) {
        cout << theDisplay[r][c];
      }
      cout << endl;
    }
  }

