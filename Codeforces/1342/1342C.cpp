#include <bits/stdc++.h>
#define TASK "1342C"
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
    int a, b, q;
    cin >> a >> b >> q;
    vector<int> ck(a*b,0);
    FOr(i, 0, a*b)
        if (i % a % b != i % b % a) ck[i]=1;
    FOr(i, 1, a*b)
        ck[i]+=ck[i-1];
    while (q--) {
        ll L, R;
        cin >> L >> R;
        ll solR = R/(a*b) * ck[a*b-1] + ck[R%(a*b)];
        L--;
        ll solL = L/(a*b) * ck[a*b-1] + ck[L%(a*b)];
        cout << solR-solL << " ";
    }
    cout << "\n";
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
