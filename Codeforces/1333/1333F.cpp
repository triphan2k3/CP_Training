#include <bits/stdc++.h>
#define TASK "1333F"
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
    int n;
    cin >> n;
    vector<int> p(n+1,0);
    for (int i=2;i*i<=n;i++)
        if (p[i]==0) {
        p[i]=i;
        for (int j=i*i;j<=n;j+=i)
            if (!p[j]) p[j]=i;
    }
    for (int i=1;i<=n;i++)
        if (!p[i]) p[i]=i;
    vector<int> ans;
    for (int i=1;i<=n;i++)
        ans.push_back(i/p[i]);
    sort(ans.begin(),ans.end());
    for (int i=1;i<n;i++)
        cout<<ans[i]<<" ";

}
