#include <bits/stdc++.h>
#define TASK "1352G"
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

void solve() {
    int n;
    cin >> n;
    if (n<4) {
        cout << "-1\n";
        return;
    }
    vector<int> ans;
    if (n&1)
        ans.push_back(n--);
    int m=n;
    FOR(i, 1, n/4) {
        ans.push_back(m-1);
        ans.push_back(m-3);
        ans.push_back(m);
        ans.push_back(m-2);
        m-=4;
    }
    if (m==2) {
        ans.pop_back();
        ans.push_back(2);
        ans.push_back(4);
        ans.push_back(1);
    }
    for (int i:ans)
        cout << i << " ";
    cout << "\n";
    return;
}
int main() {
    freopen(TASK".INP","r",stdin);
    freopen(TASK".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();

}
