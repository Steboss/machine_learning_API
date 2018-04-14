#include <iostream>
#include "simpleVector.h"
#include "../matrix/simpleMatrix.h"


using std::cout; using std::endl;

int main (){
  double **pMat = new double*[2];
  double *pVec = new double[3];
  for (int i =0; i< 2;i++){
    pMat[i] = new double[3];
    for(int j=0;j<3;j++){
      pMat[i][j] = (double) ((i+1)*(j+1)+j);
      pVec[j] = (double)(j+1);
    }
  }

  Matrix m(2,3,pMat);

  cout << "The matrix m" << endl;
  m.printMatrix();
  Vector v(3, pVec);
  cout << "The vector v" << endl;
  v.printVec();
  cout << "Product vector matrix"<< endl;
  (m*v).printVec();
  return 0 ;
}
