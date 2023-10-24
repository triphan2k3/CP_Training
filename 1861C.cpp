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
        vector<int> state(s.size() + 5, 0);
        vector<int> num;
        string ans = "YES";

        for (int i = 1; i <= s.size(); i++) {
            int type = s[i - 1];
            if (type == '+') {
                num.push_back(i);
                if (num.size() == 1)
                    state[num.back()] = 1;
            } else if (type == '-') {
                num.pop_back();
            } else if (type == '1') {
                if (num.size() < 2)
                    continue;

                if (state[num.back()] == -1)
                    ans = "NO";
                for (int i = num.size() - 1; state[num[i]] != 1; i--) {
                    if (state[num[i]] == -1)
                        ans = "NO";
                    state[num[i]] = 1;
                }
            } else {
                if (num.size() < 2) {
                    ans = "NO";
                    continue;
                }
                if (state[num.back()] == 1)
                    ans = "NO";
                state[num.back()] = -1;
            }
        }
        int isBegin = 0;
        while (num.size()) {
            if (state[num.back()] == -1 && isBegin)
                ans = "NO";
            if (state[num.back()] == 1)
                isBegin = 1;
            num.pop_back();
        }
        cout << ans << "\n";
    }
}