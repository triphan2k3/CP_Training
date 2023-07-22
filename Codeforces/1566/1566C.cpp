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
    int t; cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string a,b;
        cin >> a >> b;
        a = '#' + a;
        b = '#' + b;
        int ans = 0;
        int cur0 = 0, cur1 = 0;
        FOR(i,1,n) {
            int sum = a[i] + b[i] - '0' - '0';
            if (sum == 1) {
                ans += 2 + cur0;
                cur0 = cur1 = 0; 
            }
            if (sum == 0) {
                if (cur1) {
                    ans += 2;
                    cur0 = cur1 = 0;
                } else {
                    ans += cur0;
                    cur0 = 1;
                }
            }
            if (sum == 2) {
                if (cur0) {
                    ans += 2;
                    cur0 = cur1 = 0;
                } else 
                    cur1 = 1;
            }
        }
        ans += cur0;
        cout << ans << "\n";
    }
}