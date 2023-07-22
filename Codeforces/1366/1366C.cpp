#include <bits/stdc++.h>
#define TASK "1366C"
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
int a[100][100];
int main() {
    freopen(TASK".INP","r",stdin);
    freopen(TASK".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n,m;
        int ans=0;
        cin >> n >> m;
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
                cin >> a[i][j];
        for (int st=1;st*2<=m+n-1;st++) {
            int l=st+1;
            int r=m+n-st+1;
            int n0=0;
            int n1=0;
            for (int i=max(1,l-m);i<=min(l-1,n);i++) {
                int j=l-i;
                if (a[i][j]) n1++;
                else n0++;
            }
            for (int i=max(1,r-m);i<=min(r-1,n);i++) {
                int j=r-i;
                if (a[i][j]) n1++;
                else n0++;
            }
            ans+=min(n0,n1);
        }
        cout << ans << "\n";
    }
}
