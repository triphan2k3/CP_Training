#include <bits/stdc++.h>
#define TASK "1167E"
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
vector<int> a[N];
int b[N];
int n,x;
int main() {
    //freopen(TASK".INP","r",stdin);
    //freopen(TASK".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> x;
    FOR(i,1,n) {
        int y;
        cin >> y;
        b[y]=1;
        a[y].push_back(i);
    }

    int r = n+1;
    int last = x;
    for (int i=x;i>=1;i--) {
        if (a[i].size()==0) {
            last = i;
            continue;
        }
        if (a[i].back() > r)
            break;
        last = i;
        r = a[i][0];
    }
    a[x+1].push_back(n+1);
    for (int i=x;i>=1;i--)
        if (a[i].empty())
            a[i].push_back(a[i+1][0]);
    int l = 0;
    ll ans = 0;
    last--;
    for (int i=1;i<=x;i++) {
        last=max(last,i);
        if (b[i]==0) {
            ans += x-last+1;
            continue;
        }
        ans += x-last+1;
        if (a[i][0] < l)
            break;
        while (a[i].back() > a[last+1][0] && last <=x)
            last++;
        l = a[i].back();
    }
    cout << ans;
}
