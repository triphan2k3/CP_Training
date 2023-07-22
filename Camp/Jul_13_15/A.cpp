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
    int c1, c2, c3, c4;
    cin >> c1 >> c2 >> c3 >> c4;
    int n, m;
    cin >> n >> m;
    int ansBus = 0;
    FOR(i, 1, n) {
        int x; cin >> x;
        ansBus += min(c1 * x, c2);
    }
    ansBus = min(ansBus, c3);
    int ansTro = 0;
    FOR(i, 1, m) {
        int x; cin >> x;
        ansTro += min(c1 * x, c2);
    }
    ansTro = min(ansTro, c3);
    cout << min(c4, ansBus + ansTro);
}