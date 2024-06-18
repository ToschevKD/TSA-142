#include <iostream>
using namespace std;
/**
 * @brief Функция для перевода значения веса из граммов в унции
 * @param grams Значение веса в граммах
 * @return Значение веса в унциях
 */
double gramsToOunces(double grams) {
    return grams / 28.3;
}

int main() {
    double grams;
    cout << "Введите значение веса в граммах: ";
    cin >> grams;

    if (grams < 0) {
        cerr << "Ошибка: вес не может быть отрицательным\n";
        return 1;
    }

    double ounces = gramsToOunces(grams);
    cout << "Вес в унциях: " << ounces << endl;

    return 0;
}
