#include <bits/stdc++.h>
#define TASK "1037F"
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
ll a[N];
int L[N],R[N];
int n,k;
ll calc(int l,int r) {
    ll n=r-l+1;
    if (n<k) return 0;
    ll x=(n-1)/(k-1);
    return (n*x-(k-1LL)*x*(x+1LL)/2LL) % MOD;
}
int main() {
    freopen(TASK".INP","r",stdin);
    freopen(TASK".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    FOR(i,1,n)
        cin >> a[i];

    deque<int> q;
    a[0]=a[n+1]=MOD;
    q.push_back(0);
    FOR(i,1,n) {
        while (a[q.back()] < a[i])
            q.pop_back();
        L[i]=q.back()+1;
        q.push_back(i);
    }
    q={n+1};
    FOD(i,n,1) {
        while (a[q.back()] <= a[i])
            q.pop_back();
        R[i]=q.back()-1;
        q.push_back(i);
    }
    ll ans=0;
    FOR(i,1,n) {
        ll num=calc(L[i],R[i])-calc(L[i],i-1)-calc(i+1,R[i]);
        ans+=a[i]*num;
        ans%=MOD;
    }
    cout << ans;
}
