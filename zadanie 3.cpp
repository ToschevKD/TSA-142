#include <iostream>
using namespace std;
/**
 * Функция для расчета времени, за которое путник одолел первую половину пути
 * @param t1 Время движения первой части пути
 * @param v1 Скорость движения первой части пути
 * @param t2 Время движения второй части пути
 * @param v2 Скорость движения второй части пути
 * @param t3 Время движения третьей части пути
 * @param v3 Скорость движения третьей части пути
 * @return Время, за которое путник одолел первую половину пути
 */
double calculateFirstHalfTime(double t1, double v1, double t2, double v2, double t3, double v3) {
    double totalDistance = (t1 * v1) + (t2 * v2) + (t3 * v3);
    double halfDistance = totalDistance / 2.0;

    double firstHalfTime = 0.0;
    double distanceCovered = 0.0;

    // Рассчитываем время для движения до достижения половины пути
    if (halfDistance <= (t1 * v1)) {
        firstHalfTime = halfDistance / v1;
    } else if (halfDistance <= ((t1 * v1) + (t2 * v2))) {
        firstHalfTime = t1 + ((halfDistance - (t1 * v1)) / v2);
    } else {
        firstHalfTime = t1 + t2 + ((halfDistance - (t1 * v1) - (t2 * v2)) / v3);
    }

    return firstHalfTime;
}

int main() {
    double t1, v1, t2, v2, t3, v3;

    cout << "Введите время t1 и скорость v1 для первой части пути: ";
    cin >> t1 >> v1;

    cout << "Введите время t2 и скорость v2 для второй части пути: ";
    cin >> t2 >> v2;

    cout << "Введите время t3 и скорость v3 для третьей части пути: ";
    cin >> t3 >> v3;

    double firstHalfTime = calculateFirstHalfTime(t1, v1, t2, v2, t3, v3);
    cout << "Время, за которое путник одолел первую половину пути: " << firstHalfTime << " часов" << endl;

    return 0;
}
