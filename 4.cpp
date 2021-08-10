#include <iostream>
#include <string>
#include <cstdlib>
#include <cctype>

using namespace std;
//http://cppstudio.com/post/2668/
int main()
{
    int n, m, sum=0;
    cout<<"Enter n and m "<<endl;;
    cin>>n;
    cin>>m; cout<<" "<<endl;
    int **p = new int *[n];
    for (int i =  0; i < n; ++i)
{
    p[i] = new int [m];
}

    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
        {

            p[i][j]=rand()%30-10;
            cout.width(3);
            cout<<p[i][j]<<" ";
        }
        cout<<endl;
    }
    for (int j=0; j<m; j++)
    {
        for (int i=0; i<n; i++)
        {
            if (p[i][j]>=0) {sum+=p[i][j];}
            else {sum=0;break;}
        }
        if (sum>0) cout<<sum<<" ";
    }
    for (int i; i<n; i++)
    delete[] p[i];
    delete[] p;

    return 0;
}

