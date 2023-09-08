#include <iostream> //int/o library
using namespace std; //instead od prefix std: :

int main() //header
  { //begin
  float a, res = 0; //declaration
  //input
  cout <<"A  = ";
  cin >> a;
  //calculation
  res = a + 5;
  //output
  cout << a << " + 5 = " << res << endl;

  system( "pause");
  return 0 ; //return to os
} //end