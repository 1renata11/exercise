#include <iostream>
#include <string>
#include <cstdlib>
#include <cctype>

using namespace std;
// http://cppstudio.com/post/1478/
int main()
{
    string s;
    cout<<"Enter s"<<endl;
    cin>>s;
    if (s[0]!=' ') {s.erase(0,1);}
    int i=1;
    while(s[i]!='.')
    {
        if (isspace(s[i])) {s.erase(i+1,1);};
        i++;
        if (s[i]=='.') break;
    }
    cout<<s;
    return 0;
}
