#include <bits/stdc++.h>
#define TASK "1380C"
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
int a[N];
int main() {
    //freopen(TASK".INP","r",stdin);
    //freopen(TASK".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while (t--) {
        int n,x;
        cin >> n >> x;
        FOR(i,1,n)
            cin >> a[i];
        sort(a+1,a+n+1);
        reverse(a+1,a+n+1);

        int last=0,ans=0;
        for (int i=1;i<=n;i++)
            if (1LL*a[i]*(i-last)>=1LL*x) {
                ans++;
                last=i;
            }
        cout << ans << "\n";
    }
}
