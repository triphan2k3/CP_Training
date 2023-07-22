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
    freopen(TASK".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >>n;
    FOR(i,1,n) {
        a[i].resize(m+1);
        b[i].resize(m+1);
    }
    cin >> m;
    FOR(i,1,n)
        FOR(i,1,m) {
            cin >> a[i][j];
            b[i][j]=(i-1)*m+j;
        }
    FOR(j,1,m) {
        FOR(i,1,n)
            cost[i]=0;
        map<ii,int> mp;
        FOR(i,1,n)
            if (a[i][j] % m == j ) {
                int line=(a[i][j]-1)/m + 1;
            }

    }


}
