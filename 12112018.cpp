#include <iostream>
#include <cmath>
using namespace std;

int main( )
{
try
{
double x;
cout << "Enter a number: ";
cin >> x;
if (x < 0) throw "Bad argument!";
cout<<"Square root of x"<< x <<" is "<< sqrt(x) << endl;
}
catch(char *str)
{
cout << str;
}
return 0;
}
