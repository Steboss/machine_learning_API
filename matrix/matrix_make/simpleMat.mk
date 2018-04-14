simpleMatrix : simpleMatDriver.o simpleMatrix.o simpleVector.o
	g++ -Wall simpleMatDriver.o simpleMatrix.o simpleVector.o -o simpleMatrix

simpleMatrix.o : simpleMatrix.cpp simpleMatrix.h
	g++ -c -Wall simpleMatrix.cpp

simpleMatDriver.o : simpleMatDriver.cpp simpleMatrix.h
	g++ -c -Wall simpleMatDriver.cpp

simpleVector.o : ../vector/simpleVector.cpp
	g++ -c -Wall ../vector/simpleVector.cpp
