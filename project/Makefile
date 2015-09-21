CXX = g++
CXXFLAGS = -Wall -MMD -lX11
EXEC = flood
OBJECTS = main.o controller.o textdisplay.o cell.o game.o view.o graphicdisplay.o window.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${OBJECTS} -o ${EXEC} ${CXXFLAGS}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
