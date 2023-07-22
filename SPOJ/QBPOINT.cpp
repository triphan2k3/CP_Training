#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define inp "QBPOINT.INP"
#define out "QBPOINT.OUT"
using namespace std;
const double esp=1e-6;
const int N=(int)1e5+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;

ii a[N];
int n;
ll ans;
vector<double> e;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen(inp,"r",stdin);
    freopen(out,"w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>a[i].X>>a[i].Y;

    for (int i=1;i<=n;i++)
    {
        e.clear();
        for (int j=i+1;j<=n;j++)
            if (a[j].Y-a[i].Y!=0)
                 e.pb((double)(a[j].X-a[i].X)/(double)(a[j].Y-a[i].Y));
            else e.pb(1e9);
        sort(e.begin(),e.end());
        e.pb(-1e9);
        int num=1;
        for (int i=1;i<e.size();i++)
            if (e[i]==e[i-1]) num++;
            else
            {
                ans+=1LL*num*(num-1)/2LL;
                num=1;
            }
    }
    cout<<ans;
}
