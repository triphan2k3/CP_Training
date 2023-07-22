#include <bits/stdc++.h>
#define TASK "1453C"
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

int a[N][N];
int L[N][10],R[N][10],U[N][10],D[N][10];
int up[10],dw[10],lf[10],rg[10],ans[10],cnt[10];
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
        cin >> n;

        FOR(i,0,9) {
            up[i]=lf[i]=n+1;
            dw[i]=rg[i]=0;
            ans[i]=cnt[i]=0;
        }
        FOR(j,0,9)
        FOR(i,1,n) {
            L[i][j]=U[i][j]=n+1;
            R[i][j]=D[i][j]=0;
        }

        FOR(i,1,n) {
            string s;
            cin >> s;
            FOR(j,1,n) {
                a[i][j]=s[j-1]-'0';
                cnt[a[i][j]]++;
                up[a[i][j]]=min(up[a[i][j]],i);
                dw[a[i][j]]=i;
                lf[a[i][j]]=min(lf[a[i][j]],j);
                rg[a[i][j]]=max(rg[a[i][j]],j);
            }
        }
        FOR(i,1,n) {
            FOR(j,1,n) {
                int num=a[i][j];
                L[i][num]=min(L[i][num],j);
                R[i][num]=j;
                U[j][num]=min(U[j][num],i);
                D[j][num]=i;
            }
        }

        FOR(i,1,n) {
            FOR(j,0,9) {
                if (cnt[j]<2 || L[i][j]==n+1) continue;
                int a1=(R[i][j]-L[i][j])*max(i-1,n-i);
                int a2=(dw[j]-i)*max(n-L[i][j],R[i][j]-1);
                int a3=(i-up[j])*max(n-L[i][j],R[i][j]-1);
                ans[j]=max(ans[j],max(a1,max(a2,a3)));
            }
        }
        FOR(i,1,n) {
            FOR(j,0,9) {
                if (cnt[j]<2 || U[i][j]==n+1) continue;
                int a1=(D[i][j]-U[i][j])*max(i-1,n-i);
                int a2=(rg[j]-i)*max(n-U[i][j],D[i][j]-1);
                int a3=(i-lf[j])*max(n-U[i][j],D[i][j]-1);
                ans[j]=max(ans[j],max(a1,max(a2,a3)));
            }
        }
        FOR(i,0,9)
            cout << ans[i] << " ";
        cout << "\n";
    }
}
