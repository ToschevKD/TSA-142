#include <iostream>
using namespace std;
int main() {
  double t1, t2, t3, v1, v2, v3;
  double totalDistance;

  cout << "Напишите время пройденное со скоростью v1 (в часах): ";
  cin >> t1;
  cout << "Введите скорость v1 (в км/ч): ";
  cin >> v1;

  cout << "Напишите время пройденное со скоростью v2 (в часах): ";
  cin >> t2;
  cout << "Введите скорость v2 (в км/ч): ";
  cin >> v2;
  cout << "Напишите время пройденное со скоростью v3 (в часах): ";
  cin >> t3;
  cout << "Введите скорость v3 (в км/ч): ";
  cin >> v3;
  totalDistance = t1 * v1 + t2 * v2 + t3 * v3;
  double halfDistance = totalDistance / 2;
  double timeToHalfway = 0;
  if (halfDistance <= t1 *v1) {
    timeToHalfway = halfDistance / v1;
  } else if (halfDistance <= (t1 * v1) + (t2 * v2)) {
    timeToHalfway = t1 + (halfDistance - (t1 * v1)) / v2;
  } else {
    timeToHalfway = t1 + t2 + (halfDistance - t1 * v1 - t2 * v2) / v3;
  }
  cout << "Время до половины пути: " << timeToHalfway << " часов" << endl;
  return 0;
}