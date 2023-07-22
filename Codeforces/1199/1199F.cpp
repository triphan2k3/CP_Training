#include <bits/stdc++.h>
#define TASK "1199F"
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

const int N=(int)52;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
int f[N][N][N][N];
int s[N][N],a[N][N];
int n;

bool full(int x,int y,int u,int v) {
    return s[u][v]-s[x-1][v]-s[u][y-1]+s[x-1][y-1] == 0;
}
int main() {
    //freopen(TASK".INP","r",stdin);
    //freopen(TASK".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    FOR(i,1,n) {
        string S;
        cin >> S;
        FOR(j,1,n)
            a[i][j]=(S[j-1]=='#') ? 1:0;
    }

    FOR(i,1,n)
        FOR(j,1,n)
            s[i][j] = s[i][j-1]+s[i-1][j]+a[i][j]-s[i-1][j-1];

    FOR(h,1,n) FOR(w,1,n)
    FOR(i,1,n-h+1)
        FOR(j,1,n-w+1) {
            int x=i+h-1;
            int y=j+w-1;
            f[i][j][x][y]=full(i,j,x,y)? 0:max(h,w);

            FOR(th,1,h-1)
                f[i][j][x][y]=min(f[i][j][x][y],f[i][j][i+th-1][y]+f[i+th][j][x][y]);

            FOR(tw,1,w-1)
                f[i][j][x][y]=min(f[i][j][x][y],f[i][j][x][j+tw-1]+f[i][j+tw][x][y]);
        }
    cout << f[1][1][n][n];

}
