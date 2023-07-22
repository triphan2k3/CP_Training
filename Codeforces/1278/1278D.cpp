#include <bits/stdc++.h>
#define TASK ""
#define pb push_back
#define ii pair<int,int>
#define iii pair<ii,int>
#define ll long long
#define F first
#define S second
#define FOR(i, a, b) for (int i=a; i<=b; i++)
#define FOr(i, a, b) for (int i=a; i<b ; i++)
#define FOD(i, a, b) for (int i=a; i>=b; i--)
#define FOd(i, a, b) for (int i=a; i>b ; i--)
using namespace std;

const int N=(int)1e6+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
int n;
int dsu[N];
ii a[N];

int head(int u) {
    if (dsu[u]<0)
        return u;
    return dsu[u]=head(dsu[u]);
}
int gop(int u,int v) {
    u=head(u);
    v=head(v);
    if (u==v)
        return 0;
    if (u<v)
        swap(u,v);
    dsu[v]+=dsu[u];
    dsu[u]=v;
    return 1;
}
int main() {
    freopen(TASK".INP","r",stdin);
    //freopen(TASK".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    FOR(i,1,n)
        dsu[i]=-1;
    FOR(i,1,n)
        cin >> a[i].F >> a[i].S;
    sort(a+1,a+n+1);
    set<ii> s;
    int numedge=0;
    FOR(i,1,n) {
        while (s.size() && (*s.begin()).F<a[i].F)
            s.erase(s.begin());
        auto it=s.begin();
        while (it != s.end() && (*it).F<a[i].S) {
            if (gop(i,(*it).S)==0) {
                cout << "NO\n";
                return 0;
            } else numedge++;
            it++;
        }
        s.insert({a[i].S,i});
    }
    if (numedge==n-1) cout << "YES\n";
    else cout <<"NO\n";

}
