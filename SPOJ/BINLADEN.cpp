#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define iii pair<int,ii>
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define inp "BINLADEN.INP"
#define out "BINLADEN.OUT"
using namespace std;
const int M=2333;
const int N=20;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;

int d[M][N],righ[M][N],left[M][N],down[M][N];
int m,n;

void dijkstra()
{
    priority_queue<iii,vector<iii>,greater<iii>> q;
    for (int i=1;i<=n;i++)
        q.push({down[1][i],{1,i}});

    for (int i=1;i<=m;i++)
        for (int j=1;j<=n;j++)
            d[i][j]=MOD;

    for (int i=1;i<=n;i++)
        d[1][i]=down[1][i];

    while (q.size())
    {
        int cost=q.top().X;
        int i=q.top().Y.X;
        int j=q.top().Y.Y;
        q.pop();
        if (d[i][j]!=cost) continue;
        //up
        if (i!=1)
            if (d[i-1][j]>d[i][j]+down[i][j])
            {
                d[i-1][j]=d[i][j]+down[i][j];
                q.push({d[i-1][j],{i-1,j}});
            }
        //down
        if (i!=m)
            if (d[i+1][j]>d[i][j]+down[i+1][j])
            {
                d[i+1][j]=d[i][j]+down[i+1][j];
                q.push({d[i+1][j],{i+1,j}});
            }
        //left
        if (j!=1)
            if (d[i][j-1]>d[i][j]+righ[i][j-1])
            {
                d[i][j-1]=d[i][j]+righ[i][j-1];
                q.push({d[i][j-1],{i,j-1}});
            }
        //right
        if (j!=n)
            if (d[i][j+1]>d[i][j]+righ[i][j])
            {
                d[i][j+1]=d[i][j]+righ[i][j];
                q.push({d[i][j+1],{i,j+1}});
            }
    }
}
int main()
{
    freopen(inp,"r",stdin);
    freopen(out,"w",stdout);
    cin>>m>>n;
    for (int i=1;i<=m;i++)
    {
        for (int j=1;j<=n;j++)
            cin>>down[i][j];
        for (int j=1;j<n;j++)
            cin>>righ[i][j];
    }
    dijkstra();
    cout<<d[m][n];
}
