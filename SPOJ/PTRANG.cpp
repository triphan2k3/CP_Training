#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define inp "PTRANG.INP"
#define out "PTRANG.OUT"
using namespace std;
const int N=(int)1e5+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
int n,L,tmp,a[N],f[N];
int main()
{
    freopen(inp,"r",stdin);
    freopen(out,"w",stdout);
    cin>>n>>L;
    for (int i=1;i<=n;i++)
        cin>> a[i];

    f[0]=0;
    for (int i=1;i<=n;i++)
    {
        tmp=0;
        f[i]=max(f[i-1],L-a[i]);
        for (int j=i;j>0;j--)
        {
            tmp+=a[j];
            if (tmp>L) break;
            f[i]=min(f[i],max(f[j-1],L-tmp));
        }
    }
    cout<<f[n];
}
