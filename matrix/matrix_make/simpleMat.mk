simpleMatrix : simpleMatDriver.o simpleMatrix.o
	g++ -Wall simpleMatDriver.o simpleMatrix.o -o simpleMatrix

simpleMatrix.o : simpleMatrix.cpp simpleMatrix.h
	g++ -c -Wall simpleMatrix.cpp

simpleMatDriver.o : simpleMatDriver.cpp simpleMatrix.h
	g++ -c -Wall simpleMatDriver.cpp
