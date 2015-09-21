#include <iostream>
#include "graphicdisplay.h"

GraphicDisplay::GraphicDisplay(int n): View(n) {
	//Create default white rectangles
	int length = 500 / n;
	for (int r = 0; r < n; ++r) {
		for (int c = 0; c < n; ++c) {
			xw.fillRectangle(length * r, length * c, length, length, Xwindow::White);
		}
	}
}

GraphicDisplay::~GraphicDisplay() {}

void GraphicDisplay::notify(int r, int c, char ch) {
	int length = 500 / gridSize;
	xw.fillRectangle(length *  r, length * c, length, length, ch - '0');
}

void GraphicDisplay::print(std::ostream &) {}
