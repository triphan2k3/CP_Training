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
        int n; cin >> n;
        vector<ii> a(n);
        int cnt = 0;
        for (ii &x:a) {
            cin >> x.F;
            x.S = cnt++;
        }
        for (ii &x:a) {
            int y; cin >> y; 
            x.F -= y;
            x.F = - x.F;
        }

        sort(all(a));
        vector<int> ans;
        for (int i = 0; i < n; i++)
            if (i == 0 || a[i].F == a[i - 1].F)
                ans.push_back(a[i].S + 1);
            else 
                break;

        sort(all(ans));
        cout << ans.size() << "\n";
        for (int x:ans)
            cout << x << " ";
        cout << "\n";
    }
}