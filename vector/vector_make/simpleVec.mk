simpleVector : simpleVecDriver.o simpleVector.o simpleMatrix.o
	g++ -Wall simpleVecDriver.o simpleVector.o simpleMatrix.o -o simpleVector

simpleVector.o : simpleVector.cpp simpleVector.h
	g++ -c -Wall simpleVector.cpp

simpleVecDriver.o : simpleVecDriver.cpp simpleVector.h
	g++ -c -Wall simpleVecDriver.cpp

simpleMatrix.o : ../matrix/simpleMatrix.cpp
	g++ -c -Wall ../matrix/simpleMatrix.cpp
