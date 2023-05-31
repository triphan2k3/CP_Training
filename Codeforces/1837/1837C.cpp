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
        string s;
        cin >> s;
        if (s[0] == '?') {
            for (int i = 1;i < s.size(); i++)
                if (s[i] != '?') {
                    for (int j = 0; j < i; j++)
                        s[j] = s[i];
                    break;
                }
        }
        if (s[0] == '?') {
            FOr(i, 0, s.size())
                cout << 0;
            cout << "\n";
            continue;
        }
        FOr(i, 0, s.size())
            if (s[i] == '?')
                s[i] = s[i - 1];
        cout << s << "\n";
    }
}