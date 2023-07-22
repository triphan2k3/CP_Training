#include <bits/stdc++.h>
#define TASK ""
#define pb push_back
#define F first
#define S second
#define FOR(i, a, b) for (int i=a; i<=b; i++)
#define FOr(i, a, b) for (int i=a; i<b ; i++)
#define FOD(i, a, b) for (int i=a; i>=b; i--)
#define FOd(i, a, b) for (int i=a; i>b ; i--)
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef vector<int> vi;

const int N=1e6+7;
const int MOD=1e9+7;
const ll INF=(ll)1e18+7;

int main() {
    #ifdef TriPhan
        freopen("TEST.INP","r",stdin);
        freopen("TEST.OUT","w",stdout);
    #else
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    #endif
    int t; cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> uoc;
        FOR(i,1,n) 
            cin >> a[i-1];
        sort(a.begin(),a.end());
        int half = n/2;
        int flag = 1;
        FOR(i,0,half)
            if (a[i]==a[i+half-1]) {
                cout << "-1\n";
                flag = 0;
                break;
            }
        if (flag==0) continue;
        FOR(i,0,n-1)
            FOR(j,i+1,n-1)
                if (a[i]!=a[j]) {
                    int k = a[j]-a[i];
                    uoc.pb(k);
                    for(int i=2;i*i<=k;i++)
                        if (k%i==0) {
                            uoc.pb(i);
                            uoc.pb(k/i);
                        }
                }
        sort(uoc.begin(),uoc.end());
        uoc.resize(distance(uoc.begin(),unique(uoc.begin(),uoc.end())));
        int ans = 1;
        for (int u:uoc) {
            //cout << u << " ";
            FOR(i,0,n-1) {
                int cnt = 0;
                FOR(j,0,n-1)
                    cnt += (abs(a[i]-a[j])%u==0);
                if (cnt>=half)
                    ans = max(ans,u); 
            }
        }
        cout << ans << "\n";
    }
}