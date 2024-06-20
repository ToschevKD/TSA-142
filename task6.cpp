#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <stdio.h>



using namespace std;

/**
 * @brief оператор выбоа способа заполнения массива
 * @param RANDOM = 0 автоматическое заполнение
 * @param MANUALLY =1 ручное заполнение
 */
enum SELECT
{
    RANDOM = 0,
    MANUALLY = 1
};

/**
 * @brief проверяет размер массива
 * @param n - размер массива
 */
void checkN(const int n);

/**
 * @brief считывает размер массива
 * @return размер массива в беззнаковом типе данных
 */
size_t getSize();

/**
 * @brief считывает значение типа int
 * @return считанное значение целочисленное
 */
int getNumber();

/**
 * @brief вывод массива на экран
 * @param arr - массив
 * @param n - размер массива
 */
void printArray(const int* arr, const int n);

/**
 * @brief заполнение массива автоматически случайнвми числами в заданном диапазоне
 * @param arr - массив
 * @param n - размер массива
 * @param min - минимальное значение диапазона значений элементов массива
 * @param max - максимальное значение диапазона значений элементов массива
 */
void fillArrayRandom(int* arr, const int n, const int min, const int max);

/**
 * @brief проверяет диапазон
 * @param min - минимальное значение диапазона значений элементов массива
 * @param max - максимальное значение диапазона значений элементов массива
 */
void checkRange(const int min, const int max);

/**
 * @brief  нахождение суммы четных элементов массива
 * @param arr - массив
 * @param n - размер массива
 * @return сумму четных элементов
 */
int sumEvenElements(int* arr, const int n);

/**
 * @brief  нахождение Количества элементов состоящих из двух значений
 * @param arr - массив
 * @param n - размер массива
 * @return количество двузначных чисел
 */
int countTwoDigitElements(int* arr, const int n);

/**
 * @brief замена последнего отрицательного числа на модуль первого элемента
 * @param arr - массив
 * @param n - размер массива
 */
void replaceLastNegativeElement(int* arr, const int n);

/**
 * @brief заполнение массива вручную
 * @param arr - массив
 * @param n - размер массива
 * @param min - минимальное значение диапазона значений элементов массива
 * @param max - максимальное значение диапазона значений элементов массива
 */
void fillArray(int* arr, const int n, const int min, const int max);



/**
* @brief точка входа в программу
* @return 0 - если программма выполнена корректно, инече -1
*/
int main()
{
    setlocale(LC_ALL, "Russian");

    int n = getSize();
    int* arr = new int[n];

    cout << "Введите минимальное и максимальное значение диапазона: ";
    int minValue = getNumber();
    int maxValue = getNumber();
    checkRange(minValue, maxValue);

    cout << "Введите выбор для заполнения массива: " << endl
        << RANDOM << " Для случайного заполнения" << endl
        << MANUALLY << " Для ручного заполнения" << endl;

    int choice = getNumber();

    switch (static_cast<SELECT>(choice))
    {
    case RANDOM:
        fillArrayRandom(arr, n, minValue, maxValue);
        break;
    case MANUALLY:
        fillArray(arr, n, minValue, maxValue);
        break;
    default:
        cout << "Ваш выбор неверен" << endl;
        delete[] arr;
        return -1;
    }

    cout << "Элементы массива:" << endl;
    printArray(arr, n);

    cout << "Сумма положительных элементов: " << sumEvenElements(arr, n) << endl;

    cout << "Количество элементов массива, значения которых состоят из двух цифр: " << countTwoDigitElements(arr, n) << endl;


    replaceLastNegativeElement(arr, n);

    delete[] arr;

    return 0;
}

void checkN(const int n)
{
    if (n <= 0)
    {
        cout << "Неправильный размер массива" << endl;
        abort();
    }
}

size_t getSize()
{
    cout << "Введите размер массива: ";
    int n;
    cin >> n;
    checkN(n);
    return (size_t)n;
}

int getNumber()
{
    int number;
    cin >> number;
    if (cin.fail())
    {
        cout << "Неправильный ввод данных";
        abort();
    }
    return number;
}

void printArray(const int* arr, const int n)
{
    for (size_t i = 0; i < n; i++)
    {
        cout << "arr[" << i << "] = " << arr[i] << endl;
    }
}

void fillArrayRandom(int* arr, const int n, const int min, const int max)
{
    srand(time(0));
    for (size_t i = 0; i < n; i++)
    {
        arr[i] = rand() % (max - min) + min;
    }
}


void checkRange(const int min, const int max)
{
    if (min > max)
    {
        cout << "Введен неправильный диапазон" << endl;
        abort();
    }
}




void fillArray(int* arr, const int n, const int min, const int max)
{
    for (size_t i = 0; i < n; i++)
    {
        cout << "Введите значение для arr[" << i << "]: ";
        arr[i] = getNumber();
        if (arr[i] < min || arr[i] > max)
        {
            cout << "Значение вне диапазона" << endl;
            i--;
        }
    }
}
int sumEvenElements(int* arr, const int n)
{
    int sum = 0;
    for (size_t i = 0; i < n; i++)
    {
        if (arr[i] % 2 == 0)
        {
            sum += arr[i];
        }
    }
    return sum;
}

int countTwoDigitElements(int* arr, const int n)
{
    int count = 0;
    for (size_t i = 0; i < n; i++)
    {
        if (abs(arr[i]) >= 10 && abs(arr[i]) <= 99)
        {
            count++;
        }
    }
    return count;

}

void replaceLastNegativeElement(int* arr, const int n) {
    int element = 0;
    int ielement = 0;
    for (size_t i = 0; i < n; i++) 
    {
        if (arr[i] < 0)
        {
            element = arr[i];
            ielement = i;
        }
    }
        arr[ielement] = abs(arr[0]);
    cout << "Массив после замены последнего отрицательного элемента на модуль первого элемента: ";
    for (size_t i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
