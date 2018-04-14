#ifndef VECTOR_H
#define VECTOR_H


class Vector{
  double *pA;
  int nRows;
  void pointerCheck() const;

public:

  Vector(int nrows=0, double b =0.0);
  Vector(int nrows, const double* pa);
  Vector(const Vector& v);
  ~Vector();

  Vector& operator=(const Vector& v);
  //overload
  Vector operator*(const Vector& v) const;

  double operator[](int i)const {return pA[i];}
  void printVec() const;
  int getnRows() const {return nRows;}

  //friend class
  friend class Matrix;
};

#endif
