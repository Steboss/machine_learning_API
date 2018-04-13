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
  double ** p =new double*[2]; //3 rows
  for(int i =0; i<2; i++){
    p[i] =new double[2]; //2 columns
    for (int j =0; j<2; j++){
      p[i][j] = (double)(i+1)*(j+1);
    }
  }
  Matrix* m2 = new Matrix(2,2,p);
  cout<< "Matrix initialize with a pointer, dimensions 2x2"<< endl;
  m2->printMatrix();

  Matrix m3;
  m3 = m1 ;
  cout << "Copy matrix 1 to new one with = "<< endl;
  m3.printMatrix();
  cout << "Sum of matrix 1 and 3" << endl;
  (m3+m1).printMatrix();
  cout << "Product between matrix 3 and matrix 1"<<endl;
  (m3*m1.trans()).printMatrix();
  cout << "Moltiplication of matrix 3 with number 2"<<endl;
  (2*m3).printMatrix();
  cout << "Index operator [1][1]"<< m1[1][1] << endl;


  return 0;
}
