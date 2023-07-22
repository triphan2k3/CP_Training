#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define inp "NICEQUAD.INP"
#define out "NICEQUAD.OUT"
using namespace std;
const int N=(int)1e5+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
ll cnt[4][4];
int n,t;
void resetvar()
{
    for (int i=0;i<4;i++)
        for (int j=0;j<4;j++)
            cnt[i][j]=0;
}
void add(int x,int y)
{
    int mask=0,phan=0;
    if (x==0 || y==0) return;
    if (x<0 && y>0) phan=1;
    if (x<0 && y<0) phan=2;
    if (x>0 && y<0) phan=3;
    if (abs(x)%2) mask+=2;
    if (abs(y)%2) mask+=1;
    cnt[phan][mask]++;
    return;
}
int main()
{
    freopen(inp,"r",stdin);
    freopen(out,"w",stdout);
    cin>>t;
    while (t--)
    {
        resetvar();
        cin>>n;
        for (int i=1,x,y;i<=n;i++)
        {
            cin>>x>>y;
            add(x,y);
        }
        ll res=0;
        for (int i=0;i<4;i++)
            for (int j=0;j<4;j++)
                res+=cnt[0][i]*cnt[2][3-i]*cnt[1][j]*cnt[3][3-j];
        //int I=1,II=2;
        for (int i=0;i<4;i++)
        for (int j=0;j<4;j++)
        for (int k=0;k<4;k++)
        for (int l=0;l<4;l++)
        if ((((i^k)&1)==0 || ((j^l)&2)==0) && (((i^k)&2)==0 || ((j^l)&1)==0))
            res+=cnt[0][i]*cnt[1][j]*cnt[2][k]*cnt[3][l];
        cout<<res<<"\n";

    }
}
