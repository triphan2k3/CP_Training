#include <bits/stdc++.h>
using namespace std;
int a,f[2001][2001],b,k;
string s1,s2;
int main()
{
    cin >> s1>>s2>> k;
    a=s1.length();
    b=s2.length();
    s1=" "+s1;
    s2=" "+s2;
    for (int i=1;i<=a;i++)
        f[i][0]=k*i;

    for (int i=1;i<=b;i++)
        f[0][i]=k*i;

    for (int i=1;i<=a;i++)
        for (int j=1;j<=b;j++)
            f[i][j]=min(min(f[i-1][j]+k,f[i][j-1]+k),f[i-1][j-1]+abs(int(s1[i])-int(s2[j])));



    cout << f[a][b];
}
