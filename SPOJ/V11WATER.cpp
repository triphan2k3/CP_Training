#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define inp "V11WATER.INP"
#define out "V11WATER.OUT"
using namespace std;
const int N=(int)1e5+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
int a[N],l[N],r[N];
int n;

int main()
{
    //freopen(inp,"r",stdin);
    //freopen(out,"w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    for (int i=1;i<=n;i++)
        l[i]=max(a[i],l[i-1]);
    for (int i=n;i>=1;i--)
        r[i]=max(r[i+1],a[i]);

    ll ans=0;
    for (int i=1;i<=n;i++)
        ans+=1LL*max(min(l[i],r[i])-a[i],0);
    cout<<ans;
}
