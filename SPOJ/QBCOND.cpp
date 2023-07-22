#include <bits/stdc++.h>
using namespace std;
long long res[11][46],k;
long long n,sl[11],gt[11],x[11],cnt;
bool check[11][11];

void makec()
{
    for (int i=1;i<=10;i++) sl[i]=i*(i-1)/2;
    gt[1]=1;
    for (int i=2;i<=10;i++) gt[i]=gt[i-1]*i;
}

void proces()
{
    long long m=0;
    for (int i=1;i<=cnt;i++)
        m+=sl[x[i]];

    if (m!=k) return;

    m=1;

    for (int i=1;i<=cnt;i++)
        m*=gt[x[i]];

    m=gt[n]/m;
    res[n][k]+=m;
}
void btrk(int i)
{
    if (i==n+1)
    {
        proces();
        return;
    }
    x[cnt]++;
    btrk(i+1);
    x[cnt]--;
    cnt++;
    x[cnt]=1;
    btrk(i+1);
    cnt--;
}
int main()
{
    makec();
    for (int i=2;i<=10;i++)
    for (int j=0;j<=45;j++)
    {
        n=i;
        k=j;
        cnt=1;
        x[1]=1;
        btrk(2);
    }
    cin >> n;
    while (n!=-1)
    {
        cin >> k;
        if (k<0 || k>45) cout<< "0\n";
        else
        cout << res[n][k] << "\n";
  //  }
        cin >> n;
    }
}
