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

const int N=3e5+1;
const int MOD=1e9+7;
const ll INF=(ll)1e18+7;
int x[N];
int main() {
    #ifdef TriPhan
        freopen("TEST.INP","r",stdin);
        freopen("TEST.OUT","w",stdout);
    #else
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    #endif
    FOR(i,1,N-1)
        x[i]=x[i-1]^i;
    int t; cin >> t;
    while (t--) {
        int a,b,ans;
        cin >> a >> b;
        if (x[a-1]==b) 
            ans = a;
        else if ((b ^ x[a-1]) == a)
            ans = a+2;
        else ans = a+1;
        cout << ans << "\n";
    }
}