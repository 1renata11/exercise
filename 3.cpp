#include <iostream>
#include <string>
#include <cstdlib>
#include <cctype>
//http://cppstudio.com/post/1514/
using namespace std;
int main()
{
    string s;
    int k=0, n=0, m=0, i=0;
    string* p=new string [n];
    cout<<"Enter s"<<endl;
    cin>>s;
    while (s[i]!='\n')
    {
        if (isspace(s[i])) {if (n>m) {m=n; n=0;k++;} else {delete *p; string *p=new string [n];};}
        else {n++;*p+=s[i];}
        i++;
    }
    cout<<k<<" "<<*p;
    delete[] p;
    return 0;
}
