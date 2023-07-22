#include <bits/stdc++.h>
#define TASK ""
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
int n;

int main() {
    //freopen(TASK".INP","r",stdin);
    //freopen(TASK".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    FOR(i,1,n) {
        cin >> a[i];
        --a[i];
    }
    ll S=0;//min(a[1],a[2])
    ll ans=a[1];
    FOR(i,2,n) {
        S=S*min(min(a[i-2],a[i-1]),a[i]) + min(a[i-1],a[i]);
        S%=MOD;
        ans+=a[i]+S*min(a[i],a[i-1]);
        ans%=MOD;
    }
    cout << ans;
}
