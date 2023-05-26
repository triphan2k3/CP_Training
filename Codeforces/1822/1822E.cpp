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
        std::cin.tie(0);
    #endif
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        string s;
        std::cin >> n >> s;
        if (n & 1) {
            std::cout << "-1\n";
            continue;
        }
        vector<int> cnt(26, 0);
        vector<int> cntp(26, 0);
        int ans = 0;
        FOr(i, 0, n / 2) {
            cnt[s[i] - 'a']++;
            cnt[s[n - i - 1] - 'a']++;
            if (s[i] == s[n - i - 1])
                cntp[s[i] - 'a']++, ans++;
            
        }
        sort(cntp.begin(), cntp.end());
        reverse(cntp.begin(), cntp.end());
        int ma = 0;
        int cma = 0;
        FOr(i, 0 ,26)
            if (cnt[i] > ma) {
                ma = cnt[i];
                cma = i;
            }
        if (cntp[0] > (ans + 1) / 2) {
            ans = cntp[0];
        }
        else
            ans = (ans + 1) / 2;
        if (ma > n / 2) {
            std::cout << "-1\n";
            continue;
        }
        std::cout << ans << "\n";
    }
}