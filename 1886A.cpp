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
    int t; cin >> t; 
    while (t--) {
        int n; 
        cin >> n;
        if (n <= 6 || n == 9) {
            cout << "NO\n";
            continue;
        }
        if (n % 3 == 0) {
            int a = 1, b = 4, c = n - 5;
            cout << "YES\n";
            cout << a << " " << b << " " << c << "\n";
            continue;
        }
        int a = 1, b = 2, c = n - 3;
        cout << "YES\n";
        cout << a << " " << b << " " << c << "\n";
    }
}