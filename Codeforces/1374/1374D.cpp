#include <bits/stdc++.h>
#define TASK "1374D"
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
int main() {
    freopen(TASK".INP","r",stdin);
    freopen(TASK".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n,k;
        cin >> n >> k;
        vector<int> a;
        FOR(i,1,n) {
            int q;
            cin >> q;
            if (q%k) a.push_back(q%k);
        }
        if (a.empty()) {
            cout << "0\n";
            continue;
        }
        sort(a.begin(),a.end());
        ll ans=k-a[0];
        ll sl=1;
        for (int i=1;i<a.size();i++) {
            if (a[i]!=a[i-1])
                sl=1;
            else sl++;
            ans=max(ans,1LL*k*(sl-1)+k-a[i]);
        }
        cout << ans+1 << "\n";
    }
}
