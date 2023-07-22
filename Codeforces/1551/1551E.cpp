#include <bits/stdc++.h>
#define TASK ""
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

const int N=(int)2e3+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
int n,k;
int f[N][N];
int nxt[N][N];
int a[N];

int main() {
    //freopen(TASK".INP","r",stdin);
    //freopen(TASK".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        FOR(i,1,n)
            cin >> a[n-i+1];
        FOR(i,1,n) FOR(j,1,n) f[i][j]=-1;
        FOR(i,1,n) {
            if (i==a[n]) {
                f[n][i]=1;
                nxt[n][i]=n;
            } else {
                if (i==1) {
                    f[n][i]=0;
                    nxt[n][i]=-1;
                }
                else
                f[n][i]=nxt[n][i]=-1;
            }
            f[n+1][i]=-1;
        }
        FOD(i,n-1,1)
        FOR(j,1,n) {
            if (a[i]==j)
                nxt[i][j]=i;
            else
                nxt[i][j]=nxt[i+1][j];
            if (nxt[i][j]>=0) {
                f[i][j]=(j==1)? 1:1+f[nxt[i][j]+1][j-1];
            }
            f[i][j]=max(f[i][j],f[i+1][j-1]);
        }
        int res=-1;
        FOD(i,n,1) {
            if (f[1][i]>=k) {
                res=n-i;
                break;
            }
        }
        cout << res << "\n";
    }
}
