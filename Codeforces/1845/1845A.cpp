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
    int t;
    cin >> t;
    while (t--) {
        int n, k, x;
        cin >> n >> k >> x;
        if (k == 1) {
            cout << "NO\n";
            continue;
        }
        if (x != 1) {
            cout << "YES\n" << n << "\n";
            FOR(i, 1, n)
                cout << "1 ";
            cout << "\n";
            continue;
        }
        if (k == 2 && n % 2 == 1) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n" << n / 2 << "\n";
        if (n % 2)
            cout << "3 ";
        else cout << "2 ";
        while (n > 3) {
            cout << "2 ";
            n -= 2;
        }
        cout << "\n";
    }
}