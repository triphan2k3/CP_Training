#include <bits/stdc++.h>
#define TASK ""
#define pb push_back
#define F first
#define S second
#define FOR(i, a, b) for (int i=a; i<=b; i++)
#define FOr(i, a, b) for (int i=a; i<b ; i++)
#define FOD(i, a, b) for (int i=a; i>=b; i--)
#define FOd(i, a, b) for (int i=a; i>b ; i--)
#define all(a) a.begin(), a.end()
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
    #endif

    // vector<int> u = {1,2,3,4,5,6,7,8,9,10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    // while (1) {
    //     int v = 0;
    //     int ma = 0;
    //     for (int i = 1; i <= 20; i++) {
    //         v+= i * u[i - 1];
    //         ma = max(ma, i * u[i - 1]);
    //     }
    //     if (v - ma == 2529) {
    //         for (int x:u)
    //             cout << x << " ";
    //         cout << "\n";
    //         return 0;
    //     }
    //     if(!next_permutation(all(u))) return 0;
    // }

    int t; cin >> t;
    while (t--) {
        ll n; cin >> n;
        ll ans = 0;
        FOR(i, 0, n) {
            int ma = 0;
            ll sum = 0;
            FOR(j, 1, i) {
                sum += j * j;
                ma = max(ma, j * j);
            }
            for (int j = n, pos = i + 1; j > i; j--, pos++) {
                sum += j * pos;
                ma = max(ma, j * pos);
            }
            if (sum - ma > ans) {
                ans = sum - ma;
            }
        }  
        cout << ans << "\n";      
    }
}