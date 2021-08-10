#include <iostream>

using namespace std;
/*Задача на динамическое выделение памяти. Изначально есть указатель на массив с одним элементом.
Пользователь вводит число. Если оно больше 0 записываем его в массив. Далее пользователь вводит второе число, тут уже,
если оно больше 0, надо перевыделять память для 2-х элементов массива и записать в массив второе число.
И так далее…  для 3-х элементов, для 4-х…  пока пользователь не введет отрицательное число.*/
int main()
{
    int s=1, new_s, n;
    int *old_a=new int [s];
    cout<<"Enter n: ";
    cin>>n;
    cout<<endl;
while (!(cin >> n) || (cin.peek() != '\n'))
{
    cin.clear();
    while (cin.get() != '\n');
    cout << "Error!" << endl;
}
if (n<0) cout<<"Error!"<<endl;
    old_a[s]=n;
    cout<<old_a[s];
    while(n>=0)
    {
        cout<<endl;
        cout<<"Enter n:";
        cin>>n;
        if (n<0) break;
        new_s=s+1;
        int *new_a=new int [new_s];
        for (int i=1; i<new_s; i++)
        {
            new_a[i]=old_a[i];
        }
        new_a[new_s]=n;
        delete[] old_a;
        for (int i=1; i<=new_s; i++)
        {
            cout<<new_a[i];
        }
        cout<<endl;
        int *old_a=new int [new_s];
        for (int i=1; i<=new_s; i++)
        {
            old_a[i]=new_a[i];
        }
        delete[] new_a;
        s=new_s;
    }
    delete[] old_a;
    return 0;
}
