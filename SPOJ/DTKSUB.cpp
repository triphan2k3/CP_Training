#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define inp "DTKSUB.INP"
#define out "DTKSUB.OUT"
using namespace std;
const int N=50007;
const ll MOD=(ll)1e9+7;
const ll BASE=31;
const ll INF=(ll)1e18+7;

string s;
int n,k;
ll h[N],lt[N];

ll gethash(int i,int j)
{
    return (MOD*MOD+h[j]-h[i-1]*lt[j-i+1])%MOD;
}
bool ck(int val)
{
    vector<ll> v;
    for (int i=1;i+val-1<=n;i++)
        v.push_back(gethash(i,i+val-1));
    sort(v.begin(),v.end());
    int ans=1;
    for (int i=1;i<v.size();i++)
    {
        ans=v[i]==v[i-1] ? ans+1:1;
        if (ans==k) return true;
    }
    return false;

}
void setup()
{
    lt[0]=1LL;
    for (int i=1;i<=n;i++)
        lt[i]=(lt[i-1]*BASE)%MOD;

    for (int i=1;i<=n;i++)
        h[i]=(h[i-1]*BASE+(ll)(s[i]-96))%MOD;
}
int main()
{
    freopen(inp,"r",stdin);
    freopen(out,"w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k>>s;
    if (k==1)
    {
        cout<<n;
        return 0;
    }
    s=" "+s;
    setup();
    int l=0,r=n;
    while (r-l>1)
    {
        int mid=(l+r)>>1;
        if (ck(mid)) l=mid;
        else r=mid;
    }
    if (ck(r)) cout<<r;
    else cout<<l;
}
