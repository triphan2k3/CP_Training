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
        int n,x;
        cin >> n >> x;
        vector<int> a(n+1),b(n+1);
        FOR(i,1,n) {
            cin >>a[i];
            b[i] = a[i];
        }
        sort(a.begin()+1,a.begin()+n+1);
        int l = x + 1;
        int r = n - x;
        if (l<=r) {
            cout << "YES\n";
            continue;
        }
        int flag = 0 ;
        FOR(i,r+1,l-1)
            flag |= (a[i]!=b[i]);
        if (flag) cout << "NO\n";
        else cout << "YES\n";
    }
}