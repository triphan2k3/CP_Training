#include <bits/stdc++.h>
#define TASK "1359C"
#define pb push_back
#define ii pair<int,int>
#define iii pair<ii,int>
#define ll long long
#define ld double
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

ll c,h,t;
ld Get(int x) {
    ld tmp=x*(h+c)+h;
    ld d=tmp/(ld)(2*x+1);
    return abs(d-t);
}
int ans(ld a,ld b, ld c, ld d,int x) {
    if (a < b && a < c && a < d) return 2*x+1;
    if (b<c && b < d) return 2*x-1;
    if (c<d) return 2*x+3;
    return 2;
}
int main() {
    freopen(TASK".INP","r",stdin);
    freopen(TASK".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> q;
    while (q--) {
        cin >> h >> c >> t;
        if (2*t-h-c == 0) {
            cout << 2 << "\n";
            continue;
        }
      //  if (t>=h) {
    //        cout << 1 << "\n";
     //   }
        int x=(h-t)/(2*t-c-h);
        ld d1=Get(x);
        ld d2;
        if (x>0) d2=Get(x-1); else d2=d1+1;
        ld d3=Get(x+1);
        ld tmp=h+c;
        ld d4=abs(tmp/2.0 - t);
        int res=ans(d1,d2,d3,d4,x);
        cout << res << "\n";
    }
}

