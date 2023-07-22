#include <bits/stdc++.h>
#define TASK ""
#define pb push_back
#define F first
#define S second
#define FOR(i, a, b) for (int i=a; i<=b; i++)
#define FOr(i, a, b) for (int i=a; i<b ; i++)
#define FOD(i, a, b) for (int i=a; i>=b; i--)
#define FOd(i, a, b) for (int i=a; i>b ; i--)
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef vector<int> vi;

const int N=1e6+7;
const int MOD=1e9+7;
const ll INF=(ll)1e18+7;

int main() {
    #ifdef TriPhan
        freopen("TEST.INP","r",stdin);
        freopen("TEST.OUT","w",stdout);
    #else
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    #endif
    int t;cin >>t;
    while (t--) {
        int n,k;
        cin >> n >> k;
        vector<int> v;
        FOR(i,1,k) {
            int x;
            cin >> x;
            v.pb(n-x);
        }
        sort(v.begin(),v.end());
        int ans = 0;
        for(int x:v) {
            n-=x;
            if (n>0)
                ans++;
            else break;
        }
        cout << ans << "\n";

    }
}