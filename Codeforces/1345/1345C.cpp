#include <bits/stdc++.h>
#define TASK "1345C"
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
    while(t--) {
        int n, k, ans=1;
        cin >> n;
        vector<int> ok(2*n,0);
        FOr(k,0,n) {
            int v,gt;
            cin >> v;
            v+=k;
            if (v<0)
                gt=(n - ((-v)%n)) % n;
            else
                gt=v%n;
            if (ok[gt])
                ans=0;
            ok[gt]++;
        }
        if (ans)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
