#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define inp "PCYCLE.INP"
#define out "PCYCLE.OUT"
using namespace std;
const int N=(int)1e5+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
vector<ii> a[210];
vector<int> res;
int s[50000];
int n,m;
int w[210][210];
int avail[50000];
int deg[210];
void buildcircle(int u)
{
    for (ii e:a[u])
    {
        if (avail[e.Y]) continue;
        avail[e.Y]=1;
        buildcircle(e.X);
    }
    res.pb(u);
}
int main()
{
    freopen(inp,"r",stdin);
    freopen(out,"w",stdout);

    int x,y,z;
    int sum=0;
    cin>>n;
    if (n==1)
    {
    	cout<<1;
    	return 0;
    }
    cin>>m;
    for (int i=1;i<=m;i++)
    {
        cin>>x>>y>>z;
        a[x].pb(mp(y,i));
        a[y].pb(mp(x,i));
        w[x][y]=w[y][x]=z;
        deg[x]++;
        deg[y]++;
        sum+=z;
    }
    if (n==2)
    {
    	cout<<"1 2 1";
    	return 0;
    }
    for (int i=1;i<=n;i++)
        if (deg[i]%2==1)
    {
        cout<<"-1";
        return 0;
    }
    buildcircle(1);
    if (sum<0)
    {
        cout<<-1;
        return 0;
    }
    //reverse(res.begin(),res.end());
    int mi=0;
    int mival=0;
    for (int i=1;i<res.size();i++)
    {
        s[res[i]]=s[res[i-1]]+w[res[i]][res[i-1]];
        if (s[res[i]]<mival)
        {
            mival=s[res[i]];
            mi=i;
        }
    }
    for (int i=mi;i<res.size()-1;i++)
        cout<<res[i]<<" ";
    for (int i=0;i<mi;i++)
        cout<<res[i]<<" ";
        cout<<res[mi];
}
