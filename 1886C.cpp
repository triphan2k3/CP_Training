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
        string s; cin >> s;
        int n = s.size();
        ll pos; cin >> pos;
        int id;
        for (int i = s.size(); i > 0; i--) {
            if (pos > i)
                pos -= i;
            else {
                id = i;
                break;
            }
        }
        s = " " + s;
        vector<int> lst(26, n + 1);
        vector<int> nxt(n + 1, n + 1);
        FOD(i, n, 1) {
            int ch = s[i] - 'a';
            FOr(j, 0, ch)
                nxt[i] = min(nxt[i], lst[j]);
            lst[ch] = i;
        }
        string ans;
        for (int i = 1; ans.size() != id; ) {
            int ni = nxt[i];
            if (n - ni + 1 + ans.size() >= id && ni != n + 1) {
                i = ni;
                continue;
            }
            ans.push_back(s[i]);
            i++;
        }
        cout << ans[pos - 1];
    }
}