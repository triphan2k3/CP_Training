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

int pMax[22][N];

void setTable(vector<int> a) {
    int n = a.size() - 2;
    FOR(i, 1, n)
        pMax[0][i] = a[i];
    FOR(k, 1, 19) 
        for (int i = 1; i <= n; i++) {
            pMax[k][i] = max(pMax[k - 1][i], pMax[k - 1][min(n, i + (1 << (k - 1)))]);
        }
    return;
}

ll prepare[N];

int main() {
    #ifdef TriPhan
        freopen("TEST.INP","r",stdin);
        freopen("TEST.OUT","w",stdout);
    #else
        ios_base::sync_with_stdio(0);
        cin.tie(0);
    #endif
    int t; cin >> t;
    FOR(i, 1, N - 1) 
        prepare[i] = prepare[i - 1] + 1LL * i * (i - 1) / 2;

    while (t--) {
        int n; cin >> n;
        vector<int> a(n + 2, 0);
        FOR(i, 1, n)
            cin >> a[i];
        vector<int> miL(n + 2, 0), miR(n + 2, 0);
        vector<int> miS, maS;
        FOR(i, 1, n) {
            while (miS.size() && a[i] < a[miS.back()])
                miS.pop_back();
            if (miS.size())
                miL[i] = miS.back() + 1;
            else 
                miL[i] = 1;
            miS.push_back(i);
        }
        miS.clear();
        FOD(i, n, 1) {
            while (miS.size() && a[i] < a[miS.back()])
                miS.pop_back();
            if (miS.size())
                miR[i] = miS.back() - 1;
            else 
                miR[i] = n;
            miS.push_back(i);
        }
        a[0] = MOD;
        setTable(a);
        ll ans = prepare[n];
        
        FOR(i, 1, n) {
            int k = miL[i] - 1;
            int y = miR[i] + 1;
            int x = k;
            FOD(j, 19, 0) if (x >= (1 << j)) 
                if (pMax[j][x - (1 << j) + 1] < a[i])
                    x -= (1 << j);
            ans -= 1LL * (k - x) * (y - i);
        }
        cout << ans << "\n";
    }
}