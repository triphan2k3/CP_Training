/*
                                 _ _  _| _   |_     |_  _  _  _ |   _  _|_ _
                                (_(_)(_|(/_  |_)\/  | |(_)| |(_||\/(_|_|| (/_
                                                /             _| /
*/
#include <bits/stdc++.h>
#define ll long long
#define ii pair<ll,ll>
#define iii pair<ll,ii>
#define int long long
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define inp "659F.INP"
#define out "659F.OUT"
using namespace std;
const int N=(int)1e3+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
int x[4]={1,-1,0,0};
int y[4]={0,0,1,-1};
ll a[N][N];
vector<iii> e;
int ok[N][N];
ll m,n,k,cnt;
int loang(ii p)
{
    int i=p.X;
    int j=p.Y;
    ll val=a[i][j];
    ll ans=val;

    ok[i][j]=cnt;
    if (ans==k) return 1;
    deque<ii> q;
    q.push_back({i,j});
    while (q.size())
    {
        i=q.back().X;
        j=q.back().Y;
        q.pop_back();
        for (int z=0;z<4;z++)

        {
            int u=i+x[z];
            int v=j+y[z];
            if (a[u][v] < val || ok[u][v]==cnt) continue;
            ok[u][v]=cnt;
            ans+=val;
            if (ans==k) return 1;
            q.push_front({u,v});
        }
    }
    return 0;
}
main()
{
    freopen(inp,"r",stdin);
    freopen(out,"w",stdout);
    cin>>m>>n>>k;
    for (int i=1;i<=m;i++)
        for (int j=1;j<=n;j++)
    {
        cin>>a[i][j];
        if (k%a[i][j]==0)
            e.push_back({a[i][j],{i,j}});
    }
    if (e.size()==0)
    {
        cout<<"NO";
        return 0;
    }
    sort(e.begin(),e.end());
    cnt=1;
    int k=loang(e[0].Y);
    int last=0;
    for (int i=0;i<e.size() && !k;i++)
    {
        if (e[i].X*m*n<k) continue;
        ll val=e[i].X;
        ll x=e[i].Y.X;
        ll y=e[i].Y.Y;
        if (val==e[i-1].X && ok[x][y]==cnt) continue;
        if (val!=e[i-1].X) cnt++;
        k=loang(e[i].Y);
        if (k) last=i;
    }
    if (!k)
    {
        cout<<"NO";
        return 0;
    }
    cout<<"YES\n";
    cnt++;
    loang(e[last].Y);
    //ll soluong=k/e[i].X;
    ll gt=e[last].X;
    for (int i=1;i<=m;i++)
    {
        for (int j=1;j<=n;j++)
            if (ok[i][j]==cnt)
                cout<<gt<<" ";
            else cout<<"0 ";
        cout<<"\n";
    }
    return 0;
}
