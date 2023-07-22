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
    int n, m;
    cin >> n >> m;
    vector<int> co(n + 1, 0);
    FOR(i, 1, m) {
        int a, b, c;
        cin >> a >> b >> c;
        if (co[b])
            swap(b, a);
        if (co[c])
            swap(c, a);

        if (!co[a])
            co[a] = 1;
        if (co[a] == 1)
            co[b] = 2;
        else
            co[b] =1;
        co[c] = 6 - co[a] - co[b];
    }
    for (int c:co)
    if (c!=0)
        cout << c << " ";
}