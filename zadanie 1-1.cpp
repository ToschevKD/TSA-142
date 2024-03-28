#include <iostream>
#include <cmath>
using namespace std;
double getA(const double x, const double y, const double z);
double getB(const double x, const double y, const double z);
int main() {
  const double x=-2.9;
  const double y=15.5;
  const double z=1.5;
  cout << "x=" << x << "y=" << y << "z=" << z << endl;
         cout << "a=" << getA(x,y,z) << "b=" << getB(x,y,z) << endl;
return 0;
}
double getA(const double x, const double y, const double z)
{
  return sqrt(pow(x,2)+y)-pow(y,2)*pow(sin(x+z/x),3);
}
  double getB(const double x, const double y, const double z)
{
  return pow(cos(pow(x,3)),2)-x/sqrt(pow(z,2)+pow(y,2));
}
