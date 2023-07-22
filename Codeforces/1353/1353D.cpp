#include <bits/stdc++.h>
#define TASK "1353D"
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
bool cmp(ii a,ii b) {
    return a.F==b.F ? a.S<b.S : a.F>b.F;
}
int main() {
    //freopen(TASK".INP","r",stdin);
    //freopen(TASK".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n+1);
        vector<ii> b,c;
        c.push_back({n,1});
        while (c.size()) {
            b.push_back(c.back());
            int l=c.back().S;
            int r=c.back().S+c.back().F-1;
            c.pop_back();
            int m=(l+r)/2;
            if (l<=m-1) c.push_back({m-l,l});
            if (r>=m+1) c.push_back({r-m,m+1});
        }
        sort(b.begin(),b.end(),cmp);
        FOr(i,0,n) {
            int l=b[i].S;
            int r=b[i].S+b[i].F-1;
            a[(r+l)>>1]=i+1;
        }
        FOR(i,1,n)
            cout << a[i] << " ";
        cout << "\n";
    }
}
