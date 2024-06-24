#include <iostream>
#include <cmath>
#include <limits>
using namespace std;
/
*@brief Считывает значиния с клавиатуры с проверкой ввода
*@return возвращает значение, если оно правильное , иначе завершает программу
*/
double getValue();

/
*@brief  Функция для вычисления значения функции y = sin(log(x))-cos(log(x))+2*log(x)
*@return sin(log(x))-cos(log(x))+2*log(x)
*/
double calculateFunction(const double x);

/**
*@brief  точка хода в программу
*@return 0
*/
int main()
{
    setlocale(LC_ALL, "Russian");

    cout << "Введите начальное значение x: ";
    double startX = getValue();

    cout << "Введите конечное значение x: ";
    double endX = getValue();

    if (startX > endX)
    {
        cout << "Ошибка: xstart должно быть меньше, чем xend" << endl;
        return 1;
    }

    cout << "Введите шаг: ";
    double step = getValue();
    if (abs(step) <=  -numeric_limits<double>::epsilon()) 
    {
        cout << "Ошибка." << endl;
        return 1; 
    }

   
    cout <<"x | y" << endl;
   for (double x = startX; x < endX + step; x += step)
    {
         if (x<0)
        {
            cout<<"x должно быть положительным числом";
            return 1;
        }
        else
        {
        double y = calculateFunction(x);
        cout << x << " | " << y << endl; 
        }
    }

    return 0;
}

double getValue()
{
    double value;
    cin >> value;
    if (cin.fail())
    {
        cout << "Некорректное значение" << endl;
        abort();
    }
    return value;
}

double calculateFunction(const double x)
{
    
    return sin(log(x))-cos(log(x))+2*log(x);
}
