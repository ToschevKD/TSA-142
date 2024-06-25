#include <iostream>
#include <cmath>
#include <limits>
using namespace std;

/*
 * @brief Рассчитывает сумму первых N членов последовательности
 * @param n Число членов последовательности
 * @return Значение суммы
 */
double sumN(const int n);

/*
 * @brief Рассчитывает сумму всех членов последовательности, модуль которых не меньше заданного числа e
 * @param e Заданное число e
 * @return Значение суммы
 */
double sumE(const double e);

/*
 * @brief Вычисляет текущий член последовательности
 * @param a Индекс члена
 * @return Значение текущего члена
 */
double getCurent(const int a);

int getValidN();

double getValidE();

/*
 * @brief Проверяет на корректность ввода
 * @return Введённое значение
 */
double getValue();

int main()
{
    const int n = getValidN();
    if (n == -1)
    {
        return 1; // Возвращаем код ошибки
    }

    cout << "Сумма первых " << n << " членов последовательности: " << sumN(n) << endl;

    const double e = getValidE();
    if (e == -1)
    {
        return 1; // Возвращаем код ошибки
    }

    cout << "Сумма всех членов последовательности, модуль которых не меньше " << e << ": " << sumE(e) << endl;

    return 0;
}

double getValue()
{
    double value;
    cin>>value;
    if (cin.fail())
    {
        cout<<"Некорректное значение"<<endl;
        abort();
    }
    return value;
}


int getValidN()
{   
    cout << "Введите значение n: ";
    int n = getValue();
    

    if ( n <= 0)
    {
        cout << "Ошибка: n должно быть положительным числом." << endl;
        return -1;
    }

    return n;
}


double getValidE()
{   
    cout << "Введите значение e (0 < e < 1): ";
    double e = getValue();
    

    if (e <= 0 or e > 1)
    {
        cout << "Ошибка: e должно быть положительным числом меньше 1." << endl;
        return -1;
    }

    return e;
}



double getCurent(const int a)
{
    return -1.0 / ((a + 1) * (a + 1));
}


double sumN(const int n)
{
    const double first = 1.0;
    double current = first;
    double result = current;
    for (int a = 0; a < n; a++)
    {
        current *= getCurent(a);
        result += current;
    }
    return result;
}


double sumE(const double e)
{
    const double first = 1.0;
    double current = first;
    double result = 0.0;
    for (int a = 0; abs(current) >= e + numeric_limits<double>::epsilon(); a++)
    {
        result += current;
        current *= getCurent(a);
    }
    return result;
}
