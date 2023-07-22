#include <bits/stdc++.h>
using namespace std;
struct data
{
    int h,a,c;
};

int res,k;
data d[1000];
bool f[2][50000];
bool myfunc(data x, data y)
{
    return (x.a < y.a);
}
int main()
{
   // ifstream ff ("test.inp");
    cin >> k;
    for (int i=1;i<=k;i++)
        cin >> d[i].h >> d[i].a >> d[i].c;
    sort(d+1,d+k+1,myfunc);

    f[0][0]=true;
    f[1][0]=true;
    int temp=0;
    for (int i=1;i<=k;i++)
    {
        for (int j=1;j<=40000;j++)
        if (j<=d[i].a)
        {
            if (j==53)
                temp=temp+1;
            f[i%2][j]=f[(i+1)%2][j];
            for (int t=1;t<=d[i].c;t++)
            if (d[i].h*t<=j)
            f[i%2][j]=(f[i%2][j] || f[(i+1)%2][j-d[i].h*t]);
        }
    }
    for (int j=1;j<=40000;j++)
        if (f[k%2][j]==true) res=j;
    cout << res;
    //ff.close();
}
