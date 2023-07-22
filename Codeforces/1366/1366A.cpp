#include <bits/stdc++.h>
#define TASK "1366A"
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
int main() {
    freopen(TASK".INP","r",stdin);
    freopen(TASK".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int a,b;
        cin >> a >> b;
        if (a<b) swap(a,b); // a > b
        if (2*b-a <= 0) {
            cout << b << "\n";
            continue;
        }
        int x=a-b;
        a-=2*x;
        b-=x;
        a=a/3;
        int ans=a*2+x;
        if (b%3 == 2) ans++;
        cout << ans << "\n";
    }
}
