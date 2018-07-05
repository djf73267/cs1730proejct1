//
//  Matrix.h
//
//
//  Ryan Bechtel
//

#ifndef MATRIX_H
#define MATRIX_H

#include <initializer_list>

using namespace std;

typedef unsigned int uint;
typedef initializer_list<initializer_list<double>> i_list;

class Matrix {


 private:
  uint numberRows;
  uint numberCols;
  double** ptrMatrix;

 public:

  Matrix(uint rows, uint cols);

  Matrix(const i_list & list);

  Matrix(const Matrix & m);

  ~Matrix();

  Matrix add(double s) const;

  Matrix add(const Matrix & m) const;
  
  Matrix subtract(double s) const;

  Matrix subtract(const Matrix & m) const;

  Matrix multiply(double s) const;

  Matrix multiply(const Matrix & m) const;

  Matrix divide(double s) const;

  Matrix t() const;

  const uint numRows() const;

  const uint numCols() const;

  double & at(uint row, uint col);

  const double & at(uint row, uint col) const;

  Matrix operator+(double s) const;

  Matrix operator+(const Matrix & m) const;

  Matrix operator-(double s) const;

  Matrix operator-(const Matrix & m) const;

  Matrix operator*(double s) const;

  Matrix operator*(const Matrix & m) const;

  Matrix operator/(double s) const;

  Matrix operator=(const Matrix & m);

  Matrix operator=(const i_list & list);

  Matrix operator-() const;

  double & operator()(uint row, uint col);

  const double & operator()(uint row, uint col) const;

}; // Matrix

Matrix operator+(double s, Matrix & m);

Matrix operator-(double s, Matrix & m);

Matrix operator*(double s, Matrix & m);

Matrix operator/(double s, Matrix & m);

ostream & operator<<(ostream & out, const Matrix & m);

#endif
