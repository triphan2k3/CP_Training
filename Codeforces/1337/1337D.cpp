#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define inp "1337D.INP"
#define out "1337D.OUT"
using namespace std;
const int N=(int)2e5+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
int x,y,z,k,t;
long long ans;
vector<int> a,b,c;

ll sq(int a)
{
    return 1LL*a*a;
}
ll getans(int a,int b,int c)
{
    return sq(a-b)+sq(b-c)+sq(c-a);
}
void solve(vector<int> a,vector<int> b,vector<int> c)
{
    for (int x:a)
    {
        int lb=lower_bound(b.begin(),b.end(),x)-b.begin();
        int lc=lower_bound(c.begin(),c.end(),x)-c.begin();
        int ub=upper_bound(b.begin(),b.end(),x)-b.begin()-1;
        int uc=upper_bound(c.begin(),c.end(),x)-c.begin()-1;
        if (lb<b.size() && uc>=0)
        {
            int y=b[lb];
            int z=c[uc];
            ans=min(ans,getans(x,y,z));
        }
        if (lc<c.size() && ub>=0)
        {
            int y=b[ub];
            int z=c[lc];
            ans=min(ans,getans(x,y,z));
        }
    }
    return;
}
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
        ans=4e18;
        cin>>x>>y>>z;
        a.resize(x);
        b.resize(y);
        c.resize(z);
        for (int i=0;i<x;i++)
            cin>>a[i];
        sort(a.begin(),a.end());

        for (int i=0;i<y;i++)
            cin>>b[i];
        sort(b.begin(),b.end());

        for (int i=0;i<z;i++)
            cin>>c[i];
        sort(c.begin(),c.end());
        solve(a,b,c);
        solve(b,a,c);
        solve(c,a,b);
        cout<<ans<<"\n";
    }
}
