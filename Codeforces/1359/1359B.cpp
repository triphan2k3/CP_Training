#include <bits/stdc++.h>
#define TASK "1359B"
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
int a[N][N];
int main() {
    freopen(TASK".INP","r",stdin);
    freopen(TASK".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n,m,x,y;
        cin >> n >> m >> x >> y;
        FOR(i,1,n) {
            string s;
            cin >> s;
            FOR(j,1,m)
                a[i][j]=s[j-1]=='.' ? 1:0;
        }
        y=min(y,x+x);
        int ans=0;
        FOR(i,1,n) {
            FOR(j,1,m-1)
                if (a[i][j]+a[i][j+1]==2) {
                    ans+=y;
                    a[i][j]=a[i][j+1]=0;
                }
                else if (a[i][j]==1) {
                    ans+=x;
                    a[i][j]=0;
                }
            if (a[i][m]==1)
                ans+=x;
        }
        cout << ans << "\n";
    }

}
