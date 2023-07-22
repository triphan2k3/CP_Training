#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define inp "MILITARY.INP"
#define out "MILITARY.OUT"
using namespace std;
const int N=(int)1e5+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;

vector<ii> a;
vector<int> tren,duoi,e;
int kt[N];
int n;

int cw(ii a,ii b,ii c)
{
    ii ba={a.X-b.X,a.Y-b.Y};
    ii bc={c.X-b.X,c.Y-b.Y};
    int tcheo=ba.X*bc.Y-ba.Y*bc.X;
    if (tcheo==0) return 0;
    return (tcheo<0) ? -1:1;
}
int area()
{
    int s=0;
    for (int i=1;i<=e.size();i++)
        s+=a[e[i%e.size()]].X*(a[e[i-1]].Y-a[e[(i+1)%e.size()]].Y);
    if (s!=0) return 1;
    return 0;
}
bool convex_hull()
{
    tren.clear();
    duoi.clear();

    for (int i=0;i<a.size();i++)
    {

            while (tren.size()>=2 && cw(a[tren[tren.size()-2]],a[tren[tren.size()-1]],a[i])==-1)
                tren.pop_back();
            tren.push_back(i);

            while (duoi.size()>=2 && cw(a[duoi[duoi.size()-2]],a[duoi[duoi.size()-1]],a[i])==1)
                duoi.pop_back();
            duoi.push_back(i);
    }
    e.clear();
    for (int i=0;i<tren.size();i++)
        e.pb(tren[i]);
    for (int i=duoi.size()-2;i>0;i--)
        e.pb(duoi[i]);
    if (area()==0) return false;
    return true;
}
void loaidiem()
{
    for (int i=0;i<a.size();i++)
        kt[i]=0;
    for (int i=0;i<e.size();i++)
        kt[e[i]]=1;
    vector<ii> b;
    for (int i=0;i<a.size();i++)
        if (!kt[i])
            b.pb(a[i]);
    a=b;
    return;
}
int main()
{
    freopen(inp,"r",stdin);
    freopen(out,"w",stdout);
    cin>>n;
    a.resize(n);
    for (int i=0;i<n;i++)
        cin>>a[i].X>>a[i].Y;
    sort(a.begin(),a.end());
    int res=0;
    while (1)
    {
        if (!convex_hull()) break;
        loaidiem();
        res++;
    }
    cout<<res;
}
