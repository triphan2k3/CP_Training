#include <bits/stdc++.h>
#define TASK "1333C"
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
    int n;
    cin >> n;
    vector<ll> a(n+1,0);
    FOr(i, 0, n)
        cin >> a[i+1];
    FOr(i, 1, n)
        a[i+1]+=a[i];
    map<ll,ll> L;
    //L[0]=1;
    int r=0;
    ll ans=0;
    FOr(l, 0, n) {
        if (r<l) r=l;
        while (r<=n && !L[a[r]])
            L[a[r++]]++;
        ans=ans+(r-l-1);
        L[a[l]]--;
    }
    cout << ans;
}
