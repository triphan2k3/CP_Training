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
int ans[N],a[N];
vector<int> e[N];
int n,k;
int main() {
    //freopen(TASK".INP","r",stdin);
    //freopen(TASK".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin>> n >> k;
        FOR(i,1,n)
            cin >> a[i];
        FOR(i,1,n) ans[i]=0;
        FOR(i,1,n) e[a[i]].push_back(i);

        vector<int> r;
        FOR(i,1,n) {
            int sz=e[i].size();
            if (sz>=k) sz=k;

            for (int j=0;j<sz;j++)
                r.push_back(e[i][j]);
        }
        while (r.size() % k)
            r.pop_back();
        for (int i=0;i<r.size();i++) {
            int id=r[i];
            ans[id]=i%k + 1;
        }
        FOR(i,1,n)
            cout << ans[i] << " ";
        cout << "\n";
        FOR(i,1,n)
            e[i].clear();

    }
}
