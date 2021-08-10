#include <iostream>
#include <string>
#include <cstdlib>
#include <cctype>
#include <limits>
#include <ctime>

using namespace std;

// http://cppstudio.com/post/2668/

// всё, что делается единообразно и более одного раза - кандидат на вынос в функцию
// Особенно приятно, когда уже есть готовая функция из 1.cpp
int inputN(const char* txt){
    int n;

    cout << txt;
    while (! (cin >> n)){
        cout << "Your entry must be a valid numeric value." << endl; 
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << txt;
    }

    return n;
}

int main()
{
    // Даём значимым переменным говорящие имена, не жадничаем. Текст программы резко становится понятнее!
    int rows, columns, sum=0;
    
    // при работе со случайными числами надо инициализовывать генератор, иначе случайности не будет
    srand( time(0) );

    rows = inputN("Enter the number of rows: ");
    columns =  inputN("Enter the number of columns: ");
    cout << " " << endl;

    int **p = new int *[rows];
    for (auto i =  0; i < rows; ++i)
    {
        p[i] = new int [columns];
    }

    for (auto i = 0; i < rows; i++)
    {
        for (auto j = 0; j < columns; j++)
        {            
            p[i][j] = rand() % 30 - 10;
            cout.width(3);
            cout << p[i][j] << " ";
        }
        cout << endl;
    }
    for (auto j = 0; j < columns; j++)
    {
        for (auto i=0; i < rows; i++)
        {
            if (p[i][j] >= 0){
                sum += p[i][j];
            }
            else {
                sum=0;
                break;
            }
        }
        // Лучше подписывать, в каком столбце у нас вычислялась сумма
        // И помним, что программисты считают с 0, а люди - с 1. Программа обычно пишется для людей.
        if (sum>0){ 
            cout << "Column " << j+1 << " sum="<< sum << endl;
        }
        // и ошибка. В задаче сказано найти сумму каждого столбца по отдельности. Нужно обнулять сумму, либо создавать для суммирования локальную переменную
        sum = 0;
    }
    
    // Патриархи, Кенниган и Ритчи, даровали нам операторные скобки, нужно их использовать.
    // Иначе есть шанс потратить лучшие дни жизни в поисках ошибки
    for (auto i = 0; i < rows; i++) {
        delete[] p[i];
    }
    delete[] p;

    return 0;
}

// А в целом к этой задаче больше замечаний нет, кроме того, что исправил.