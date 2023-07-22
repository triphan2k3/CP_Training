#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define inp ".INP"
#define out ".OUT"
using namespace std;
const int N=(int)1e5+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
int a[2*N];
int n,k,x;
int main()
{
    //freopen(inp,"r",stdin);
    //freopen(out,"w",stdout);
    cin>>n>>k;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    int x=a[k];
    if (k==0)
    {
        if (a[1]>1) cout<<1;
        else cout<<-1;
        return 0;
    }
    if (a[k]==a[k+1])
    {
        cout<<-1;
        return 0;
    }
    else cout<<x;
}
