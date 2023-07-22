#include <bits/stdc++.h>
#define TASK "1350E"
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

const int N=(int)1e3+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
const int x[4]={0, 0,1,-1};
const int y[4]={1,-1,0, 0};
int n, m, t;
int a[N][N],b[N][N];

int main() {
    freopen(TASK".INP","r",stdin);
    freopen(TASK".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> t;
    FOR(i, 1, n) {
        string s;
        cin >> s;
        FOR(j, 1, m)
            a[i][j] = s[j-1]-'0'+1;
    }

    queue<ii> q;
    FOR(i, 1, n)
        FOR(j, 1, m) {
            FOR(k, 0, 3)
                if (a[i][j]==a[i+x[k]][j+y[k]])
                    b[i][j]=1;
            if (b[i][j]==1) q.push({i,j});
        }
    while (q.size()) {
        int i=q.front().F;
        int j=q.front().S;
        q.pop();
        FOR(k, 0, 3) {
            int ni=i+x[k];
            int nj=j+y[k];
            if (a[i][j]+a[ni][nj]==3 && b[ni][nj]==0) {
                b[ni][nj]=b[i][j]+1;
                q.push({ni,nj});
            }
        }
    }

    while (t--) {
        int i, j;
        long long p;
        cin >> i >> j >> p;
        int ans=a[i][j]-1;
        if (p >= b[i][j] && b[i][j] > 0)
            if ( (p - b[i][j]) % 2 == 0) ans ^= 1;
        cout << ans << "\n";
    }
}
