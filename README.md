#Flood It
A one-player game written in C++. The player changes the color of the top-left cell (master cell)repeatedly. In response, all neighbouring cells of the master cell will change color if they were in the same color as the master cell. The goal of the game is to make all the cells in the grid have the same color before running out of the moves. A graphical display is provided to make the game more intuitive.

To compile: “make”

To run: “./flood” for textual display or “./flood -graphics” for graphical display

To play:  
new n: Creates a new n by n grid.  
init: Enters initialization mode.  
include f: Includes a file f which is a list of cell initializations of the same format of initialization from init.  
game g: Once the board has been initialized, this command starts a new game, with a commitment to solve the game in g moves or fewer (g > 0).  
switch s: Within a game, switches the top-left cell to s, changes all appropriate neighbours, and then redisplays the grid.  0-white, 1-black, 2-red, 3-green, 4-blue.
