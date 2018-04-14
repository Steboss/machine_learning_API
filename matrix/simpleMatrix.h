#ifndef SIMPLEMATRIX_H
#define SIMPLEMATRIX_H

#include "../vector/simpleVector.h"

class Matrix{
  //class mameber
  int nRows, nCols;
  double** pA;
  void pointerCheck() const;
  void pointerCheck(int i ) const;

public:
  //constructor and destructors
  Matrix(int nrows=0, int ncols=0, double a= 0);
  Matrix(int nrows, int ncols, const double* const* pa);
  //copy constructor
  Matrix(const Matrix& A);
  //destructor
  ~Matrix();

  //define a "copy" operator
  Matrix& operator=(const Matrix& B);
  //define all the other operators to perform matrix arithmetics
  Matrix operator+(const Matrix& B) const;
  Matrix& operator+=(const Matrix& B);
  Matrix operator*(const Matrix& B) const;
  Matrix operator*(double b) const;
  Vector operator*(const Vector& v) const;
  const double* operator[](int i) const{return pA[i];}
  //define the transpose
  Matrix trans() const ;
  //print matrix
  void printMatrix() const;
  int getnRows() const {return nRows;}
  int getnCols() const {return nCols;}


};

Matrix operator*(double, const Matrix& A);
#endif
