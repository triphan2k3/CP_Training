#include <bits/stdc++.h>
#define TASK "1455D"
#define pb push_back
#define ii pair<int,int>
#define iii pair<ii,int>
#define ll long long
#define F first
#define S second
#define FOR(i, a, b) for (int i=a; i<=b; i++)
#define FOr(i, a, b) for (int i=a; i<b ; i++)
#define FOD(i, a, b) for (int i=a; i>=b; i--)
#define FOd(i, a, b) for (int i=a; i>b ; i--)
using namespace std;

const int N=(int)1e6+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
int f[2][507][507];
int a[507];

int main() {
    freopen(TASK".INP","r",stdin);
    freopen(TASK".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n,x;
        cin >> n >> x;
        FOR(i,1,n)
            cin >> a[i];

        FOR(i,0,500)
            FOR(j,0,500)
                f[0][i][j] = f[1][i][j] = 501;

        f[1][a[1]][x] = 0;
        if (a[1] > x)
            f[1][x][a[1]] = 1;
        FOr(i,1,n) {
            FOR(j,0,500)
            FOR(k,0,500)
                if (f[i&1][j][k] != 501) {
                    int t = (i+1)&1, pre = f[i&1][j][k];
                    if (a[i+1] >= j)
                        f[t][a[i + 1]][k]=min(f[t][a[i + 1]][k],pre);
                    if (a[i+1] > k && k >= j)
                    f[t][k][a[i + 1]]=min(f[t][k][a[i + 1]], pre + 1);
                }

            FOR(j,0,500)
            FOR(k,0,500)
                    f[i & 1][j][k] = 501;
        }

        int ans = 501;
        FOR(i,0,500)
            FOR(j,0,500)
                ans=min(ans, f[n & 1][i][j]);
        if (ans==501)
            cout << -1 << "\n";
        else
            cout << ans << "\n";
    }
}
