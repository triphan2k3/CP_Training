#include <bits/stdc++.h>
#define ll long long
#define di pair<double,int>
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define inp "RECT1.INP"
#define out "RECT1.OUT"
using namespace std;
const double esp=0.000001;
const int N=(int)1e5+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
vector<ii> a,b;
vector<di> q;
int n,xmax,ymax;

double cos(ii a)
{
    ll tp=(1LL*a.X*a.X+1LL*a.Y*a.Y);
    return (double)a.X/(double)sqrt(tp);
}
bool cmp(di a,di b)
{
    return abs(a.X-b.X)<esp ? a.Y>b.Y:a.X<b.X;
}
int main()
{
    freopen(inp,"r",stdin);
    freopen(out,"w",stdout);
    cin>>xmax>>ymax>>n;
    for (int i=1;i<=n;i++)
    {
        int xd,yd,xt,yt;
        cin>>xd>>yd>>xt>>yt;
        //xt=min(xt,xmax);
        //yt=min(yt,ymax);
        //if (xd>xmax) xd=xmax;
        //else if (xd<0) xd=0;
        //if (yd>ymax) yd=ymax;
        //else if (yd<0) yd=0;
        a.push_back({xd,yt});
        b.push_back({xt,yd});
    }
    for (ii u:a)
        q.push_back({cos(u),1});
    for (ii u:b)
        q.push_back({cos(u),-1});
    sort(q.begin(),q.end(),cmp);
    int res=0,ans=0;
    for (int i=0;i<q.size();i++)
    {
        res+=q[i].Y;
        ans=max(ans,res);
    }
    cout<<ans;

}
