#include <iostream>
#include <cmath>
#include <limits>
using namespace std;
/**
*@brief Считывает значиния с клавиатуры с проверкой ввода
*@return возвращает значение, если оно правильное , иначе завершает программу
*/
double getValue();

/**
*@brief  Функция для вычисления значения функции y = cos(2/x) - 2*sin(1/x) + (1/x)
*@return cos(2/x) - 2*sin(1/x) + (1/x)
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
    if (step <=  -numeric_limits<double>::epsilon()) 
    {
        cout << "Ошибка." << endl;
        return 1; 
    }


    cout << "x | y" << endl;
    for (double x = startX; x < endX + step; x += step)
    {   if (x >= startX && x <= endX)
        {
            double y = calculateFunction(x);
            cout << x << " | " << y << endl;            
        }
        else
        {
            cout << "x за пределами заданного диапазона." << endl;
            break;
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
    return cos(2/x) - 2*sin(1/x) + (1/x);
}

