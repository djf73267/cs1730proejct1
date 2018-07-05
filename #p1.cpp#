#include <iostream>
#include <initializer_list>
#include "matrix.h"


using namespace std;

int main() {

  Matrix x = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  Matrix y = {{2, 4, 6}, {8, 10, 12}, {14, 16, 18}};
  Matrix z = {{0, 0.5, 1}, {1.5, 2, 2.5}, {3, 3.5, 4}};

  //Basic constructor test
  Matrix a(2, 2);

  //i_list constructor test
  i_list list = {{10, 20}, {30, 40}};
  Matrix b(list);

  //Copy constructor test
  Matrix c(x);

  //Destructor test
   
  
  //Add scalar
  Matrix d = x.add(10);
  
  //Add matrix object
  Matrix e = x.add(y);
  
  //Subtract scalar
  Matrix f = y.subtract(10);
  
  //Subtract matrix object
  Matrix g = y.subtract(z);
  
  //Multiply scalar
  Matrix h = y.multiply(2);
  
  //Multiply matrix object
  Matrix i = x.multiply(z);
  
  //Divide scalar
  Matrix j = y.divide(2);
  
  //Transpose
  Matrix k = x.t();
  
  //numRows() test
  cout << a.numRows() << endl;
  cout << x.numRows() << endl;  

  //numCols() test
  cout << b.numCols() << endl;
  cout << y.numCols() << endl;

  //at() test
  cout << "The value at 3, 3 in matrix x is: " << x.at(3, 3) << endl;
  cout << "We are going to change it to 69 before the next line." << endl;
  x.at(3, 3) = 69;
  cout << "The value at 3, 3 in matrix x is: " << x.at(3, 3) << endl;
  


  return 0;
}
