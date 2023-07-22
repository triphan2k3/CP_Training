#include <bits/stdc++.h>
#define TASK "1195E"
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

const int N=(int)3e3+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
ll h[N][N],c[N][N];
ll f,x,y,z;
int m,n,a,b;
int main() {
    //freopen(TASK".INP","r",stdin);
    //freopen(TASK".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> m >> n >> a >> b >> f >> x >> y >> z;
    h[1][1]=f;
    int ni=1,nj=1;
    FOR(i,2,m*n) {
        f=(f * x + y) % z;
        nj++;
        if (nj>n) {
            nj=1;
            ni++;
        }
        h[ni][nj]=f;
    }

    FOR(i,1,m) {
        deque<int> q;

        FOR(j,1,n) {
            while (q.size() && h[i][q.back()] >= h[i][j])
                q.pop_back();
            while (q.size() && j-q.front()+1 > b)
                q.pop_front();
            q.push_back(j);
            if (j>=b)
                c[i][j-b+1]=h[i][q.front()];
        }
    }
    ll ans=0;
    FOR(i,1,n-b+1) {
        deque<int> q;
        FOR(j,1,m) {
            while (q.size() && c[q.back()][i] >= c[j][i])
                q.pop_back();
            while (q.size() && j-q.front()+1 > a)
                q.pop_front();
            q.push_back(j);
            if (j>=a)
                ans+=c[q.front()][i];
        }
    }
    cout << ans;

}
