#include <bits/stdc++.h>
#define TASK "1354B"
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

const int N=(int)2e5+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
int dem[4][N];
int n;
int main() {
    freopen(TASK".INP","r",stdin);
    freopen(TASK".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        n=s.size();
        s=" "+s;
        for (int i=1; i<=n; i++) {
            dem[1][i]=dem[1][i-1]+(s[i]=='1');
            dem[2][i]=dem[2][i-1]+(s[i]=='2');
            dem[3][i]=dem[3][i-1]+(s[i]=='3');
        }
        if (dem[1][n]==0 || dem[2][n]==0 || dem[3][n]==0) {
            cout<<"0\n";
            continue;
        }
        int l=3,r=n,ans=n;
        while (l<=r) {
            int m=(l+r)>>1;
            int kt=0;
            for (int i=1; i+m-1<=n; i++) {
                int j=i+m-1;
                int n1 = dem[1][j]-dem[1][i-1];
                int n2 = dem[2][j]-dem[2][i-1];
                int n3 = dem[3][j]-dem[3][i-1];
                if (n1*n2*n3 != 0) {
                    kt=1;
                    break;
                }
            }
            if (kt) {
                ans=m;
                r=m-1;
            }
            else
                l=m+1;
        }
        cout<<ans<<"\n";
    }
}
