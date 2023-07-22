#include <bits/stdc++.h>
#define TASK ""
#define pb push_back
#define F first
#define S second
#define FOR(i, a, b) for (int i=a; i<=b; i++)
#define FOr(i, a, b) for (int i=a; i<b ; i++)
#define FOD(i, a, b) for (int i=a; i>=b; i--)
#define FOd(i, a, b) for (int i=a; i>b ; i--)
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef vector<int> vi;

const int N=300+7;
const int MOD=1e9+7;
const ll INF=(ll)1e18+7;
int n,m;
int valid[N][N],ind[N*N];
ii a[N*N];

bool cmp(ii a,ii b) {
    return a.F != b.F ? a.F < b.F : a.S > b.S;
}

int A(int i,int j) {
    return a[(i-1)*m+j].F;
}
int main() {
    #ifdef TriPhann
        freopen("TEST.INP","r",stdin);
        freopen("TEST.OUT","w",stdout);
    #else
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    #endif
    int t; cin >> t;
    while (t--) {
        cin >> n >> m;
        FOR(i,1,m*n) {
            cin >> a[i].F;
            a[i].S=i;
        }
        sort(a+1,a+m*n+1);



        FOR(i,1,m*n)
            ind[a[i].S] = i;
        FOR(i,1,n)
            FOR(j,1,m)
                valid[i][j]=0;//a[id(i,j)].S;
        
        int ans = 0;
        FOR(i,1,m*n) {
            int id = ind[i];
            int col = (id-1) % m + 1;
            int row = (id-1)/m + 1;
            FOR(j,1,col)
                if (A(row,j)!=A(row,col))
                    ans += valid[row][j];
            valid[row][col] = 1;
        }
        cout << ans << "\n";
    }
}