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
int m,n;
int a[N];
int main() {
    //freopen(TASK".INP","r",stdin);
    //freopen(TASK".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    FOR(i,1,m) {
        int u,v;
        cin>> u>> v;
        a[u]=v;
    }
    int ans=-1;
    FOR(i,1,100) {
        int kt=1;
        FOR(j,1,100)
            if (a[j] && a[j]!=(j-1)/i+1)
                kt=0;
        if (!kt) continue;
        if (ans==-1) ans=(n-1)/i+1;
        if (ans!=(n-1)/i+1) {
            cout << "-1";
            return 0;
        }
    }
    cout << ans;
}
