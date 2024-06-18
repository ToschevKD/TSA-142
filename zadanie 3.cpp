#include <iostream>
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
    // Расчет расстояния, которое нужно пройти путнику
    double totalDistance = t1*v1 + t2*v2 + t3*v3;

    // Расчет времени для одоления первой половины пути
    double halfDistance = totalDistance / 2.0;
    double timeForHalf = 0.0;

    if (halfDistance <= t1*v1) {
        timeForHalf = halfDistance / v1;
    } else if (halfDistance <= t1*v1 + t2*v2) {
        timeForHalf = t1 + (halfDistance - t1*v1) / v2;
    } else {
        timeForHalf = t1 + t2 + (halfDistance - t1*v1 - t2*v2) / v3;
    }

    // Расчет времени для привала
    double timeForRest = t1 + t2 + t3;

    return make_pair(timeForHalf, timeForRest);
}

int main() {
    double t1, v1, t2, v2, t3, v3;

    // Ввод времени и скорости для каждого участка пути
    cout << "Введите время t1 и скорость v1 для первой части пути: ";
    cin >> t1 >> v1;

    cout << "Введите время t2 и скорость v2 для второй части пути: ";
    cin >> t2 >> v2;

    cout << "Введите время t3 и скорость v3 для третьей части пути: ";
    cin >> t3 >> v3;

    // Вызов функции для расчета времени для первой половины пути и времени для привала
    auto times = calculateTimes(t1, v1, t2, v2, t3, v3);

    // Вывод результатов
    cout << "Время, за которое путник одолел первую половину пути: " << times.first << " часов" << endl;

    return 0;
}
