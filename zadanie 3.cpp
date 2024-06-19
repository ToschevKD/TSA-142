#include <iostream>
#include <utility>
using namespace std;

/**
 * Функция для расчета времени, за которое путник одолеет первую половину пути
 * и время для планирования привала
 * 
 * @param t1 Время движения со скоростью v1
 * @param v1 Скорость движения во время t1
 * @param t2 Время движения со скоростью v2
 * @param v2 Скорость движения во время t2
 * @param t3 Время движения со скоростью v3
 * @param v3 Скорость движения во время t3
 * @return Время для одоления первой половины пути и время для привала
 */
pair<double, double> calculateTimes(double t1, double v1, double t2, double v2, double t3, double v3) {
    double totalDistance = t1 * v1 + t2 * v2 + t3 * v3;
    double halfDistance = totalDistance / 2.0;
    double timeForHalf = 0.0;
    double distanceCovered = 0.0;

    // Расчет времени для одоления первой половины пути
    if (halfDistance <= (distanceCovered += t1 * v1)) {
        timeForHalf = (halfDistance - (distanceCovered - t1 * v1)) / v1;
    } else if (halfDistance <= (distanceCovered += t2 * v2)) {
        timeForHalf = t1 + (halfDistance - (distanceCovered - t2 * v2)) / v2;
    } else {
        timeForHalf = t1 + t2 + (halfDistance - distanceCovered) / v3;
    }

    // Время для привала не изменяется, оно равно сумме всех времен
    double timeForRest = t1 + t2 + t3;

    return make_pair(timeForHalf, timeForRest);
}

int main() {
    double t1, v1, t2, v2, t3, v3;

    cout << "Введите время t1 и скорость v1 для первой части пути: ";
    if (!(cin >> t1 >> v1)) {
        cerr << "Ошибка: введено нечисловое значение для t1 или v1\n";
        return 1;
    }

    cout << "Введите время t2 и скорость v2 для второй части пути: ";
    if (!(cin >> t2 >> v2)) {
        cerr << "Ошибка: введено нечисловое значение для t2 или v2\n";
        return 1;
    }

    cout << "Введите время t3 и скорость v3 для третьей части пути: ";
    if (!(cin >> t3 >> v3)) {
        cerr << "Ошибка: введено нечисловое значение для t3 или v3\n";
        return 1;
    }

    auto times = calculateTimes(t1, v1, t2, v2, t3, v3);
    cout << "Время, за которое путник одолел первую половину пути: " << times.first << " часов" << endl;
    cout << "Время для привала: " << times.second << " часов" << endl;

    return 0;
}

