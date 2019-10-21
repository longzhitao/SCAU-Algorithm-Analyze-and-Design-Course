/*
 *
 */

#include <iostream>
using namespace std;

long long h[40];

int main()
{
    int i,j,n;
    h[0]=1,h[1]=1;h[2]=1;
    cin>>n;
    if (n <= 2)
        cout << "No answer";
    else
    {
        for(i=3;i<=n;i++)
            for(j=2;j<=i-1;j++)
                h[i]+=h[j]*h[i-j+1];
        h[2]=0;
        cout<<h[n];
    }


    return 0;
}
