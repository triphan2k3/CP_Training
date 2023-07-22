#include <bits/stdc++.h>
#define TASK "1370B"
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
        vector<int> x,y;
        FOR(i,1,2*n) {
            int a;
            cin >> a;
            if (a%2) x.push_back(i);
            else y.push_back(i);
        }
        n--;
        while (n) {
            if (x.size()>= 2) {
                int u=x.back(); x.pop_back();
                int v=x.back(); x.pop_back();
                cout << u << " " << v << "\n";
            }
            else {
                int u=y.back(); y.pop_back();
                int v=y.back(); y.pop_back();
                cout << u << " " << v << "\n";
            }
            n--;
        }
    }
}
