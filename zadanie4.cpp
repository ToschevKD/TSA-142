#include <iostream>
#include <cmath>
#include <limits>
using namespace std;

/**
*@brief Считывает значиния с клавиатуры с проверкой ввода
*@brief  Функция для вычисления значения функции y = cos(2/x) - 2*sin(1/x) + (1/x)
*@return cos(2/x) - 2*sin(1/x) + (1/x)
*@brief  точка хода в программу
*@return возвращает значение, если оно правильное , иначе завершает программу
*@return 0
*/
double getValue();

double calculateFunction(const double x);

int main()
{
    setlocale(LC_ALL, "Russian");

    cout << "Введите начальное значение x: ";
    double startX = getValue();

    cout << "Введите конечное значение x: ";
    double endX = getValue();

    if (startX > endX)
    {
        cout << "Ошибка: начальное значение x должно быть меньше, чем конечное значение x." << endl;
        return 1;
    }

    cout << "Введите шаг: ";
    double step = getValue();
    if (step <= 0) 
    {
        cout << "Ошибка: шаг должен быть больше нуля." << endl;
        return 1; 
    }

    cout << "x | y" << endl;
    for (double x = startX; x <= endX; x += step)
    {
        double y = calculateFunction(x);
        cout << x << " | " << y << endl;
    }

    return 0;
}

double getValue()
{
    double value;
    while (!(cin >> value))
    {
        cin.clear(); // очистка флагов ошибки потока
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // игнорирование оставшихся символов в потоке
        cout << "Некорректное значение. Пожалуйста, введите число: ";
    }
    return value;
}

double calculateFunction(const double x)
{
    if (x == 0) {
        cout << "Ошибка: деление на ноль." << endl;
        abort();
    }
    return cos(2/x) - 2*sin(1/x) + (1/x);
}

