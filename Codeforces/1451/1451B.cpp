#include <bits/stdc++.h>
#define TASK "1451B"
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
    //freopen(TASK".INP","w",stdin);
    //freopen(TASK".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n,q;
        cin >> n >> q;
        string s;
        cin >> s;
        s="."+s;
        int l0=n+1,l1=n+1,r0=0,r1=0;
        FOR(i,1,n)
            if (s[i]=='0') {
                l0=i;
                break;
        }
        FOR(i,1,n)
            if (s[i]=='1') {
                l1=i;
                break;
        }
        FOD(i,n,1)
        if (s[i]=='0') {
            r0=i;
            break;
        }
        FOD(i,n,1)
        if (s[i]=='1') {
            r1=i;
            break;
        }

        while (q--) {
            int l,r;
            cin >> l >> r;
            int kt=0;
            if (s[l]=='0' && l0 < l) kt=1;
            if (s[l]=='1' && l1 < l) kt=1;
            if (s[r]=='0' && r0 > r) kt=1;
            if (s[r]=='1' && r1 > r) kt=1;
            if (kt)
                cout << "YES\n";
            else
                cout << "NO\n";

        }
    }
}
