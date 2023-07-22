#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define inp "VO17TV.INP"
#define out "VO17TV.OUT"
using namespace std;
const int N=(int)1e5+7;
const ll BASE=8010;
const ll MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
string s[100];
ll lt[N],h[100][N];
int ck[N];
int n,k,l,r,ans;
void prepare()
{
    lt[0]=1;
    for (int i=1;i<N;i++)
        lt[i]=(lt[i-1]*BASE) % MOD;
    for (int i=1;i<=n;i++)
        for (int j=0;j<s[i].size();j++)
            h[i][j+1]=(h[i][j]*BASE+s[i][j])%MOD;
    return;
}
ll gethash(int i,int l,int r)
{
    return (MOD*MOD+h[i][r]-h[i][l-1]*lt[r-l+1]) % MOD;
}

bool check(int len)
{
    vector<ii> a;
    for (int i=1;i<=n;i++)
        for (int j=len;j<=s[i].size();j++)
            a.push_back({gethash(i,j-len+1,j),i});

    sort(a.begin(),a.end());
    for (int i=1;i<=n;i++)
        ck[i]=0;
    ck[a[0].Y]=1;
    int tp=1;
    int sl=1;
    for (int i=1;i<a.size();i++)
    {
        if (sl==k) return true;
        if (a[i].X!=a[i-1].X)
        {
            ck[a[i].Y]=++tp;
            sl=1;
            continue;
        }
        if (ck[a[i].Y]==tp) continue;
        ck[a[i].Y]=tp;
        sl++;
    }
    if (sl==k) return true;
    return false;
}
int main()
{
    freopen(inp,"r",stdin);
    freopen(out,"w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k;
    for (int i=1;i<=n;i++)
        cin>>s[i];
    prepare();
    for (int i=1;i<=n;i++)
    {
        int cp=s[i].size();
        r=max(r,cp);
    }
        //r=max(r,s[i].size());
    l=0;
    while (r>=l)
    {
        int m=(r+l)>>1;
        if (check(m))
        {
            ans=m;
            l=m+1;
        }
        else r=m-1;
    }
    cout<<ans;
}
