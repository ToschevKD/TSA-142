#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <vector>
#include <cstring>
using namespace std;

/**
*@brief Считывает значиния с клавиатуры с проверкой ввода
* @return возвращает значение, если оно правильное, иначе завершает программу
*/
double getValue();

/**
* @brief Заполняет двумерный массив случайными значениями.
* @param array Указатель на двумерный массив.
* @param rows Количество строк в массиве.
* @param cols Количество столбцов в массиве.
*/
void fillArrayRandomly(int** array, const int rows, const int cols);

/**
 * @brief Заменяет минимальные элементы в каждом столбце двумерного массива на их противоположные значения.
 * @param arr Указатель на двумерный массив целых чисел.
 * @param max_rows Количество строк в массиве.
 * @param max_cols Количество столбцов в массиве.
 * @return Количество элементов, которые были изменены (заменены на противоположные).
 */
int replace_min_elements(int** arr, const int max_rows, const int max_cols);

/**
*brief Выводит двумерный массив на экран.
* @param  array Указатель на двумерный массив, в котором нужно заменить нулевые элементы.
* @param rows Количество строк в массиве.
* @param cols Количество столбцов в массиве
*/
void printArray(int** array, const int rows, const int cols);
/**
*@brief Создает новый двумерный массив с заданным количеством строк и столбцов.
* @param rows Количество строк в новом массиве.
* @param columns Количество столбцов в новом массиве.
* @return Указатель на новый двумерный массив типа int.
*/
int** getNewArray(const int rows, const int columns);

/**
*@brief Создает копию существующего двумерного массива с заданным количеством строк и столбцов.
* @param arr Указатель на существующий двумерный массив типа int, который нужно скопировать.
* @param rows Количество строк в существующем массиве.
* @param columns Количество столбцов в существующем массиве.
* @return Указатель на новую копию двумерного массива типа int.
*/
int** copyArray(int** arr, const int rows, const int columns);

/**
* @brief Освобождает память, выделенную под двумерный массив типа int.
* @param arr Указатель на двумерный массив типа int, который нужно освободить.
* @param rows Количество строк в двумерном массиве.
*/
void deleteArray(int** arr, const int rows);

/**
 * @brief Функция checkPositiveInput проверяет, является ли введенное значение положительным числом.
 * @param value - целочисленное значение, которое необходимо проверить
 * @return true, если значение положительное; false в противном случае
 */
bool checkPositiveInput(const int value);


/**
 * @brief Копирует содержимое одного двумерного массива в другой, расширяя его при необходимости.
 * @param arr1 Указатель на исходный двумерный массив целых чисел.
 * @param arr3 Указатель на целевой двумерный массив, куда будет скопировано содержимое arr1.
 * @param max_rows Количество строк в массиве arr1.
 * @param max_cols Количество столбцов в массиве arr1.
 * @param newcols Новое количество столбцов в массиве arr3 (если больше, чем max_cols).
 */
void copy_and_expand_array(int** arr1, int** arr3, const int max_rows, const int max_cols, const int newcols);

/**
 * @brief Функция getNumberOfCols считает количество столбцов, в которых элементы первой строки больше соответствующих элементов последней строки.
 * @param arr1 Указатель на двумерный массив целых чисел.
    * @param max_rows Количество строк в массиве.
     * @param max_cols Количество столбцов в массиве.
     * @return Количество столбцов, в которых элементы первой строки больше элементов последней строки.
     */
    int getNumberOfCols(int** arr1, int const max_rows, int const max_cols);


    /**
    *brief Точка входа в программу
    * return 0
    */
    int main()
    {
        setlocale(LC_ALL, "Russian");
        srand(time(0));

        cout << "Введите количество строк: ";
        int max_rows = getValue();
        cout << "Введите количество столбцов: ";
        int max_cols = getValue();
        if (checkPositiveInput(max_rows) && checkPositiveInput(max_cols))
        {
            cout << "Оба значения max_rows и max_cols положительные." << endl;
        }
        else
        {
            cout << "Одно из значений max_rows или max_cols не положительное." << endl;
            return 1;
        }

        int** arr1 = getNewArray(max_rows, max_cols);
        fillArrayRandomly(arr1, max_rows, max_cols);

        cout << "Случайно заполненный массив:" << endl;
        printArray(arr1, max_rows, max_cols);

        int** secondArr = copyArray(arr1, max_rows, max_cols);

        int modified_elements = replace_min_elements(arr1, max_rows, max_cols);
        cout << "Количество измененных элементов: " << modified_elements << endl;
        printArray(arr1, max_rows, max_cols);

        size_t newcols = max_cols - getNumberOfCols(arr1, max_rows, max_cols);
        int** arr3 = getNewArray(max_rows, static_cast<int>(newcols));
        copy_and_expand_array(arr1, arr3, max_rows, max_cols, static_cast<int>(newcols));


        modified_elements = replace_min_elements(arr3, max_rows, newcols);
        cout << "\nМассив после вставки строк из нулей после столбцов с максимальным по модулю элементом:" << endl;
        printArray(arr3, max_rows, newcols);
        cout << "Количество измененных элементов: " << modified_elements << endl;

            deleteArray(arr3, max_rows);
            deleteArray(secondArr, max_rows);
            deleteArray(arr1, max_rows);

            return 0;
        }

        bool checkPositiveInput(const int value)
        {
            if (value > 0)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        void fillArrayRandomly(int** array, int rows, int cols)
        {
            for (size_t i = 0; i < rows; ++i)
            {
                for (size_t j = 0; j < cols; ++j)
                {
                    array[i][j] = rand() - RAND_MAX / 2;
                }
            }
        }

        int replace_min_elements(int** arr, const int max_rows, const int max_cols)
        {
            int modified_elements = 0;

            for (size_t j = 0; j < max_cols; j++)
            {
                int min_element = arr[0][j];
                int min_index = 0;

                // Находим минимальный по модулю элемент в столбце
                for (size_t i = 1; i < max_rows; i++)
                {
                    if (abs(arr[i][j]) < abs(min_element))
                    {
                        min_element = arr[i][j];
                        min_index = i;
                    }
                }

                // Заменяем минимальный элемент на противоположный
                arr[min_index][j] = -min_element;
                        modified_elements++;
                    }

                    return modified_elements;
                }

                void printArray(int** array, int rows, int cols) 
                {
                    for (size_t i = 0; i < rows; ++i)
                    {
                        for (size_t j = 0; j < cols; ++j) 
                        {
                            cout << array[i][j] << " ";
                        }
                        cout << endl;
                    }
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

                int** getNewArray(const int max_rows, const int max_cols)
                {
                    int** array = new int* [max_rows];
                    for (size_t i = 0; i < max_rows; ++i)
                    {
                        array[i] = new int[max_cols];
                    }
                    return array;
                }

                int** copyArray(int** arr, const int rows, const int columns) 
                {
                    int** resultArray = getNewArray(rows, columns);
                    for (size_t i = 0; i < rows; i++)
                    {
                        for (size_t j = 0; j < columns; j++)
                        {
                            resultArray[i][j] = arr[i][j];
                        }
                    }
                    return resultArray;
                    }
void deleteArray(int** arr, const int rows) 
{
    for (size_t i = 0; i < rows; ++i) 
    {
        delete[] arr[i];
    }
    delete[] arr;
}

void copy_and_expand_array(int** arr1, int** arr3, const int max_rows, const int max_cols, const int newcols)
{
    for (size_t i = 0; i < max_rows; i++)
    {
        for (size_t j = 0; j < max_cols; j++)
        {
            arr3[i][j] = arr1[i][j];
        }
        for (size_t j = max_cols; j < newcols; j++)
        {
            arr3[i][j] = 0;
        }
    }
}

int getNumberOfCols(int** arr1, int const max_rows, int const max_cols)
{
    int count = 0;
    for (size_t j = 0; j < max_cols; j++)
    {
        if (arr1[0][j] > arr1[max_rows - 1][j])
        {
            count++;
        }
    }
    return count;
}

