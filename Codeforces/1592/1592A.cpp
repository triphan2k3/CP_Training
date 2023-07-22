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
        int n,h;
        cin >> n >> h;
        vector<int> a(n);
        FOr(i,0,n)
            cin >> a[i];
        sort(a.begin(),a.end());
        reverse(a.begin(),a.end());
        int x = a[0],y=a[1];
        int ans = h/(x+y);
        h-= ans*(x+y);
        ans = ans*2 + (h>0) + (h>x);
        cout << ans << "\n";
    }
}