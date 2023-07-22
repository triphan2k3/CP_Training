#include <bits/stdc++.h>
#define TASK "1348D"
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
        --n;
        int sl = 1;
        vector<int> ans;
        while (n >= 4*sl) {
            ans.push_back(sl);
            sl *= 2;
            n -= sl;
        }
        if (n<=2*sl)
            ans.push_back(n-sl);
        else {
            n -= 2*sl;
            int rem = n/2;
            int ram = n%2;
            ans.push_back(rem);
            ans.push_back(ram);
        }
        cout << ans.size() << "\n";
        for(int i:ans)
            cout << i << " ";
        cout << "\n";
    }
}
