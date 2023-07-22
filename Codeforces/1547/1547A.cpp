#include <bits/stdc++.h>
#define TASK ""
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
        int xa,ya,xb,yb,xf,yf;
        cin >> xa >> ya >> xb >> yb >> xf >> yf;
        if (xa != xb && ya !=yb) {
            cout << abs(xa-xb)+abs(ya-yb) << "\n";
            continue;
        }
        if (ya==yb) {
            swap(xa,ya);
            swap(xb,yb);
            swap(xf,yf);
        }
        if (xf!=xa) {
            cout <<  abs(xa-xb)+abs(ya-yb) << "\n";
            continue;
        }
        if (ya==yb) {
            cout << "0\n";
            continue;
        }
        if (yf >= min(ya,yb) && yf<=max(ya,yb)) {
            cout << abs(ya-yb)+2 << "\n";
            continue;
        }
        cout << abs(ya-yb) <<"\n";
    }

}
