#include <iostream>
#include <initializer_list>
#include "matrix.h"


using namespace std;

int main() {

  Matrix x = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  Matrix y = {{2, 4, 6}, {8, 10, 12}, {14, 16, 18}};

  //Basic constructor test
  Matrix con1(2, 2);
  cout << "\nBasic constructor for 2x2 matrix" << endl;
  cout << con1 << endl;

  //i_list constructor test
  i_list list = {{10, 20}, {30, 40}};
  Matrix con2(list);
  cout << "i_list param constructor using {{10, 20}, {30, 40}}" << endl;
  cout << con2 << endl;

  //Copy constructor test
  Matrix con3(x);
  cout << "Copy constructor copying x into z" << endl;
  cout << "Matrix x:" << endl;
  cout << x << "Matrix z:" << endl;
  cout << con3 << endl;


  cout << "\nMatrix x and y will be used in the following demonstration:" << endl;
  cout << "\nMatrix x:\n" << x << "Matrix y:\n" << y << endl;

  //Add scalar
  Matrix add1 = x.add(10);
  cout << "Add 10 to x\n" << add1 << endl;

  //Add matrix object
  Matrix add2 = x.add(y);
  cout << "Add y to x\n" << add2 << endl;

  //Subtract scalar
  Matrix sub1 = y.subtract(5);
  cout << "Subtract 5 from y\n" << sub1 << endl;

  //Subtract matrix object
  Matrix sub2 = x.subtract(y);
  cout << "Subtract y from x\n" << sub2 << endl;

  //Multiply scalar
  Matrix mult1 = y.multiply(3);
  cout << "Multiply y by 3\n" << mult1 << endl;

  //Multiply matrix object
  Matrix mult2 = x.multiply(y);
  cout << "Multiply x by y\n" << mult2 << endl;

  //Divide scalar
  Matrix div = y.divide(2);
  cout << "Divide y by 2\n" << div << endl;

  //Transpose
  Matrix trans = x.t();
  cout << "Transpose x\n" << trans << endl;

  //numRows() and numCols() test
  cout << "\nnumRows and numCols test:\n" << endl;
  cout << "The number of rows in x is: " << x.numRows() << endl;
  cout << "The number of columns in x is: " << x.numCols() << endl;

  //at() test
  cout << "\n\nat() test:" << endl;
  cout << "\nThe value at 2, 2 in matrix x is: " << x.at(2, 2) << endl;
  cout << "We are going to change it to 69 using the at method" << endl;
  x.at(2, 2) = 69;
  cout << "The value at 2, 2 in matrix x is now: " << x.at(2, 2) << endl;
  cout << "But now let's change it back to 9" << endl;
  x.at(2, 2) = 9;
  cout << "The value at 2, 2 in matrix x is now: " << x.at(2, 2) << endl;

  //operator +
  Matrix a = x + 2.0;
  Matrix b = 4.0 + x;
  Matrix c = a + b;
  cout << "\n\nOverloaded + Operator Test:\n" << endl;
  cout << "a = x + 2\na:\n" << a << endl;
  cout << "b = 4 + x\nb:\n" << b << endl;
  cout << "c = a + b\nc:\n" << c << endl;
  
  //operator -
  Matrix d = x - 20;
  Matrix e = 2 - x;
  Matrix f = d - e;
  cout << "\nOverloaded - Operator Test:\n" << endl;
  cout << "d = x - 20\nd:\n" << d << endl;
  cout << "e = 2 - x\ne:\n" << e << endl;
  cout << "f = d - e\nf:\n" << f << endl;

  //operator *
  Matrix g = x * 2;
  Matrix h = 5 * x;
  Matrix i = g * h;
  cout << "\nOverloaded * Operator Test:\n" << endl;
  cout << "g = x * 2\ng:\n" << g << endl;
  cout << "h = 5 * x\nh:\n" << h << endl;
  cout << "i = g * h\ni:\n" << i << endl;

  //operator /
  Matrix j = x / 2;
  Matrix k = 60 / x;
  cout << "\nOverloaded / Operator Test:\n" << endl;
  cout << "j = x / 2\nj:\n" << j << endl;
  cout << "k = 60 / x\nk:\n" << k << endl;

  //operator =
  Matrix m(2, 2);
  Matrix l = {{29, 54, 99, 70}, {43, 19, 39, 10}};
  cout << "\nOverloaded = Operator Test:\n" << endl;
  cout << "l = {{29, 54, 99, 70}, {43, 19, 39, 10}}\nl:\n" << l << endl;
  cout << "m before assignment m = l:\n" << m << endl;
  m = l;
  cout << "m after assignment m = l:\n" << m << endl;

  //operator ()
  cout << "\nOverloaded () Operator Test:\n" << endl;
  cout << "Position (0,1) in m holds the value: " << m(0, 1) << endl;
  cout << "Position (1,2) in m holds the value: " << m(1, 2) << endl;

  //unary operator -
  cout << "\n\nOverlaoded - Unary Operator Test:\n" << endl;
  cout << "-m is as follows:\n" << -m << endl;

  //operator <<
  cout << "\nThis presentation has been brought to you in part by:" << endl;
  cout << "The Overloaded << Operator ;)\n" << endl;


  return 0;
}
