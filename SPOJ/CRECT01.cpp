#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define inp "CRECT01.INP"
#define out "CRECT01.OUT"
using namespace std;
const int N=(int)1e5+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;

ll f[1001][1001];
ll h[1001][1001];
int a[1001][1001];
ll res;
int n,m;

void proces(int i)
{
    deque<int> d;
    int pos=1;
    for (int j=1;j<=n;j++)
    {
        while (d.size() && h[i][d.back()]>=h[i][j]) d.pop_back();
        if (d.empty()) pos=1; else pos=d.back()+1;
        d.pb(j);

        f[i][j]=f[i][pos-1]+h[i][j]*(j-pos+1);
        res+=f[i][j];
    }
}
int main()
{
    freopen(inp,"r",stdin);
    freopen(out,"w",stdout);
    cin>>m>>n;
    string s;
    for (int i=1;i<=m;i++)
    {
        cin>>s;
        for (int j=1;j<=n;j++)
        {
            a[i][j]=s[j-1]-'0';
            h[i][j]=(a[i][j]==1) ? h[i-1][j]+1 : 0;
        }
    }
    for (int i=1;i<=n;i++)
        proces(i);
    cout<<res;
}
