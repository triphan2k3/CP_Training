#include <bits/stdc++.h>
#define TASK ""
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()
#define ii pair<int,int>
#define iii pair<ii,int>
#define ll long long
#define F first
#define S second
#define sz(x) ((int) (x).size())
#define FOR(i, a, b) for (int i=a; i<=b; i++)
#define FOr(i, a, b) for (int i=a; i<b ; i++)
#define FOD(i, a, b) for (int i=a; i>=b; i--)
#define FOd(i, a, b) for (int i=a; i>b ; i--)
using namespace std;

const int N=1e6+7;
const int MOD=1e9+7;
const ll INF=(ll)1e18+7;
ll a[N];
ll s[N];
int n,k;
int main() {
    #ifdef TriPhan
        freopen("TEST.INP","r",stdin);
        freopen("TEST.OUT","w",stdout);
    #else
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    #endif
    cin >> n >> k;
    FOR(i,2,n) {
        ll u,v;
        cout << "or 1 "<< i << "\n";
        cout.flush();
        cin >> u;
        cout << "and 1 "<< i << "\n";
        cout.flush();
        cin >> v;
        s[i]=u+v;
    }
    ll u,v;
    cout << "or 2 3\n";
    cout.flush();
    cin >> u;

    cout << "and 2 3\n";
    cout.flush();
    cin >> v;
    u+=v;
    a[1]=((s[2]+s[3]+u) >> 1) - u;
    FOR(i,2,n)
        a[i]=s[i]-a[1];
    sort(a+1,a+n+1);
    cout << "finish " << a[k] << "\n";
    cout.flush();
}
