#include <bits/stdc++.h>
#define TASK "1350D"
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

int solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    FOr(i,0,n)
        cin >> a[i];

    FOr(i,0,n) {
        if (a[i]==k) break;
        if (i==n-1) return 0;
    }
    if (n==1) return 1;
    FOR(i,0,n-2)
        if (a[i]>=k && a[i+1]>=k)
            return 1;
    FOR(i,1,n-2)
        if (a[i-1]>=k && a[i+1]>=k)
            return 1;
    return 0;
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
        if (solve())
            cout << "yes\n";
        else
            cout << "no\n";

}
