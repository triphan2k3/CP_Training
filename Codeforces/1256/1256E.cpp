/*
                                 _ _  _| _   |_     |_  _  _  _ |   _  _|_ _
                                (_(_)(_|(/_  |_)\/  | |(_)| |(_||\/(_|_|| (/_
                                                /             _| /
*/
#include <bits/stdc++.h>
#define ll long long
#define ii pair<ll,ll>
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define inp "1256E.INP"
#define out "1256E.OUT"
using namespace std;
const int N=(int)2e5+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e14+7;

int res[N],num[N];
ll f[N];
ii a[N];
int n;

int main()
{
    freopen(inp,"r",stdin);
    freopen(out,"w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>a[i].X;
    for (int i=1;i<=n;i++)
        a[i].Y=i;
    sort(a+1,a+n+1);

    f[1]=f[2]=INF;
    f[3]=a[3].X-a[1].X;
    f[4]=a[4].X-a[1].X;
    f[5]=a[5].X-a[1].X;
    num[3]=3;
    num[4]=4;
    num[5]=5;

    for (int i=6;i<=n;i++)
    {
        f[i]=INF;
        for (int j=i-3;j>=i-5;j--)
            if (f[i]>f[j]+a[i].X-a[j+1].X)
            {
                f[i]=f[j]+a[i].X-a[j+1].X;
                num[i]=i-j;
            }
    }
    int cnt=1;
    int i=n;
    while (i>0)
    {
        for (int j=0;j<num[i];j++)
            res[a[i-j].Y]=cnt;
        i-=num[i];
        cnt++;
    }
    cout<<f[n]<<" "<<cnt-1<<"\n";
    for (int i=1;i<=n;i++)
        cout<<res[i]<<" ";
}
