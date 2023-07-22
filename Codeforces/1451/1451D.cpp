#include <bits/stdc++.h>
#define TASK "1451D"
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
main() {
    //freopen(TASK".INP","r",stdin);
    //freopen(TASK".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int d,k;
        cin >> d >> k;
        double r=1.0*d/k;
        int step=d/k;
        int midx=r/sqrt(2);
        int midy=sqrt(1LL*r*r-1LL*midx*midx);
        if (midx != midy)
                cout << "Ashish\n";
            else
                cout << "Utkarsh\n";

        continue;

        if (midx+1 > r) {
            cout << "Utkarsh\n";
            continue;
        }
    }
}
