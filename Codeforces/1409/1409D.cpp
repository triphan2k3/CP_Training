#include <bits/stdc++.h>
#define TASK "1409D"
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
    //freopen(TASK".INP","r",stdin);
    //freopen(TASK".OUT","w",stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        ll n,s;
        cin >> n >> s;
        vector<int> a;

        ll tmp=n;
        while (tmp) {
            a.pb(tmp%10);
            tmp/=10;
        }
        a.push_back(0);
        reverse(a.begin(),a.end());

        int sum=0;
        FOR(i,0,a.size()-1)
            sum+=a[i];
        if (sum<=s) {
            cout << 0 << "\n";
            continue;
        }
        ll m=1; ll ans=0;
        for (int i=a.size()-1;i>0;i--) {
            if (a[i]==10) {
                sum-=9;
                m*=10LL;
                a[i-1]++;
                continue;
            }
            if (sum<=s) break;
            ans+=1LL*(10-a[i])*m;
            a[i-1]++;
            sum=sum+1-a[i];
            m*=10LL;
        }
        cout << ans << "\n";
    }
}
