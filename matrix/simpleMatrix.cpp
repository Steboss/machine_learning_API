#include <iostream>
#include <cstdlib>
#include <new>
#include "simpleMatrix.h"

using std::cout; using std::endl;

//constructor for a diagonal matrix with elements = a
Matrix::Matrix(int nrows, int ncols, double a){
  nRows=nrows;
  nCols = ncols;
  //set pA to null as a default case
  if (nRows==0 || nCols == 0 ){
    pA = 0;
    return ;
  }
  //initialize Rows
  pA = new(std::nothrow)  double*[nRows];
  pointerCheck();

  //initialise the Matrix
  for (int i = 0 ; i < nRows; i++){
    pA[i] = new(std::nothrow) double[nCols];
    pointerCheck(i);
    for(int j =0 ; j< nCols; j++){
      if(i==j){
        pA[i][j]=a;
      }
      else {
        pA[i][j] = 0;
      }
    }
  }
}


//Constructor for a general Matrix
Matrix::Matrix(int nrows, int ncols, const double* const* pa ){
  nRows = nrows;
  nCols = ncols;
  pA = new(std::nothrow) double*[nRows];
  pointerCheck();
  for (int i=0; i<nRows; i++){
    pA[i] = new(std::nothrow) double[nCols];
    pointerCheck(i);
  }
  for (int i =0; i<nRows; i++){
    for (int j =0; j<nCols;j++){
      pA[i][j] = pa[i][j];
    }
  }
}
//Copy constructor
Matrix::Matrix(const Matrix &A){
  nRows = A.nRows;
  nCols = A.nCols;
  pA = new(std::nothrow) double*[nRows];
  pointerCheck();
  for(int i=0;i<nRows;i++){
    pA[i] = new(std::nothrow) double[nCols];
    pointerCheck(i);
  }
  for(int i =0; i<nRows;i++){
    for(int j=0;j<nCols;j++){
      pA[i][j]=A.pA[i][j];
    }
  }
}

//overload the operator =
Matrix& Matrix::operator=(const Matrix& A){

  if (this ==&A) //self assignment
      return *this;

  if (nRows !=A.nRows || nCols!=A.nCols){
    if (pA!=0){
      this -> ~Matrix(); //destroy the current matrix
    }
    //redefine the matrix members and overwrite the matrix
    nRows = A.nRows;
    nCols = A.nCols;
    pA  = new(std::nothrow) double*[nRows];
    pointerCheck();
    for (int i= 0; i<nRows; i++){
      pA[i] = new(std::nothrow) double[nCols];
      pointerCheck(i);
    }
  }
  //copy the new matrix
  for (int i =0; i<nCols; i++){
    for (int j =0; j<nRows; j++){
      pA[i][j]= A.pA[i][j];
    }
  }
  return *this;
}
//Define the destructors
Matrix::~Matrix(){
  if(pA!=0){
    for (int i =0; i<nRows;i++){
      delete [] pA[i];
    }
    delete[] pA;
  }
}

//function to print the Matrix elements
void Matrix::printMatrix() const{
  for (int i =0; i<nRows; i++){
    for (int j =0;j<nCols;j++){
      cout << " "<< pA[i][j] << " ";
    }
    cout << endl;
  }
}

//check the pointer
void Matrix::pointerCheck() const {
  //if the pointer is null
  if(pA==0){
    cout << "Memory allocation failed" << endl;
    exit(1);
  }
}

void Matrix::pointerCheck(int i )const {
  if (pA[i]==0){
    cout << "Memory allocation for pA["<< i<< "] failed"<< endl;
    exit(1);
  }
}
//here define all the arithmetics

Matrix Matrix::operator+(const Matrix& B) const{
  if(nRows !=B.nRows || nCols !=B.nCols){
    cout << "Mismatch between dimensions, cannot perform addition for matrix dimensions" << nRows\
    << " x " << nCols << " and " << B.nRows << "  x " << B.nCols << endl;
    exit(1);
  }
  Matrix temp(nRows, nCols);
  for (int i =0; i<nRows; i++){
    for (int j=0; j<nCols ; j++){
      temp.pA[i][j] = this->pA[i][j] + B.pA[i][j];
    }
  }

  return temp;
}

Matrix& Matrix::operator+=(const Matrix& B){
  if(nRows !=B.nRows || nCols !=B.nCols){
    cout << "Mismatch between dimensions, cannot perform addition for matrix dimensions" << nRows\
    << " x " << nCols << " and " << B.nRows << "  x " << B.nCols << endl;
    exit(1);
  }

  for (int i =0; i<nRows; i++){
    for (int j=0; j<nCols ; j++){
      pA[i][j] += B.pA[i][j];
    }
  }

  return *this;
}

//multiplication
Matrix Matrix::operator*(const Matrix& B) const{
  if( nCols !=B.nRows){
    cout << "Mismatch between nCols and nRows, cannot perform multiplication for matrix dimensions" << nRows\
    << " x " << nCols << " and " << B.nRows << "  x " << B.nCols << endl;
    exit(1);
  }
  Matrix C(nRows, B.nCols); //matrix of zeroes

  for (int i =0; i<nRows; i++){
    for (int j=0; j<B.nCols ; j++){
      for (int k=0; k<B.nRows;k++){
        C.pA[i][j]+= pA[i][k]*B.pA[k][j];
      }
    }
  }
  return C;
}

Matrix Matrix::operator*(double b) const{
  Matrix C(nRows,nCols); //zeroes
  for(int i =0; i<nRows;i++){
    for (int j =0;j<nCols;j++){
      C.pA[i][j]=b*pA[i][j];
    }
  }
  return C;
}

Matrix operator*(double b, const Matrix& A ){
  return A*b;
}

//transpose
Matrix Matrix::trans() const{
  Matrix B(nCols, nRows, 0.0);
  for (int i =0; i<nRows; i++){
    for (int j =0 ; j< nCols ; j++){
      B.pA[i][j]=pA[i][j];
    }
  }
  return B;

}
