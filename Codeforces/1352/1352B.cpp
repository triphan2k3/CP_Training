#include <bits/stdc++.h>
#define TASK "1352B"
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
        int n, k;
        cin >> n >> k;
        if ((n<k) || (n%2 && !(k%2)) || (!(n%2) && k%2 && k*2>n)) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        if (n%2) {
            for (int i=1;i<k;i++,n--)
                cout << "1 ";
            cout << n << "\n";
        }
        else {
            int val=(k%2) ? 2:1;
            for (int i=1;i<k;i++,n-=val)
                cout << val << " ";
            cout << n << "\n";
        }
    }
}
