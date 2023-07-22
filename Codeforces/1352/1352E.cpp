#include <bits/stdc++.h>
#define TASK "1352E"
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

void solve() {
    int n;
    cin >> n;
    vector<int> a(n+2,0);
    FOR(i, 1, n)
        cin >> a[i];

    int ans=0;
    FOR(i,1,n) {
        int r=0;
        int sum=0;
        int ok=0;
        FOR(l,1,n) {
            sum-=a[l-1];
            while (sum <a[i] && r<n)
                sum += a[++r];
            if (sum==a[i] && r-l)
                ok=1;
        }
        ans += ok;
    }
    cout << ans <<"\n";


}
int main() {
    freopen(TASK".INP","r",stdin);
    freopen(TASK".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}
