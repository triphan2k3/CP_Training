#include <bits/stdc++.h>
#define TASK "1370C"
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
    while (t--) {
        int n;
        cin >> n;
        if (n==1) {
            cout << "FastestFinger\n";
            continue;
        }

        if (n%2) {
            cout << "Ashishgup\n";
            continue;
        }
        if (n%4==0) {
            while (n%2==0) n/=2;
            if (n==1)
                cout << "FastestFinger\n";
            else
                cout << "Ashishgup\n";
            continue;
        }
        n/=2;
        for (int i=3;i*i<=n;i++)
            if (n%i==0) {
                n=1;
                break;
            }
        if (n==1) {
            cout << "Ashishgup\n";
            continue;
        }
        cout << "FastestFinger\n";
    }
}
