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
