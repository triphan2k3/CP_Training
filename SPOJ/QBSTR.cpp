#include <bits/stdc++.h>
using namespace std;
string a,b;
int main()
{
    cin >> a >> b;
    int n=b.length();
    int m=a.length();
    a=" "+a;
    b=" "+b;
    vector< vector<int> > f(m+1, vector<int>(n+1, 0));

    //if (a[0]==b[0]) f[0][0]=1;
    for (int i=1; i<=m; i++)
        for (int j=1; j<=n; j++)
        if (a[i]==b[j]) f[i][j]=f[i-1][j-1]+1;
        else f[i][j]=max(f[i][j-1],f[i-1][j]);

    cout << f[m][n];

}
