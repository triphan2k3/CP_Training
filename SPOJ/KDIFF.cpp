#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define pb push_back
#define pf push_front
#define pob pop_back
#define pof pop_front
#define mp make_pair
#define X first
#define Y second
#define inp "KDIFF.INP"
#define out "KDIFF.OUT"
using namespace std;
const int N=(int)1e5+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
deque<int> mi,ma;
int n,k;
int a[3*N];
int f[3*N];
int main()
{
    freopen(inp,"r",stdin);
    freopen(out,"w",stdout);
    cin>>n>>k;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    mi.pb(1);
    ma.pb(1);
    int res=1;
    f[1]=1;
    int maxpos=1;
    int minpos=1;
    for (int i=2;i<=n;i++)
    {
        while (mi.size() && a[mi.back()]>a[i]) mi.pop_back();
        mi.pb(i);
        while (mi.size() && a[i]-a[mi.front()]>k) minpos=mi.front()+1,mi.pop_front();

        while (ma.size() && a[ma.back()]<a[i]) ma.pop_back();
        ma.pb(i);
        while (ma.size() && a[ma.front()]-a[i]>k) maxpos=ma.front()+1,ma.pop_front();

        int pos=max(minpos,maxpos);

        f[i]=max(f[i-1],i-pos+1);
        res=max(res,f[pos-1]+i-pos+1);
    }
    cout<<res;

}
