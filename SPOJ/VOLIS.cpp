#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define inp "VOLIS.INP"
#define out "VOLIS.OUT"
using namespace std;
const int N=(int)1e3+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
int a[N];
int lis[N];
int n,x,k;
int main()
{
    freopen(inp,"r",stdin);
    freopen(out,"w",stdout);

    cin>>n>>x;
    for (int i=1;i<=n;i++)
        cin>>a[i];

    lis[0]=-MOD;
    for (int i=1;i<=n;i++)
    {
        if (lis[k]<=a[i]+x)
        {
            k++;
            lis[k]=max(lis[k-1],a[i]-x);
        }
        for (int j=k;j>=1;j--)
            if (lis[j-1]<=a[i]+x)
                lis[j]=min(lis[j],max(lis[j-1],a[i]-x));
    }
    cout<<k;
}
