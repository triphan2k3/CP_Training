#include <bits/stdc++.h>
using namespace std;
string s;
int f[2000][2000];
bool kt[2000];
int main()
{
    cin >> s;
    int k;
    int t=s.length();
    for (int i=0;i<t;i++)
        f[i][i]=1;

    for (int i=2;i<=t;i++)
        for (int j=0;j<=t-i;j++)
    {
        k=j+i-1;
        f[j][k]=(s[j]==s[k]) ? f[j+1][k-1]+2 : max(f[j+1][k],f[j][k-1]);
    }

    int i=0,j=t-1,temp=f[0][t-1];
    do
    {
        while (f[i][j-1]==temp) j--;
        while (f[i+1][j]==temp) i++;
        kt[i]=true;
        kt[j]=true;
        if (i==j) temp--;
        else temp-=2;
        i++;
        j--;
    } while (temp>0);

    for (i=0;i<t;i++)
        if (kt[i]==true) cout << s[i];
}
