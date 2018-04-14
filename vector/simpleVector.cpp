#include <iostream>
#include <cstdlib>
#include <new>
#include "simpleVector.h"
#include "../matrix/simpleMatrix.h"

using std::cout; using std::endl;

Vector::Vector(int nrows, double b){
  nRows=nrows;
  if(nRows==0){
    pA= 0;
    return ;
  }

  pA=new(std::nothrow) double[nRows];
  pointerCheck();

  for(int i=0; i<nRows; i++){
    pA[i]=b;
  }

}

Vector::Vector(int nrows, const double* pa){
  nRows = nrows;
  pA=new(std::nothrow) double[nRows];
  pointerCheck();
  for(int i=0; i<nRows; i++){
    pA[i] = pa[i];
  }
}

Vector::Vector(const Vector& v){
  nRows = v.nRows;
  pA = new(std::nothrow) double[nRows];
  pointerCheck();
  for(int i =0; i< nRows; i++){
    pA[i] = v.pA[i];
  }
}

//destructor
Vector::~Vector(){
  if (pA!=0)
    delete [] pA;
}

Vector& Vector::operator=(const Vector& v){
  if(this==&v)
  {
    return *this;
  }

  if(nRows!=v.nRows){
    if(pA!=0){
      delete [] pA;
    }
    nRows= v.nRows;
    pA = new(std::nothrow)double [nRows];
    pointerCheck();
  }

  for (int i =0; i<nRows; i++){
    pA[i] = v.pA[i];
  }
  return *this;

}

void Vector::pointerCheck() const{
  if(pA==0){
    cout <<" Memory allocation error"<< endl;
    exit(1);
  }
}

void Vector::printVec() const{
  for(int i =0; i<nRows;i++){
    cout << " " << pA[i] << " " << endl;
  }
}
