#include <iostream>
#include <ctime>
#include <cstdlib>

/**
* Функция для заполнения массива случайными числами
* @param arr - указатель на массив
* @param n - количество элементов в массиве
*/
void fillRandom(int* arr, int n) {
    for (int i = 0; i < n; ++i) {
        arr[i] = rand() % 100; // генерация случайных чисел от 0 до 99
    }
}

/**
* Функция для заполнения массива с клавиатуры
* @param arr - указатель на массив
* @param n - количество элементов в массиве
*/
void fillFromKeyboard(int* arr, int n) {
    for (int i = 0; i < n; ++i) {
        std::cout << "Введите элемент " << i << ": ";
        std::cin >> arr[i];
    }
}

/**
* Функция для замены последних k элементов массива на противоположные по знаку
* @param arr - указатель на массив
* @param n - количество элементов в массиве
* @param k - количество последних элементов, которые нужно изменить
*/
void replaceLastKElem(int* arr, int n, int k) {
    for (int i = n - k; i < n; ++i) {
        arr[i] = -arr[i];
    }
}

/**
* Функция для вывода индексов элементов, значения которых кратны num
* @param arr - указатель на массив
* @param n - количество элементов в массиве
* @param num - число, кратность которому проверяем
*/
void printIndexesIfMultiple(int* arr, int n, int num) {
    for (int i = 0; i < n; ++i) {
        if (arr[i] % num == 0) {
            std::cout << "Элемент с индексом " << i << " (" << arr[i] << ") кратен " << num << std::endl;
        }
    }
}

/**
* Функция для определения, есть ли пара соседних элементов с суммой, равной заданному числу
* @param arr - указатель на массив
* @param n - количество элементов в массиве
* @param targetSum - заданная сумма
* @return true, если такая пара существует, иначе false
*/
bool checkNeighbourPairSum(int* arr, int n, int targetSum) {
    for (int i = 0; i < n - 1; ++i) {
        if (arr[i] + arr[i + 1] == targetSum) {
            return true;
        }
    }
    return false;
}

int main() {
    srand(time(nullptr));

    int n;
    std::cout << "Введите размер массива: ";
    std::cin >> n;

    int* arr = new int[n];

    // Выбор метода заполнения массива
    char choice;
    std::cout << "Заполнить массив случайными числами (R) или с клавиатуры (K)? ";
    std::cin >> choice;

    if (choice == 'R' || choice == 'r') {
        fillRandom(arr, n);
    } else if (choice == 'K' || choice == 'k') {
        fillFromKeyboard(arr, n);
    } else {
        std::cout << "Ошибка ввода!\n";
        return 1;
    }

    // Вывод исходного массива
    std::cout << "Исходный массив: ";
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    // Замена последних k элементов на противоположные по знаку
    int k;
    std::cout << "Введите количество последних элементов для замены: ";
    std::cin >> k;
    replaceLastKElem(arr, n, k);

    // Вывод измененного массива
    std::cout << "Массив после замены: ";
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    // Поиск элементов, кратных num
    int num;
    std::cout << "Введите число для проверки кратности: ";
    std::cin >> num;
    printIndexesIfMultiple(arr, n, num);

    // Проверка наличия пары соседних элементов с суммой равной targetSum
    int targetSum;
    std::cout << "Введите целевую сумму для поиска пары соседних элементов: ";
    std::cin >> targetSum;
    if (checkNeighbourPairSum(arr, n, targetSum)) {
        std::cout << "Найдена пара соседних элементов с суммой равной " << targetSum << std::endl;
    } else {
        std::cout << "Пары соседних элементов с суммой " << targetSum << " не найдено\n";
    }

    delete[] arr;
    return 0;
}