#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define inp "1337B.INP"
#define out "1337B.OUT"
using namespace std;
const int N=(int)2e5+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
int t,x,n,m;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen(inp,"r",stdin);
    freopen(out,"w",stdout);
    cin>>t;
    while (t--)
    {
        cin>>x>>n>>m;
        while (n && x>20)
        {
            n--;
            x=(x/2)+10;
        }
        while (m && x>0)
        {
            m--;
            x-=10;
        }
        if (x<=0) cout<<"YES\n";
        else cout<<"NO\n";

    }
}
