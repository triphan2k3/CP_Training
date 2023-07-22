#include <bits/stdc++.h>
#define TASK "1345D"
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
const int x[4]={1,-1, 0, 0};
const int y[4]={0, 0, 1,-1};
string a[N];
int m,n;
int col[N],row[N],ncol[N],nrow[N];
int c[N][N];
void dfs(int i,int j) {
    c[i][j]=1;
    col[j]=1;
    row[i]=1;

    for(int u=0;u<4;u++) {
            int ni=i+x[u];
            int nj=j+y[u];
            if (ni==m || ni<0) continue;
            if (nj==n || nj<0) continue;
            if (c[ni][nj] || a[ni][nj]=='.') continue;
            dfs(ni,nj);
        }
    return;
}
int main() {
    freopen(TASK".INP","r",stdin);
    freopen(TASK".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> m >> n;

    FOr(i,0,m)
        cin >> a[i];

    FOr(i,0,m) {
        int num=(a[i][0]=='#') ? 1:0;
        FOr(j,1,n)
            if (a[i][j]=='#' && a[i][j-1]=='.')
                num++;
        if (num > 1) {
            cout<<-1;
            return 0;
        }
    }

    FOr(j,0,n) {
        int num=(a[0][j]=='#') ? 1:0;
        FOr(i,1,m)
            if (a[i][j]=='#' && a[i-1][j]=='.') num++;
        if (num>1) {
            cout<<-1;
            return 0;
        }
    }

    int ans=0;
    FOr(i,0,m)
        FOr(j,0,n) if (!c[i][j] && a[i][j]=='#') {
            dfs(i,j);
            ans++;
        }

    FOr(i,0,m)
        FOr(j,0,n)
            if (!row[i] && !col[j]) nrow[i]=ncol[j]=1;
    FOr(i,0,m)
        row[i]|=nrow[i];
    FOr(i,0,n)
        col[i]|=ncol[i];
    int ok=1;
    FOr(i,0,n)
        ok&=col[i];
    FOr(i,0,m)
        ok&=row[i];

    if (ok)
        cout<<ans;
    else
        cout<<-1;
    return 0;
}
