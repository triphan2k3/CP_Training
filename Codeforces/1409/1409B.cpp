#include <bits/stdc++.h>
#define TASK "1409B"
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
    //freopen(TASK".INP","r",stdin);
    //freopen(TASK".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        ll a,b,x,y,n,t1,t2,m,res;
        cin >> a >> b >> x >> y >> n;
        if (n>=a-x+b-y) {
            cout << x*y << "\n";
            continue;
        }
        t1=a, t2=b,m=n;
        t1-=min(n,a-x);
        m-=min(n,a-x);
        t2-=m;

        res=t1*t2;
        t1=a; t2=b; m=n;
        t2-=min(n,b-y);
        m-=min(n,b-y);
        t1-=m;
        res=min(res,t1*t2);
        cout << res << "\n";
    }
}
