#include <bits/stdc++.h>
#define TASK ""
#define pb push_back
#define F first
#define S second
#define FOR(i, a, b) for (int i=a; i<=b; i++)
#define FOr(i, a, b) for (int i=a; i<b ; i++)
#define FOD(i, a, b) for (int i=a; i>=b; i--)
#define FOd(i, a, b) for (int i=a; i>b ; i--)
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef vector<int> vi;

const int N=400+7;
const int MOD=1e9+7;
const ll INF=(ll)1e18+7;
int a[N][N],s[N][N];
int n,m;

int sum (int i, int j, int u, int v) {
    return s[u][v] -s[u][j-1]-s[i-1][v]+s[i-1][j-1];
}
int ck(int u, int d, int l, int r) {
    int a1 = sum(u+1,l+1,d-1,r-1) ;
    int a2 = 2*(d-u-1) - sum(u+1,l,d-1,l) - sum(u+1,r,d-1,r); 
    int a3 = 2*(r-l-1) - sum(u,l+1,u,r-1) - sum(d,l+1,d,r-1);
    return a1+a2+a3;
}
int main() {
    #ifdef TriPhan
        freopen("TEST.INP","r",stdin);
        freopen("TEST.OUT","w",stdout);
    #else
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    #endif
    int t; cin >> t;
    t = 1;
    while (t--) {
        cin >> n >> m;
        FOR(i,1,n) {
            string s;
            cin >> s;
            FOR(j,1,m)
                a[i][j] = s[j-1]-'0';
        }
        FOR(i,1,n) FOR(j,1,m) s[i][j] = s[i-1][j] + s[i][j-1] - s[i-1][j-1] + a[i][j];
        int ans = 16;
        FOR(u,1,n)
            FOR(d,u+4,n) {
                FOR(l,1,m-3) {
                    FOR(r,l+3,m) {
                        int t = ck(u,d,l,r);
                        if (t>16) break;
                        ans = min(ans,ck(u,d,l,r));
                    }
                }
            }
        cout << ans << "\n";
    }
}