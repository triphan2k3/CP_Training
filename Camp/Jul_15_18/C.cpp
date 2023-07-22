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

long double C(int k, int n) {
    if (k == 0 || k == n)
        return 1.0;
    else 
        return C(k, n - 1) + C(k - 1, n - 1);
}

int main() {
    #ifdef TriPhan
        freopen("TEST.INP","r",stdin);
        freopen("TEST.OUT","w",stdout);
    #else
        ios_base::sync_with_stdio(0);
        cin.tie(0);
    #endif
    string s;
    cin >> s;
    int sum = 0;
    int cnt = 0;
    for (char ch:s)
        if (ch == '+')
            sum++;
        else 
            sum--;
    cin >> s;
    for (char ch:s)
        if (ch == '+')
            sum--;
        else if (ch == '-')
            sum++;
        else 
            cnt++;
    if (cnt < abs(sum)) {
        cout << 0;
        return 0;
    }
    // x + y = cnt
    // x - y = sum 
    // x = (sum + cnt) / 2
    cout << setprecision(9) << fixed << C((sum + cnt) / 2, cnt) / (1 << cnt);
}