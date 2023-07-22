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

const int N=1e6+7;
const int MOD=1e9+7;
const ll INF=(ll)1e18+7;
int a[N],b[N];
int main() {
    #ifdef TriPhan
        freopen("TEST.INP","r",stdin);
        freopen("TEST.OUT","w",stdout);
    #else
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    #endif
    int t;cin >> t;
    while (t--) {
        int n;
        cin >> n;
        FOR(i,1,n) {
            cin >> a[i];
            b[i]=a[i];
        }
        sort(a+1,a+n+1);
        vector<ii> p;
        FOR(i,1,n) {
            FOR(j,i,n) if (a[i] == b[j]) {
                if (i<j) 
                p.pb({i,j});
                int t = b[j];
                FOD(k,j,i+1)
                    b[k] = b[k-1];
                b[i]=t;
                break;
            }
        }
        cout << p.size() << "\n";
        for(ii x:p) {
            cout << x.F << " " << x.S << " " << x.S-x.F << "\n";
        }
    }
}