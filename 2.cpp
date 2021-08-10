#include <iostream>
#include <string>
#include <cstdlib>
#include <cctype>

using namespace std;

// http://cppstudio.com/post/1478/

int main()
{
    string s;
    // Всегда пишите понятно. Имена функций, переменных, пользовательский ввод, сообщения об ошибках. Не ленитесь.
    // Нет задачи сэкономить пару символов, но как правило к нормальному коду возвращаются вновь и вновь, через месяцы и годы. 
    // И как в нём разбирваться? А как пользоваться?
    cout << "Enter string: " << endl;
    // Такая конструкция принимает символы до первого пробела. Надо иначе.
    // cin >> s;
    getline(cin, s);
    
    // если в предложении в самом конце нет точки - программа падает.
    if(s[s.length()-1] != '.') {
        cout << "Error: absent terminal '.'" << endl;
        return -1;
    }

    // Всегда разворачивайте условия и циклы на несколько строк, так их гораздо легче читать. Особенно если не забывать про отступы.
    // Для тех, кто осознанно этим пренебрегает, в аду приготовлен специальный котёл.
    if (s[0] != ' ') {
        s.erase(0, 1);
    }
    int i = 1;
    while(s[i] != '.')
    {
        if (isspace(s[i])) {
            // Так нельзя делать. Кто вам даёт гарантию, что есть ещё один символ в строке?
            // И по этой логике вы также съедаете все пробелы между словами, кроме одного. Про пробелы в условии задачи ничего не сказано.
            // Предлагаю это исправить самостоятельно.
            s.erase(i+1, 1);
        };
        i++;
        if (s[i] == '.') 
            break;
    }

    cout << s;
    return 0;
}
