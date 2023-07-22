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

bool check(int k, vector<int> &asterisk, vector<int> &packman) {
    int id = 0;
    for (int pos:packman) {
        if (abs(pos - asterisk[id]) > k) continue;
        int l = asterisk[id];
        int r = pos + max((k - (pos - l)) / 2, k - (pos - l) * 2);
        if (l > pos) r = pos + k;
        while (id < asterisk.size() && asterisk[id] <= r)
            ++id;
        if (id == asterisk.size()) break;   
    }
    return id == asterisk.size();
}

int main() {
    #ifdef TriPhan
        freopen("TEST.INP","r",stdin);
        freopen("TEST.OUT","w",stdout);
    #else
        ios_base::sync_with_stdio(0);
        cin.tie(0);
    #endif
    int n;
    string s;
    cin >> n >> s;
    vector<int> asterisk, packman;
    FOR(i, 1, n)
        if (s[i - 1] == '*')
            asterisk.pb(i);
        else if (s[i - 1] == 'P')
            packman.pb(i);
    int l = 0, r = 2 * n;
    int ans = r;
    while (l <= r) {
        int m = (l + r) >> 1;
        if (check(m, asterisk, packman)) {
            ans = m;
            r = m - 1;
        } else 
            l = m + 1;
    }
    cout << ans;
}