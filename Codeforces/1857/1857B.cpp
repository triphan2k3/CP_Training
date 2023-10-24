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
        int id = -1;
        for (int i = 0; i < s.size(); i++)
            if (s[i] >= '5') {
                id = i;
                break;
            }
        if (id == -1) {
            cout << s << "\n";
            continue;
        }
        string ans;
        for (int i = s.size() - 1; i >= id; i--)
            ans.push_back('0');

        int done = 0;
        for (int i = id - 1; i >= 0; i--) {
            if (done) {
                ans.push_back(s[i]);
                continue;
            }
            if (s[i] >= '4')
                ans.push_back('0');
            else {
                ans.push_back(s[i] + 1);
                done = 1;
            }
        }
        if (!done)
            ans.push_back('1');
        reverse(all(ans));
        cout << ans << "\n";
    }
}