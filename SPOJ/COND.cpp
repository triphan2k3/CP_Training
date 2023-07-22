#include <bits/stdc++.h>
using namespace std;
int n,cnt,x[11];
long long res,gt[11];

void init()
{
    gt[1]=1;
    for (int i=2;i<=10;i++)
        gt[i]=gt[i-1]*i;
}

void btrk(int i)
{
    if (i==n+1)
    {
        long long k=1;
        for (int j=1;j<=cnt;j++)
        k*=gt[x[j]];
        res+=gt[n]/k;
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

    cin >> n;
    while (n!=-1)
    {
        init();
        res=0;
        x[1]=1;
        cnt=1;
        btrk(2);
        cout<<res << "\n";
        cin>> n;
    }
}
