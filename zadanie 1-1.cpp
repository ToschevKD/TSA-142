#include <iostream>
#include <cmath>
using namespace std;
/**
 * @brief Функция getA вычисляет результат по формуле a = x * 2 + y - z.
 * 
 * @param x Первый аргумент для вычисления a.
 * @param y Второй аргумент для вычисления a.
 * @param z Третий аргумент для вычисления a.
 * @return Результат вычисления по формуле a = x * 2 + y - z.
 */
double getA(const double x, const double y, const double z);

/**
 * @brief Функция getB вычисляет результат по формуле b = x + y * 3 - z.
 * 
 * @param x Первый аргумент для вычисления b.
 * @param y Второй аргумент для вычисления b.
 * @param z Третий аргумент для вычисления b.
 * @return Результат вычисления по формуле b = x + y * 3 - z.
 */
double getB(const double x, const double y, const double z);

/**
 * @brief Главная функция программы.
 * 
 * @return 0 в случае успешного завершения программы.
 */
int main();
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
