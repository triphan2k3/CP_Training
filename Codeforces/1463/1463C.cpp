#include <bits/stdc++.h>
#define TASK "1463C"
#define pb push_back
#define ii pair<int,int>
#define iii pair<ii,int>
#define ll long long
#define int long long
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

ii a[N];

bool trong(int a,int x,int y) {
    if (x>y)
        swap(x,y);
    if (a>=x && a<=y)
        return 1;
    return 0;
}
main() {
    freopen(TASK".INP","r",stdin);
    freopen(TASK".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while (t--) {
        int n,ans=0;
        cin >> n;
        FOR(i,1,n)
            cin >>a[i].F >> a[i].S;
        int pret=0,prex=0,netx=0;
        FOR(i,1,n) {
            if (pret+abs(netx-prex) <= a[i].F) {
                prex=netx;
                netx=a[i].S;
                pret=a[i].F;
                if (i==n) {
                    ans++;
                    continue;
                }
                int nett=a[i+1].F;
                if (pret+abs(netx-prex) <= nett)
                    ans++;
                continue;
            }
            if (trong(a[i].S,prex,netx)){

                int timetox=pret + abs(prex-a[i].S);
                if (i==n ) {
                    if (timetox >= a[i].F)
                        ans++;
                    continue;
                }
                if (timetox<=a[i+1].F && timetox>=a[i].F)
                    ans++;
            }
        }

        cout << ans << "\n";

    }
}
