#include <iostream>
#include <string>
#include <cstdlib>
#include <cctype>

// http://cppstudio.com/post/1514/

using namespace std;
int main()
{
    string s;
    int k=0, n=0, m=0, i=0;
    // Зачем??? Если вам нужен массив строк, его можно создать на стеке. И вы в любом случае ещё не знаете, какого размера он вам нужен.
    string* p=new string [n];
    
    cout << "Enter string: " << endl;
    // Такая конструкция принимает символы до первого пробела. Надо иначе.
    // cin >> s;
    getline(cin, s);
    
    // Тут вы даже алгоритм не сформулировали. Вот у вас строка. Нужно 
    // 1. Посчитать число слов прямо в строке
    // 2. Расчленить строку на слова
    // 3. Пройтись по массиву слов и определить слово с максимальной длиной
    // Не злоупотребляйте new. А ещё есть коллекции типа std::array или std::list, которые позволяют динамически увеличивать размер при добавлении элемента. 
    // Почитайте вообще про коллекции. Я не вижу в задании требований по используемым коллекциям.
    // Удалите тот мрак, что ниже, и решайте заново.

    /*while (s[i]!='\n')
    {
        if (isspace(s[i])) {if (n>m) {m=n; n=0;k++;} else {delete *p; string *p=new string [n];};}
        else {n++;*p+=s[i];}
        i++;
    }
    cout<<k<<" "<<*p;
    delete[] p;*/
    return 0;
}
