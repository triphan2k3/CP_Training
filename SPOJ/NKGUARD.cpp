#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define inp "NKGUARD.INP"
#define out "NKGUARD.OUT"
using namespace std;
const int N=1000;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
int x[8]={-1,-1,-1, 0,0, 1,1,1};
int y[8]={-1, 0, 1,-1,1,-1,0,1};
int ck[N][N];
int a[N][N];
int m,n,res;
int check(int i,int j)
{
    for (int k=0;k<8;k++)
        if (a[i][j]<a[i+x[k]][j+y[k]]) return 0;
    return 1;
}
void bfs(int i,int j)
{
    deque<ii> q;
    q.pb(mp(i,j));
    int val=a[i][j];
    int add=1;
    while (q.size())
    {
        ii t=q.back();
        i=t.X;
        j=t.Y;
        if (!check(i,j)) add=0;
        q.pop_back();
        for (int k=0;k<8;k++)
            if (!ck[i+x[k]][j+y[k]] && a[i+x[k]][j+y[k]]==val)
            {
                ck[i+x[k]][j+y[k]]=1;
                q.pb(mp(i+x[k],j+y[k]));
            }
    }
    res+=add;
}
int main()
{
    freopen(inp,"r",stdin);
    freopen(out,"w",stdout);
    cin>>m>>n;
    for (int i=1;i<=m;i++)
        for (int j=1;j<=n;j++)
            cin>>a[i][j];

    for (int i=1;i<=m;i++)
        for (int j=1;j<=n;j++)
            if (a[i][j]!=0)
            if (check(i,j) && (!ck[i][j]))
                bfs(i,j);

    cout<<res;

}
