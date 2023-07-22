#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define inp "VOSTR.INP"
#define out "VOSTR.OUT"
using namespace std;
const int N=(int)1e6+7;
const ll MOD=(ll)1e9+7;
const ll BASE=311;
const ll INF=(ll)1e18+7;
string a,b;
int la,lb,La,Lb,Ra,Rb,q;
ll ha[N],hb[N],lt[N];

ll geta(const int l,const int r)
{
    return (MOD*MOD+ha[r]-ha[l-1]*lt[r-l+1])%MOD;
}
ll getb(const int l,const int r)
{
    return (MOD*MOD+hb[r]-hb[l-1]*lt[r-l+1])%MOD;
}
char query()
{

    int sa=Ra-La;
    int sb=Rb-Lb;
    int sz=min(sa,sb);
    int l=0,r=sz;
    if (geta(La,La+sz)==getb(Lb,Lb+sz))
    {
        if (sa==sb) return '=';
        return sa<sb ? '<':'>';
    }
    int ans=l;
    while (l<=r)
    {
        int mid=(r+l)>>1;
        if (geta(La,La+mid)==getb(Lb,Lb+mid)) l=mid+1;
        else
        {
            ans=mid;
            r=mid-1;
        }
    }
    return a[La+ans]<b[Lb+ans] ? '<':'>';
}
void setup()
{
    a="_"+a;
    b="_"+b;
    lt[0]=1;
    for (int i=1;i<=max(la,lb);i++)
        lt[i]=(lt[i-1]*BASE)%MOD;
    for (int i=1;i<=la;i++)
        ha[i]=(ha[i-1]*BASE+(ll)a[i])%MOD;
    for (int i=1;i<=lb;i++)
        hb[i]=(hb[i-1]*BASE+(ll)b[i])%MOD;
}
int main()
{
    freopen(inp,"r",stdin);
    freopen(out,"w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>la>>lb>>a>>b>>q;
    setup();
    while (q--)
    {
        cin>>La>>Ra>>Lb>>Rb;
        cout<<query();
    }
}
