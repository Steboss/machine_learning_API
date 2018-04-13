#include "simpleMatrix.h"
#include <iostream>

using std::cout; using std::endl;

int main () {
  //examples on how to use the matrix classes
  //initialize a matrix 2x2 with all the diagonal elems = 1
  Matrix m1(2,2,1);
  cout << "Initialization of an identity matrix"<< endl;
  m1.printMatrix();
  //initialize with a pointer
  double ** p =new double*[3]; //3 rows
  for(int i =0; i<3; i++){
    p[i] =new double[2]; //2 columns
    for (int j =0; j<2; j++){
      p[i][j] = (double)(i+1)*(j+1);
    }
  }
  Matrix* m2 = new Matrix(3,2,p);
  cout<< "Matrix initialize with a pointer, dimensions 3x2"<< endl;
  m2->printMatrix();
  return 0;
}
