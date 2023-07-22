#include <bits/stdc++.h>
#define TASK "1366B"
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
ii a[1000];
int ok[1000];
int main() {
    freopen(TASK".INP","r",stdin);
    freopen(TASK".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n,x,m;
        cin >> n >> x >> m;
        int f=m+1;
        for (int i=1;i<=m;i++) {
            ok[i]=0;
            cin >> a[i].F >> a[i].S;
            if (a[i].F <= x && a[i].S >= x) {
                ok[i]=1;
                f=min(f,i);
            }
        }
        vector<ii> ans;
        for (int i=f;i<=m;i++)
        if (ok[i]) {
            ans.pb(a[i]);
            for (int j=i+1;j<=m;j++)
                if (a[j].F<=a[i].S && a[i].F<=a[j].S)
                    ok[j]=1;
        }
        sort(ans.begin(),ans.end());
        if (ans.size()==0) {
            cout << "1\n";
            continue;
        }
        int res=ans[0].S-ans[0].F+1;
        int nr=ans[0].S;
        for (int i=1;i<ans.size();i++) {
            if (ans[i].S < nr) continue;
            if (ans[i].F > nr) {
                res+=ans[i].S-ans[i].F+1;
                nr=ans[i].S;
                continue;
            }
            res+=ans[i].S-nr;
            nr=ans[i].S;
        }
        cout << res << "\n";
    }
}
