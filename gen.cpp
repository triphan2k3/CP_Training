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
    // freopen("TEST.INP","r",stdin);
    freopen("TEST.INP","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << 100000 << " " << 99990 <<"\n";
    FOR(i, 1, 10)
        FOR(j, 1, 10000) if (j != i)
            cout << i << " " << j << '\n';
    cout << 100000 << "\n";
    vector<int> inU(100, 0);
    FOR(i, 1, 100000) {
        int t = rand() % 2;
        if (t == 0)
            cout << "?\n";
        else {
            int u = rand() % 10 + 1;
            if (inU[u]) {
                cout << "- " << u << "\n";
                inU[u] = 0;
            } else {
                cout << "+ " << u << "\n";
                inU[u] = 1;
            }
        }
    }
}