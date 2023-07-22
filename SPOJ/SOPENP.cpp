#include <bits/stdc++.h>
using namespace std;
struct data
{
    long long val;
    int pos;
};
const int N=1<<21;
long long b[N],dpp[N],lef[N],righ[N];
//int ;
data a[N];

bool myf(data a, data b)
{
    return (a.val<b.val);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,l,r;
    //ifstream f ("test.inp");
    cin >> n >> l >> r;
    for (int i=1;i<=n;i++)
    {
        cin >> a[i].val;
        a[i].pos=i;
    }

    sort(a+1,a+n+1,myf);
    int t=0;
    for (int i=1;i<=n;i++)
    {
        if (a[i].val!=a[i-1].val)
        t++;
        b[a[i].pos]=t;
    }

    int d=0;
    int j=0;
    for (int i=1;i<=n;i++)
    {
        while (d<=r && j<=n)
        {
            j++;
            if (dpp[b[j]]==0) d++;
            dpp[b[j]]++;
        }
        righ[i]=j-1;
        dpp[b[i]]--;
        if (dpp[b[i]]==0) d--;
    }
    j=0;
    d=0;
    for (int i=1;i<=n;i++)
    {
        while (d<l && j<=n)
        {
            j++;
            if (dpp[b[j]]==0) d++;
            dpp[b[j]]++;
        }

        if (j<=n) lef[i]=j;
        dpp[b[i]]--;
        if (dpp[b[i]]==0) d--;
    }
    long long ans=0;
    for (int i=1;i<=n;i++)
        if (lef[i]!=0) ans+=righ[i]-lef[i]+1;

    cout << ans;
}
