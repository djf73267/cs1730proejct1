//
//  matrix.cpp
//  
//
//  Created by julianamickey on 7/1/18.
//

#include "matrix.h"

Matrix::Matrix(unsigned int rows, unsigned int cols){ //constructor all elements initialized to 0
  numberOfRows = rows;
  numberOfCols = cols;
  ptrMatrix = new double * [rows];
  for (unsigned int x = 0; x < rows; x++){
    ptrMatrix[x] = new double [cols];
  }//for

  for(int i = 0; i < rows; i++){
    for(int j =0; j < cols; j++){
      ptrMatrix[i][j] = 0;
    }//for
  }//for
}//matrix constructor1

Matrix::Matrix (const std::initializer_list<std::initializer_list<double>> & list){ //constructor using intializer list
  numberRows = list.size();
  numberCols = list.begin()-> size();
  for(int i = 0; i < size; i++){
    ptrMatrix[i] = new double[size];
  }
  for(int i = 0; i < numberRows; i+++){
    for(int j = 0; j < numberCols; j++){
      double var = 0;
      var = *(list.begin()[i].begin() + j);
      ptrMatrix[i][j] = var;
    }
  }
}//matrix constructor2

Matrix::Matrix(const Matrix & m){ //copy constructor
  numberRows = m.numRows();
  numberCols = m.numCols();
  ptrMatrix = new double *[numberRows];

  for(unsigned int i = 0; i < numberRows; i++){
    ptrMatrix[i] = new double [numberCols];
  }//for

  for(unsigned int i = 0; i < numberRows; i++){
    for(unsigned int j = 0; j < numberCols; j++){
      ptrMatrix[i][j] = m.at(i,j);
    }//for
  }//for
}//matrix constructor

~Matrix(){
  delete [] ptrMatrix;
}//destructor

Matrix Matrix::add(double s) const{//add scalar value to the matrix
  Matrix tempMat(numberRows, numberCols);
  for(unsigned int i = 0; i < numberRows; i++){
    for(unsigned j = 0; j < numberCols; j++){
      double var = ptrMatrix[i][j];
      var += s;
      tempMat.at(i,j) = var;
    }//for
  }//for
  return tempMat;
}//add function

Matrix Matrix::add(const Matrix & m) const{//add this matrix and another matrix
  Matrix tempMat(numberRows, numberCols);
  for(unsigned int i = 0; i < numberRows; i++){
    for(unsigned j = 0; j < numberCols; j++){
      double var = ptrMatrix[i][j];
      var += m.at(i,j);
      tempMat.at(i,j) = var;
    }//for
  }//for
  return tempMat;
}//add method

Matrix Matrix::subtract(double s) const{//subtract scalar from this matrix
  Matrix tempMat(numberRows, numberCols);
  for(unsigned int i = 0; i < numberRows; i++){
    for(unsigned j = 0; j < numberCols; j++){
      double var = ptrMatrix[i][j];
      var -= s;
      tempMat.at(i,j) = var;
    }//for
  }//for
  return tempMat;
}//subtract

Matrix Matrix::subtract(const Matrix & m) const{//subtract salar from this matrix
  Matrix tempMat(numberRows, numberCols);
  for(unsigned int i = 0; i < numberRows; i++){
    for(unsigned j = 0; j < numberCols; j++){
      double var = ptrMatrix[i][j];
      var -= m.at(i,j);
      tempMat.at(i,j) = var;
    }//for
  }//for
  return tempMat;
}//subtract

Matrix Matrix::multiply(double s) const{//multiply this matrix by scalar
  Matrix tempMat(numberRows, numberCols);
  for(unsigned int i = 0; i < numberRows; i++){
    for(unsigned j = 0; j < numberCols; j++){
      double var = ptrMatrix[i][j];
      var *= s;
      tempMat.at(i,j) = var;
    }//for
  }//for
  return tempMat;
}//multiply

Matrix Matrix::multiply(const Matrix & m) const{//multiply this matrix by a scalar
  Matrix tempMat(numberRows, numberCols);
  double dot = 0, var = 0;
  for(unsigned int i = 0; i < numberRows; i++){
    for(unsigned j = 0; j < numberCols; j++){
      dot = 0;
      for(unsigned int x = 0; x < numberCols; x++){
	var = 0;
	var = ptrMatrix[i][x] * m.at(x,j);
	dot += var;
      }
      tempMat.at(i,j) = dot;
    }//for
  }//for
  return tempMat;
}//multiply

Matrix Matrix::divide(double s) const{//divide this matrix by a scalar
  Matrix tempMat(numberRows, numberCols);
  for(unsigned int i = 0; i < numberRows; i++){
    for(unsigned j = 0; j < numberCols; j++){
      double var = ptrMatrix[i][j];
      var /= s;
      tempMat.at(i,j) = var;
    }//for
  }//for
  return tempMat;
}//divide

Matrix Matrix::t() const{//transpose this matrix
  Matrix tempMat(numberRows, numberCols);
  for(int row = 0; row < numberRows; row++){
    for(int col = 0; col < numberCols; col++){
      double var = 0;
      var = ptrMatrix[col][row];
      tempMat.at(row,col) = var;
    }
    return tempMat;
  }
}//transpose

const unsigned int Matrix::numRows() const{//returns the number of rows
  return numberRows;
}//numRows

const unsigned int Matrix::numCols() const{//returns the number of columns
  return numberCols;
}//numCols

double & Matrix::at(unsigned int row, unsigned int col){//get/s operator overload

  Matrix Matrix::operator*(double number){ //overloading multiplication operator
    return multiply(number);
  }//* operator overload

  Matrix Matrix::operator/(double number){ //overloading addition operator
        returween
	  }
  out << "]" << end;  //prints bracket at end of row
}
return out;
}



//nonmember overloaded functions

Matrix operator+(double number, Matrix &m){ //overloading addition operator
  return m.add(number);
}//+ operator overload

Matrix operator-(double number, Matrix //
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
  ptrMatrix = new double*[rows];

  for(uint i = 0; i < rows; i++) {
    ptrMatrix[i] = new double[cols];
  }

  for(uint i = 0; i < rows; i++) {
    for(uint j = 0; i < cols; j++) {
      ptrMatrix[i][j] = 0;
    } 
  }
}



Matrix::Matrix(const i_list & list) {
  numberRows = list.size();
  numberCols = list.begin()->size();
  ptrMatrix = new double*[numberRows];

  for(uint i = 0; i < numberRows; i++) {
    ptrMatrix[i] = new double[numberCols];
  }

  for(uint i = 0; i < numberRows; i++ ) {
    for(uint j = 0; j < numberCols; j++) {
      double var = 0;
      var = *(list.begin()[i].begin()+j);
      ptrMatrix[i][j] = var;
    }
  }
}



Matrix::Matrix(const Matrix & m) {
  numberRows = m.numRows();
  numberCols = m.numCols();
  ptrMatrix = new double *[numberRows];
  for(uint i = 0; i < numberRows; i++) {
    for(uint j = 0; j < numberCols; j++) {
      ptrMatrix[i][j] = m.at(i,j);
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
  for(uint i = 0; i < numberRows; i++) {
    for(uint j = 0; j < numberCols; j++) {
      double var = ptrMatrix[i][j];
      var += s;
      tempMat.at(i, j) = var;
    }
  }
  return tempMat;
}



Matrix Matrix::add(const Matrix & m) const {
  Matrix tempMat(numberRows, numberCols);
  for(uint i = 0; i < numberRows; i++) {
    for(uint j = 0; j < numberCols; j++) {
      double var = ptrMatrix[i][j];
      var += m.at(i, j);
      tempMat.at(i, j) = var;
    }
  }
  return tempMat;
}



Matrix Matrix::subtract(double s) const {
  Matrix tempMat(numberRows, numberCols);
  for(uint i = 0; i < numberRows; i++) {
    for(uint j = 0; j < numberCols; j++) {
      double var = ptrMatrix[i][j];
      var -= s;
      tempMat.at(i, j) = var;
    }
  }
  return tempMat;
}



Matrix Matrix::subtract(const Matrix & m) const {
  Matrix tempMat(numberRows, numberCols);
  for(uint i = 0; i < numberRows; i++) {
    for(uint j = 0; j < numberCols; j++) {
      double var = ptrMatrix[i][j];
      var -= m.at(i, j);
      tempMat.at(i, j) = var;
    }
  }
  return tempMat;
}



Matrix Matrix::multiply(double s) const {
  Matrix tempMat(numberRows, numberCols);
  for(uint i = 0; i < numberRows; i++) {
    for(uint j = 0; j < numberCols; j++) {
      double var = ptrMatrix[i][j];
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
  for(uint i = 0; i < numberRows; i++) {
    for(uint j = 0; j < numberCols; j++) {
      double var = ptrMatrix[i][j];
      var /= s;
      tempMat.at(i, j) = var;
    }
  }
  return tempMat;
}



Matrix Matrix::t() const {
  Matrix tempMat(numberCols, numberRows);
  for(uint i = 0; i < numberRows; i++) {
    for(uint j = 0; j < numberCols; j++) {
      double var = 0;
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
