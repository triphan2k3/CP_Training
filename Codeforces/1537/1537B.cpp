#include <bits/stdc++.h>
#define TASK ""
#define pb push_back
#define ii pair<int,int>
#define iii pair<ii,int>
#define ll long long
#define int long long
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
ii a[5];
int dis(ii a,ii b) {
    return abs(a.F-b.F) + abs(a.S-b.S);
}
main() {
    //freopen(TASK".INP","r",stdin);
    //freopen(TASK".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int m,n;
        ii st;
        cin >> m >> n >> st.F >> st.S;
        a[1]={1,1};
        a[2]={1,n};
        a[3]={m,1};
        a[4]={m,n};
        int u=1,v=2;
        int d = dis(st,a[1])+dis(st,a[2])+dis(a[1],a[2]);
        FOR(i,1,4)
            FOR(j,i+1,4) {
                int tmp = dis(st,a[i])+dis(st,a[j])+dis(a[i],a[j]);
                if (tmp>d) {
                    d=tmp;
                    u=i;
                    v=j;
                }
            }
        cout << a[u].F << " " << a[u].S << " "
        << a[v].F << " " << a[v].S << "\n";
    }
}
