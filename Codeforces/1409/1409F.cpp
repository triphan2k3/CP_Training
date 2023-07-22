#include <bits/stdc++.h>
#define TASK "1409F"
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

const int N=207;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
int f[N][N][N];
int main() {
    //freopen(TASK".INP","r",stdin);
    //freopen(TASK".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin >> n >> m;
    string s,t;
    cin >> s >> t;
    if (t[0]==t[1]) {
        int cnt=0;
        for (int i=0;i<s.size(); i++)
            if (s[i] != t[0])
                cnt++;
        int na=s.size()-cnt;
        na+=min(cnt,m);
        cout << na*(na-1)/2;
        return 0;
    }
    FOR(i,0,n)
        FOR(j,0,n)
            FOR(k,0,n)
                f[i][j][k]=-1;
    f[0][0][0]=0;
    s=" "+s;
    FOR(i,1,n)
        FOR(j,0,min(i,m))
            FOR(k,0,i) {
                f[i][j][k]=f[i-1][j][k];
                if (k>0 && s[i]==t[0] && f[i-1][j][k-1]>=0)
                    f[i][j][k]=max(f[i][j][k],f[i-1][j][k-1]);
                if (s[i]==t[1] && f[i-1][j][k]>=0)
                    f[i][j][k]=max(f[i][j][k],f[i-1][j][k]+k);
                if (j==0) continue;

                if (k>0 && f[i-1][j-1][k-1]>=0)
                    f[i][j][k]=max(f[i][j][k],f[i-1][j-1][k-1]);
                if (f[i-1][j-1][k]>=0)
                    f[i][j][k]=max(f[i][j][k],f[i-1][j-1][k]+k);
            }
    int ans=0;
    FOR(i,0,n)
        ans=max(ans,f[n][m][i]);

    cout << ans;

}
