#include <iostream> 
#include <limits>
using namespace std; 

/** 
*@brief Считывает значиния с клавиатуры с проверкой ввода 
*@return возвращает значение, если оно правильное , иначе завершает программу 
*/ 
double getValue();

/**
*@brief Точка входа для программы
*@return 0
*/
int main()  
{ 
    setlocale(LC_ALL, "Russian"); 
    cout << "Введите число x: "; 
    double x = getValue(); 
    cout << "Введите число y: "; 
    double y = getValue(); 


    if (x < y + numeric_limits<double>::epsilon()) 
    { 
        double temp = x; 
        x = 0.5 * (x + y);    // Меньшее число заменяем половиной их суммы 
        y = 2 * temp * y;      // Большее число заменяем их удвоенным произведением 
    } 
    else { 
        double temp = y; 
        y = 0.5 * (x + y); 
        x = 2 * x * temp; 
    } 


    cout << "При замене меньшего числа на половину их суммы получим: " << x << endl; 
    cout << "При замене большего числа на их удвоенное произведение получим: " << y << endl; 

    return 0; 
} 

double getValue() 
{ 
    double value; 
    cin >> value; 
    if (cin.fail()) 
    { 
        cout << "Некорректное значение" << endl; 
        abort(); 
    } 
    return value; 
} 
