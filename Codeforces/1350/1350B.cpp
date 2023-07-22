#include <bits/stdc++.h>
#define TASK "1350B"
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

const int N=(int)1e5+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
vector<int> uoc[N];

int main() {
    freopen(TASK".INP","r",stdin);
    freopen(TASK".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for (int i=1;i<=100000;i++)
        for (int j=2*i;j<=100000;j+=i)
            uoc[j].push_back(i);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> dp(n+1,1),a(n+1);
        for (int i=1;i<=n;i++) {
            dp[i]=1;
            cin >> a[i];
        }

        for (int i=2;i<=n;i++)
            for (int j:uoc[i])
                if (a[i]>a[j])
                    dp[i]=max(dp[i],dp[j]+1);
        int ans=1;
        for (int i=2;i<=n;i++)
            ans=max(ans,dp[i]);

        cout<<ans<<"\n";
    }
}

