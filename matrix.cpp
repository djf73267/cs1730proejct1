//
//  Matrix.cpp
//
//
//  Ryan Bechtel
//

#include <iostream>
#include "matrix.h"

using namespace std;



Matrix::Matrix(uint rows, uint cols) {
  numberRows = rows;
  numberCols = cols;
  ptrMatrix = new double *[numberRows];

  for(uint i = 0; i < numberRows; i++) {
    ptrMatrix[i] = new double[numberCols];
  }

  for(uint i = 0; i < numberRows; i++) {
    for(uint j = 0; j < numberCols; j++) {
      ptrMatrix[i][j] = 0;
    } 
  }
}



Matrix::Matrix(const i_list & list) {
  numberRows = list.size();
  numberCols = list.begin()->size();
  ptrMatrix = new double *[numberRows];
  double var = 0;

  for(uint i = 0; i < numberRows; i++) {
    ptrMatrix[i] = new double[numberCols];
  }

  for(uint i = 0; i < numberRows; i++ ) {
    for(uint j = 0; j < numberCols; j++) {
      var = 0;
      var = *(list.begin()[i].begin()+j);
      ptrMatrix[i][j] = var;
    }
  }
}



Matrix::Matrix(const Matrix & m) {
  numberRows = m.numRows();
  numberCols = m.numCols();
  ptrMatrix = new double *[numberRows];
  double var = 0;
  
  for(uint i = 0; i < numberRows; i++) {
    ptrMatrix[i] = new double[numberCols];
  }

  for(uint i = 0; i < numberRows; i++) {
    for(uint j = 0; j < numberCols; j++) {
      var = 0;
      var = m.at(i, j);
      ptrMatrix[i][j] = var;
    }
  }  
}



Matrix::~Matrix() {
  for(uint i = 0; i < this->numRows(); i++) {
    delete[] ptrMatrix[i];
  }
  delete[] ptrMatrix;
}



Matrix Matrix::add(double s) const {
  Matrix tempMat(numberRows, numberCols);
  double var = 0;

  for(uint i = 0; i < numberRows; i++) {
    for(uint j = 0; j < numberCols; j++) {
      var = ptrMatrix[i][j];
      var += s;
      tempMat.at(i, j) = var;
    }
  }
  return tempMat;
}



Matrix Matrix::add(const Matrix & m) const {
  Matrix tempMat(numberRows, numberCols);
  double var = 0;

  for(uint i = 0; i < numberRows; i++) {
    for(uint j = 0; j < numberCols; j++) {
      var = ptrMatrix[i][j];
      var += m.at(i, j);
      tempMat.at(i, j) = var;
    }
  }
  return tempMat;
}



Matrix Matrix::subtract(double s) const {
  Matrix tempMat(numberRows, numberCols);
  double var = 0;

  for(uint i = 0; i < numberRows; i++) {
    for(uint j = 0; j < numberCols; j++) {
      var = ptrMatrix[i][j];
      var -= s;
      tempMat.at(i, j) = var;
    }
  }
  return tempMat;
}



Matrix Matrix::subtract(const Matrix & m) const {
  Matrix tempMat(numberRows, numberCols);
  double var = 0;

  for(uint i = 0; i < numberRows; i++) {
    for(uint j = 0; j < numberCols; j++) {
      var = ptrMatrix[i][j];
      var -= m.at(i, j);
      tempMat.at(i, j) = var;
    }
  }
  return tempMat;
}



Matrix Matrix::multiply(double s) const {
  Matrix tempMat(numberRows, numberCols);
  double var = 0;

  for(uint i = 0; i < numberRows; i++) {
    for(uint j = 0; j < numberCols; j++) {
      var = ptrMatrix[i][j];
      var *= s;
      tempMat.at(i, j) = var;
    }
  }
  return tempMat;
}



Matrix Matrix::multiply(const Matrix & m) const {
  uint r = numberRows;
  uint c = m.numCols();
  Matrix tempMat(r, c);
  double dot = 0, var = 0;

  for(uint i = 0; i < r; i++) {
    for(uint j = 0; j < c; j++) {
      dot = 0;
      for(uint x = 0; x < numberCols; x++) {
	var = 0;
	var = ptrMatrix[i][x] * m.at(x, j);
	dot += var;
      }
      tempMat.at(i, j) = dot;
    }
  }
  return tempMat;
}



Matrix Matrix::divide(double s) const {
  Matrix tempMat(numberRows, numberCols);
  double var = 0;
  
  for(uint i = 0; i < numberRows; i++) {
    for(uint j = 0; j < numberCols; j++) {
      var = ptrMatrix[i][j];
      var /= s;
      tempMat.at(i, j) = var;
    }
  }
  return tempMat;
}



Matrix Matrix::t() const {
  Matrix tempMat(numberCols, numberRows);
  double var = 0;

  for(uint i = 0; i < numberRows; i++) {
    for(uint j = 0; j < numberCols; j++) {
      var = 0;
      var = ptrMatrix[i][j];
      tempMat.at(j, i) = var;
    }
  }
  return tempMat;
}



const uint Matrix::numRows() const {
  return numberRows;
}



const uint Matrix::numCols() const {
  return numberCols;
}



double & Matrix::at(uint row, uint col) {
  return ptrMatrix[row][col];
}



const double & Matrix::at(uint row, uint col) const {
  return ptrMatrix[row][col];
}



Matrix Matrix::operator+(double s) const {
  return this->add(s);
}



Matrix Matrix::operator+(const Matrix & m) const {
  return this->add(m);
}



Matrix Matrix::operator-(double s) const {
  return this->subtract(s);
}



Matrix Matrix::operator-(const Matrix & m) const {
  return this->subtract(m);
}



Matrix Matrix::operator*(double s) const {
  return this->multiply(s);
}



Matrix Matrix::operator*(const Matrix & m) const {
  return this->multiply(m);
}



Matrix Matrix::operator/(double s) const {
  return this->divide(s);
}



Matrix Matrix::operator=(const Matrix & m) {
  numberRows = m.numRows();
  numberCols = m.numCols();
  for(uint i = 0; i < this->numRows(); i++) {
    delete[] ptrMatrix[i];
  }
  delete[] ptrMatrix;
  ptrMatrix = new double *[numberRows];
  
  for(uint i = 0; i < numberRows; i++) {
    ptrMatrix[i] = new double[numberCols];
  }

  for(uint i = 0; i < numberRows; i++) {
    for(uint j = 0; j < numberCols; j++) {
      ptrMatrix[i][j] = m.at(i,j);
    }
  }
  return *this;
}



Matrix Matrix::operator=(const i_list & list) {
  numberRows = list.size();
  numberCols = list.begin()->size();
  for(uint i = 0; i < this->numRows(); i++) {
    delete[] ptrMatrix[i];
  }
  delete[] ptrMatrix;
  ptrMatrix = new double *[numberRows];
  double var = 0;

  for(uint i = 0; i < numberRows; i++) {
    ptrMatrix[i] = new double[numberCols];
  }

  for(uint i = 0; i < numberRows; i++ ) {
    for(uint j = 0; j < numberCols; j++) {
      var = 0;
      var = *(list.begin()[i].begin()+j);
      ptrMatrix[i][j] = var;
    }
  }
  return *this;
}



Matrix Matrix::operator-() const {
  return this->multiply(-1);
}



double & Matrix::operator()(uint row, uint col) {
  return this->at(row, col);
}



const double & Matrix::operator()(uint row, uint col) const {
  return this->at(row, col);
}









Matrix operator+(double s, Matrix &m){ //overloading addition
  return m.add(s);
}//+ operator overload



Matrix operator-(double s, Matrix & m){ //overloading subtraction
  uint r = m.numRows();
  uint c = m.numCols();
  Matrix tempMat(r, c);
  double var = 0;
  
  for(uint i = 0; i < r; i++) {
    for(uint j = 0; j < c; j++) {
      var = 0;
      var = s - m.at(i, j);
      tempMat.at(i, j) = var;
    }
  }
  return tempMat;
}//- operator overload


 
Matrix operator*(double s, Matrix & m){ //overloading multiplication
  return m.multiply(s);
}//(*) operator overload



Matrix operator/(double s, Matrix & m){ //overloading division
  uint r = m.numRows();
  uint c = m.numCols();
  Matrix tempMat(r, c);
  double var = 0;
  
  for(uint i = 0; i < r; i++) {
    for(uint j = 0; j < c; j++) {
      var = 0;
      var = s / m.at(i, j);
      tempMat.at(i, j) = var;
    }
  }
  return tempMat;
}



ostream & operator<<(ostream & out, const Matrix & m) {
  for(uint i = 0; i < m.numRows(); i++){
    out << "[ ";        //prints bracket at beginning of row
    for(uint j = 0; j < m.numCols(); j++){
      out << m.at(i,j) << ((j == m.numCols() - 1) ? " " : ", ");       //iterates through values and prints them with space and comma in between
    }
    out << "]" << endl;  //prints bracket at end of row
  }
  return out;
}

