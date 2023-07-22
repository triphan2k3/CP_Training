#include <bits/stdc++.h>
#define TASK "1342D"
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
    int n, k;
    cin >> n >> k;
    vector<int> a(k+1,0);
    FOR(i, 1, n) {
        int x;
        cin >> x;
        a[x]++;
    }
    vector<int> c(k+2,0);
    vector<int> ans[n+1];
    FOR(i, 1, k)
        cin >> c[i];
    int allar = 1, nowar = 1;
    FOD(i, k, 1) {
        nowar = c[i]!=c[i+1] ? 1:nowar;
        FOR(j, 1, a[i])
            if (ans[nowar].size() < c[i])
                ans[nowar].push_back(i);
            else
                ans[++nowar].push_back(i);
        allar=max(allar,nowar);
    }
    cout << allar << "\n";
    FOR(i, 1, allar) {
        cout << ans[i].size() << " ";
        for(int x:ans[i])
            cout << x << " ";
        cout << "\n";
    }
}
