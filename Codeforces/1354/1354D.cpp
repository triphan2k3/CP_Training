#include <bits/stdc++.h>
#define TASK "1354D"
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
int a[N],b[N],l[N],r[N];
int n,q;
bool check(int v) {
    int eq=l[v];
    int be=r[v+1];

    for (int i=1;i<=q;i++)
        if (b[i] > 0) {
            if (b[i]>v) be++;
            else eq++;
        }
        else {
            if (eq < -b[i]) be--;
            else eq--;
        }
    return eq;
}

int main() {
    freopen(TASK".INP","r",stdin);
    freopen(TASK".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q;
    for (int i=1; i<=n;i++) {
        int k;
        cin >> k;
        a[k]++;
    }
    for (int i=1;i<=n;i++)
        l[i]=l[i-1]+a[i];
    for (int i=n;i>=1;i--)
        r[i]=r[i+1]+a[i];

    int num=n;
    for (int i=1;i<=q;i++) {
        cin >> b[i];
        if (b[i] < 0) num--;
        else num++;
    }
    if (num==0) {
        cout << 0;
        return 0;
    }

    int l=1,r=n;
    int ans=0;
    while (l<=r) {
        int m=(l+r) >> 1;
        if (check(m)) {
            r=m-1;
            ans=m;
        } else l=m+1;

    }
    cout << ans << "\n";
}
