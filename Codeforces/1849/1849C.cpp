#include <bits/stdc++.h>
#define TASK ""
#define pb push_back
#define F first
#define S second
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define FOr(i, a, b) for (int i = a; i < b; i++)
#define FOD(i, a, b) for (int i = a; i >= b; i--)
#define FOd(i, a, b) for (int i = a; i > b; i--)
#define all(a) a.begin(), a.end()
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef vector<int> vi;

const int N = 1e6 + 7;
const int MOD = 1e9 + 7;
const ll INF = (ll)1e18 + 7;

int main()
{
#ifdef TriPhan
    freopen("TEST.INP", "r", stdin);
    freopen("TEST.OUT", "w", stdout);
#else
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        string s;
        cin >> n >> m >> s;
        vector<int> sum(n + 1, 0);
        FOR(i, 1, n)
        sum[i] = sum[i - 1] + s[i - 1] - '0';
        vector<int> left0(n + 1, n + 1), righ1(n + 1, 0);
        int pos = 0;
        FOR(i, 1, n)
        {
            if (s[i - 1] == '0')
                pos = i;
            left0[i] = pos;
        }
        pos = n + 1;
        FOD(i, n, 1)
        {
            if (s[i - 1] == '1')
                pos = i;
            righ1[i] = pos;
        }
        vector<ii> que;
        // for (int i = 1; i <= n; i++)
        //     cout << left0[i] << " " << righ1[i] << "\n";
        FOR(i, 1, m)
        {
            int l, r;
            cin >> l >> r;
            l = righ1[l];
            r = left0[r];
            if (l < r)
                que.pb({l, r});
            else
                que.pb({0, 0});
            // cout << l << " " << r << "\n";
        }
        sort(all(que));
        int ans = 1;
        for (int i = 1; i < que.size(); i++)
            if (que[i] != que[i - 1])
                ++ans;
        cout << ans << "\n";
    }
}