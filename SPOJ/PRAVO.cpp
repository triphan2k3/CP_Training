#include <bits/stdc++.h>
#define ll long long
#define ii pair<ll,ll>
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define inp "PRAVO.INP"
#define out "PRAVO.OUT"
using namespace std;
const double esp=0.000001;
const int N=(int)1e4+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
ll x[N],y[N];
int n;
vector<ii> vt,vp;
bool cmp(ii a,ii b)
{
    return a.X*b.Y<a.Y*b.X;
}

bool ifbe(ii a,ii b)
{
    return a.X*b.Y<a.Y*b.X;
}

bool ifbang(ii a,ii b)
{
    return a.X*b.Y==a.Y*b.X;
}
int main()
{
    freopen(inp,"r",stdin);
    freopen(out,"w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>x[i]>>y[i];
    ll ans=0;
    for (int i=1;i<=n;i++)
    {
        ll numx=0;
        ll numy=0;
        vt.clear();
        vp.clear();
        for (int j=1;j<=n;j++)
            if (j!=i)
        {
            ll _x=x[j]-x[i];
            ll _y=y[j]-y[i];
            if (_x==0) numx++;
            if (_y==0) numy++;
            if (_x!=0 && _y!=0)
            {
                if (_y<0 && _x>0)
                {
                    _x*=-1;
                    _y*=-1;
                }
                if (_y<0 && _x<0)
                {
                    _x*=-1;
                    _y*=-1;
                }

                vt.pb({_x,_y});
                if (_x<0 && _y>0)
                {
                    _x*=-1;
                    _y*=-1;
                }
                vp.pb({-_y,_x});
            }
        }
        ans+=2LL*numx*numy;
        sort(vt.begin(),vt.end(),cmp);
        sort(vp.begin(),vp.end(),cmp);
        int t=0,p=0;
        while (t<vt.size() && p<vp.size())
        {
            if (ifbe(vp[p],vt[t])) {p++; continue;}
            if (ifbe(vt[t],vp[p])) {t++; continue;}
            ll u=1,v=1;
            t++;
            if (t!=vt.size())
            while (ifbang(vt[t],vt[t-1]))
            {
                t++;
                u++;
                if (t==vt.size()) break;
            }
            p++;
            if (p!=vp.size())
            while (ifbang(vp[p],vp[p-1]))
            {
                p++;
                v++;
                if (p==vp.size()) break;
            }
            ans+=u*v;
        }

    }
    cout<<ans/2LL;

}
