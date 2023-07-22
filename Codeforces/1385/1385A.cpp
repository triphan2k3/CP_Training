#include <bits/stdc++.h>
#define TASK "1385A"
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
    int t; cin >> t;
    while (t--) {
        int x, y, z, ni=0;
        cin >> x >> y >> z;
        int mi=min(x,min(y,z));
        int ma=max(x,max(y,z));
        if (x==mi) ni++;
        if (y==mi) ni++;
        if (z==mi) ni++;
        if (ni==2) {
            cout << "NO\n";
            continue;
        }
        if (x!=y && y!=z && x!=z) {
            cout << "NO\n";
            continue;
        }
        int a,b,c,kt=0;
        if (x==mi) {
            b=ma;
            a=mi;
        } else
        {
            b=mi;
            a=ma;
        }

        c=mi;
        cout << "YES\n" << a << " " << b << " " << c << "\n";
    }
}
