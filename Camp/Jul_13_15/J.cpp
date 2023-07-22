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

const int N=70007;
const int MOD=1e9+7;
const ll INF=(ll)1e18+7;
const int BLOCK = 24000;

bitset<N> ok[BLOCK];


void dp(int n, vector<ii> &a) {
    ok[0] = 1;
    for (int i = 1; i < n; i++) {
        ok[i % BLOCK] = ok[(i + BLOCK - 1) % BLOCK] | (ok[(i + BLOCK - 1) % BLOCK] << a[i].F);

    }
}

int main() {
    #ifdef TriPhan
        freopen("TEST.INP","r",stdin);
        freopen("TEST.OUT","w",stdout);
    #else
        ios_base::sync_with_stdio(0);
        cin.tie(0);
    #endif
    int n, s;
    cin >> n >> s;
    int maID = 0;
    vector<ii> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].F;
        a[i].S = i;
    }
    sort(all(a));
    reverse(all(a));
    s -= a[0].F;
    if (s < 0) {
        cout << "-1";
        return 0;
    }
    dp(n, a);
    if (!ok[(n - 1) % BLOCK].test(s)) {
        cout << "-1";
        return 0;
    }

    vector<int> choice(n, 0);
    for(int i = n - 1; i > 0; i--) {
        if (i % BLOCK == 0) dp(i - 1, a);

        if (ok[(i - 1) % BLOCK].test(s)) continue;
        choice[i] = true;
        s -= a[i].F;
    }
    vector<vector<int>> ans(n, vector<int> (0));
    int pre = -1;
    int preCoin = 0;
    for (int i = n - 1; i >= 0; i--) 
        if (choice[i]) {
            ans[a[i].S].push_back(a[i].F);
            ans[a[i].S].push_back(0);
        } else {
            if (pre == -1) {
                ans[a[i].S].push_back(a[i].F);
                ans[a[i].S].push_back(0);
                preCoin = a[i].F;
                pre = i;
            } else {
                int nowCoin = a[i].F;
                int id = a[i].S;
                ans[id].push_back(nowCoin - preCoin);
                ans[id].push_back(1);
                ans[id].push_back(a[pre].S + 1);
                preCoin = nowCoin;
                pre = i;
            }
        }
    for (vector<int> &aa:ans) {
        for (int &bb:aa)
            cout << bb << " ";
        cout << "\n";
    }
}