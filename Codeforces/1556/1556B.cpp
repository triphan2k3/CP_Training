#include <bits/stdc++.h>
#define TASK ""
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()
#define ii pair<int,int>
#define iii pair<ii,int>
#define ll long long
#define F first
#define S second
#define sz(x) ((int) (x).size())
#define FOR(i, a, b) for (int i=a; i<=b; i++)
#define FOr(i, a, b) for (int i=a; i<b ; i++)
#define FOD(i, a, b) for (int i=a; i>=b; i--)
#define FOd(i, a, b) for (int i=a; i>b ; i--)
using namespace std;

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
    int t;
    cin >> t;
    while (t--) {
        int n,cnt1=0,cnt0=0;
        cin >> n;
        vector<int> v,u;;
        FOR(i,1,n) {
            int a;
            cin >> a;
            a%=2;
            if (a) {
                cnt1++;
                v.push_back(i);
            }
            else {
                cnt0++;
            }
        }
        if (abs(cnt0-cnt1)>1) {
            cout << "-1\n";
            continue;
        }
        ll ans=INF;
        if (cnt1>=cnt0) {
            ll res=0;
            for(int i=1;i<=n;i+=2)
                res+=1LL*abs(v[i/2]-i);
            ans=min(ans,res);
        }
        if (cnt1<=cnt0) {
            ll res=0;
            for(int i=2;i<=n;i+=2)
                res+=1LL*abs(v[(i-1)/2]-i);
            ans=min(ans,res);
        }
        cout << ans << "\n";

    }
}
