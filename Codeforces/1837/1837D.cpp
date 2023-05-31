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
#define cout std::cout
#define cin std::cin
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
    int t;
    cin >> t;
    while (t--) {
        int n; string s;
        cin >> n >> s;
        int nopen = 0;
        FOR(i, 1, n)
            if (s[i - 1] == '(') ++nopen;
        if (nopen * 2 != n) {
            cout << "-1\n";
            continue;
        }
        int flagp = 1, flagn = 1;
        for (int sump = 0, sumn = 0, i = 0; i < n; i++) {
            sump += (s[i] == ')' ? -1:1);
            sumn += (s[i] == ')' ? -1:1);
            if (sump < 0)
                flagp = 0;
            if (sumn > 0)
                flagn = 0;
        }
        if (flagp || flagn) {
            cout << "1\n";
            FOR(i, 1, n) 
                cout << 1 << " ";
            cout << "\n";
            continue;
        }
        cout << "2\n";
        for (int i = 0; i < n; i++) {
            if (nopen) {
                if (s[i] == '(')
                    cout << 1 << " ";
                else
                    cout << 2 << " ";
                nopen -= 1;
            } else {
                if (s[i] == '(')
                    cout << 2 << " ";
                else 
                    cout << 1 << " ";
            }
        }
        cout << "\n";
    }
}