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

const int N=100+7;
const int MOD=1e9+7;
const ll INF=(ll)1e18+7;
int a[N][N],b[N][N];
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
    while (t--) {
        int m,n,k;
        cin >> m >> n >> k;
        FOR(i,1,m) {
            string s;
            cin >> s;
            FOR(j,1,n) {
                a[i][j] = s[j-1]=='*';
            }
        }
        
        FOR(i,k+1,m)
            FOR(j,k+1,n-k) if (a[i][j]) {
                int sign = 1;
                FOR(h,1,k) 
                    sign = sign & (a[i-h][j+h] & a[i-h][j-h]);
                if (sign == 0) continue;
                int h = 1;
                while (a[i-h][j-h] & a[i-h][j+h]) {
                    b[i-h][j+h] = b[i-h][j-h] = 1;
                    ++h;
                }
                b[i][j] = 1;
            }
        int sign = 1;
        FOR(i,1,m) FOR(j,1,n) sign = sign & (a[i][j] == b[i][j]);
        if (sign) cout << "YES\n";
        else cout << "NO\n";

        FOR(i,1,m) FOR(j,1,n) a[i][j] = b[i][j] = 0;
    }
}