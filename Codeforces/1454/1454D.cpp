#include <bits/stdc++.h>
#define TASK "1454D"
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
        ll n;
        cin >> n;
        map<ll,int> mp;
        ll tmp=n;
        for (ll i=2;i*i<=n;i++)
            if (n%i==0)
                while (n%i==0) {
                    mp[i]++;
                    n/=i;
                }
        if (n) mp[n]++;
        n=tmp;
        int a=1;
        ll res=n;
        for (auto x:mp)
            if (x.S > a) {
                a=x.S;
                res=x.F;
            }
        cout << a << "\n";
        for (int i=1;i<a;i++) {
            cout << res << " ";
            n/=res;
        }
        cout << n << "\n";




    }
}
