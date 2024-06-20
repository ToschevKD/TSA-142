#include <iostream>
using namespace std;

/**
 * @brief Функция для перевода значения веса из граммов в унции
 * @param grams Значение веса в граммах
 * @return Значение веса в унциях
 */
double gramsToOunces(double grams) {
    return grams / 28.3; // более точное значение
}

int main() {
    double grams;
    cout << "Введите значение веса в граммах: ";
    cin >> grams;

    // Проверка на корректность ввода
    if (!cin) {
        cin.clear(); // Сбросить флаги ошибок
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Игнорировать оставшийся ввод до конца строки
        cerr << "Ошибка: введено нечисловое значение\n";
        return 1;
    }

    // Проверка на отрицательное значение веса
    if (grams < 0) {
        cerr << "Ошибка: вес не может быть отрицательным\n";
        return 1;
    }

    double ounces = gramsToOunces(grams);
    cout << "Вес в унциях: " << ounces << endl;

    return 0;
}

