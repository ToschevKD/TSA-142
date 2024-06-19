#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

void fillRandom(int* arr, int n) {
    for (int i = 0; i < n; ++i) {
        arr[i] = rand() % 100;
    }
}

void fillFromKeyboard(int* arr, int n) {
    for (int i = 0; i < n; ++i) {
        cout << "Введите элемент " << i << ": ";
        cin >> arr[i];
    }
}

void replaceLastKElem(int* arr, int n, int k) {
    if (k > n) {
        cout << "Ошибка: количество элементов для замены не может быть больше размера массива.\n";
        return;
    }
    for (int i = n - k; i < n; ++i) {
        arr[i] = -arr[i];
    }
}

void printIndexesIfMultiple(int* arr, int n, int num) {
    for (int i = 0; i < n; ++i) {
        if (arr[i] % num == 0) {
            cout << "Элемент с индексом " << i << " (" << arr[i] << ") кратен " << num << endl;
        }
    }
}

bool checkNeighbourPairSum(int* arr, int n, int targetSum) {
    for (int i = 0; i < n - 1; ++i) {
        if (arr[i] + arr[i + 1] == targetSum) {
            return true;
        }
    }
    return false;
}

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));

    int n;
    cout << "Введите размер массива: ";
    cin >> n;

    int* arr = new int[n];

    char choice;
    cout << "Заполнить массив случайными числами (R) или с клавиатуры (K)? ";
    cin >> choice;

    if (choice == 'R' || choice == 'r') {
        fillRandom(arr, n);
    } else if (choice == 'K' || choice == 'k') {
        fillFromKeyboard(arr, n);
    } else {
        cout << "Ошибка ввода!\n";
        delete[] arr; // Освобождение памяти
        return 1;
    }

    cout << "Исходный массив: ";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    int k;
    cout << "Введите количество последних элементов для замены: ";
    cin >> k;
    if (k > n) {
        cout << "Ошибка: количество элементов для замены не может быть больше размера массива.\n";
        delete[] arr; // Освобождение памяти
        return 1;
    }
    replaceLastKElem(arr, n, k);

    cout << "Массив после замены: ";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    int num;
    cout << "Введите число для проверки кратности: ";
    cin >> num;
    printIndexesIfMultiple(arr, n, num);

    int targetSum;
    cout << "Введите целевую сумму для поиска пары соседних элементов: ";
    cin >> targetSum;
    if (checkNeighbourPairSum(arr, n, targetSum)) {
        cout << "Найдена пара соседних элементов с суммой равной " << targetSum << endl;
    } else {
        cout << "Пары соседних элементов с суммой " << targetSum << " не найдено\n";
    }

    delete[] arr; // Освобождение памяти
    return 0;
}


    delete[] arr;
    return 0;
}
