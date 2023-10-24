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
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> mx = {-1}, mi = {-1};
    vector<ii> que;
    ll cur = 0, ans = 0;
    FOr(i, 0, n) {
        cin >> a[i];
        // max stack
        while (mx.back() != -1 && a[mx.back()] < a[i])
            mx.pop_back();
        int l = mx.back() + 1;
        mx.push_back(i);
        while (que.size() != 0 && que.back().S >= l) {
            int x = que.back().F;
            int y = que.back().S;
            que.pop_back();
            cur -= y - x + 1;
            if (x < l) {
                cur += l - x;
                que.push_back({x, l - 1});
            }
        }        
        que.push_back({l, i});
        cur += i - l + 1;

        while (mi.back() != -1 && a[mi.back()] > a[i])
            mi.pop_back();
        l = mi.back() + 1;
        mi.push_back(i);
        while (que.size() != 0 && que.back().S >= l) {
            int x = que.back().F;
            int y = que.back().S;
            que.pop_back();
            cur -= y - x + 1;
            if (x < l) {
                cur += l - x;
                que.push_back({x, l - 1});
            }
        }
        ans += cur;
    }
    cout << ans;
}