#include <bits/stdc++.h>
#define TASK "light"
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

const int N=(int)1e5+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;

vector<int> a[N],b[N];
vector<ii> q[N];
int m,n,k;

void active(int r,int c,int add) {
    int x=q[r][c].F;
    int y=q[r][c].S;
    b[r][c]+=add;
    b[r][y+1]-=add;
    b[x+1][c]-=add;
    b[x+1][y+1]+=add;
}

int real(int i,int j) {
    int tmp=b[i][j]+b[i-1][j]+b[i][j-1]-b[i-1][j-1];
    return (a[i][j]+tmp) % 3;
}
void chot(int i,int j) {
    b[i][j]+=b[i-1][j]+b[i][j-1]-b[i-1][j-1];
}

int solve(int p) {
    FOR(i,0,m+1)
        FOR(j,0,n+1)
            b[i][j]=0;
    int ans=0;
    FOR(i,1,m)
        FOR(j,1,n) {
            int now=real(i,j);
            if (now==p) {
                chot(i,j);
                continue;
            }
            if (q[i][j]==make_pair(0,0))
                return MOD;
            int add=0;
            while (now!=p) {
                ++add;
                now=(now+1) % 3;
            }
            active(i,j,add);
            chot(i,j);
            ans+=add;
        }
    return ans;
}
int main() {
    freopen(TASK".inp","r",stdin);
    freopen(TASK".out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> m >> n >> k;
    FOR(i,0,m+1) {
        a[i].resize(n+2);
        b[i].resize(n+2);
        q[i].resize(n+2);
    }
    FOR(i,1,m)
        FOR(j,1,n) {
            cin >> a[i][j];
            q[i][j]={0,0};
        }
    FOR(i,1,k) {
        int r,c,x,y;
        cin >> r >> c >> x >> y;
        q[r][c]={x,y};
    }
    int ans=min(solve(1),solve(2));
    if (ans==MOD)
        ans=-1;
    cout << ans;
}
