#include <iostream>

int main() {
  double grams, ounces;
  //Ввод значения веса в граммах
  std::cout <<"Введите значение в граммах: ";
  std::cin>>grams;

  //Перевод веса из граммов в унции
  ounces=grams/28.3;

  //Вывод результата
  std::cout <<"Вес в унциях: "<<ounces<<std::endl;
  return 0; 
}
