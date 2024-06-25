#include <iostream>
using namespace std;

/
 * @brief Функция для вычисления суммы.
 * @param x Значение переменной x.
 * @param y Значение переменной y.
 * @return Результат вычисления переменной sum.
 */
double getsum( const double x,const double y);

/
 * @brief Функция для вычисления разности.
 * @param x Значение переменной x.
 * @param y Значение переменной y.
 * @return Результат вычисления переменной diff.
 */
double getdiff( const double x,const double y);

/
 * @brief Функция для вычисления произведения.
 * @param x Значение переменной x.
 * @param y Значение переменной y.
 * @return Результат вычисления переменной comp.
 */
double getcomp(const double x,const double y);


/
 * @brief Функция для вычисления частного.
 * @param x Значение переменной x.
 * @param y Значение переменной y.
 * @return Результат вычисления переменной divi.
 */
double getdivi(const double x,const double y);
/
*@brief Считывает значиния с клавиатуры с проверкой ввода
*@return возвращает значение, если оно правильное , иначе завершает программу
*/
double getValue();

/
* @brief Точка входа в программу
* @return Возвращает 0,если функция выполнена верно
*/
 int main()
{
    cout<<"введите x"<<endl;
    const double x = getValue();
    cout<<"введите y "<< endl;
    const double y = getValue();



    cout<<"x = "<<x<<endl;
    cout<<"y = "<<y<<endl;
    double sum =  getsum(x,y);
    double diff =  getdiff(x,y);
    double comp =  getcomp(x,y);
    double divi =  getdivi(x,y);
    cout << "sum = " <<sum<<endl;
    cout << "diff = "<< diff<<endl;
    cout <<"comp = "<< comp<<endl;

     if (divi== y)
    {
        cout<<"деление на ноль невозможно"<<endl;
    }else{
    cout<<"divi = "<<divi<<endl;
    }

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

double getsum( const double x,const double y)
{
    return x+y;
}
double getdiff( const double x ,const double y)
{
    return x-y;
}
double getcomp(const double x,const double y)
{
    return x*y;
}
double getdivi(const double x,const double  y)
{
    if (y==0)
    {
        return y; 
    }
    else
    {
        return x/y;   
    }
}
        return x/y;
    }
}
