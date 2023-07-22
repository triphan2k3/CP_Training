#include <bits/stdc++.h>
#define TASK "1453A"
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
int cnt[1000];
int main() {
    //freopen(TASK".INP","r",stdin);
    //freopen(TASK".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n,m;
        cin >> n >> m;
        FOR(i,0,101)
            cnt[i]=0;
        FOR(i,1,n) {
            int x;
            cin >> x;
            cnt[x]++;
        }
        int ans=0;
        FOR(i,1,m) {
            int x;
            cin >> x;
            if (cnt[x])
                ans++;
        }
        cout << ans << "\n";
    }
}
