#include <iostream>
using namespace std;
/**
 * @brief Функция для конвертации веса из граммов в унции
 * @param grams Значение веса в граммах
 * @return Значение веса в унциях
 */
float gramsToOunces(float grams) {
    float ounces = grams / 28.3;
    return ounces;
}

int main() {
    float weightInGrams;
    cout << "Введите значение веса в граммах: ";
    cin >> weightInGrams;

    float weightInOunces = gramsToOunces(weightInGrams);

    cout << "Вес в унциях: " << weightInOunces << std::endl;

    return 0;
}
