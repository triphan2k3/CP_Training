#include <bits/stdc++.h>
#define TASK "1364B"
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
int a[N],b[N];
int main() {
    freopen(TASK".INP","r",stdin);
    freopen(TASK".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i=1;i<=n;i++) {
            b[i]=0;
            cin >> a[i];
        }
        int ans=n;
        for (int i=3;i<=n;i++) {
            if (a[i]>a[i-1] && a[i-1]>a[i-2]) b[i-1]=1;
            if (a[i]<a[i-1] && a[i-1]<a[i-2]) b[i-1]=1;
            if (b[i-1]) ans--;
        }
        cout << ans << "\n";
        for (int i=1;i<=n;i++)
            if (b[i]==0) cout << a[i] << " ";
        cout << "\n";
    }
}
