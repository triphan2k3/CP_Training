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
    freopen(TASK".INP","r",stdin);
    //freopen(TASK".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        ll n,a,b;
        cin >> n >> a >> b;
        if (b==1 || n==1) {
            cout << "Yes\n";
            continue;
        }
        if (n%b == 1) {
            cout << "Yes\n";
            continue;
        }
        if (a==1) {
            cout << "No\n";
            continue;
        }
        ll A=a;
        int ok=0;
        while (A<=n) {

            if (A==n) {
                ok=1;
                break;
            }

            if ((n-A)%b == 0) {
                ok=1;
                break;
            }
            A*=a;


        }
        if (ok)
            cout << "Yes\n";
        else
            cout << "No\n";

    }

}
