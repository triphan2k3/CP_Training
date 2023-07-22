#include <bits/stdc++.h>
#define TASK "280B"
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
int n,ans;
vector<int> a;

void solve() {
    vector<int> st;
    FOR(i,0,n-1) {
        while (st.size() && st.back() < a[i]) st.pop_back();
        if (st.size())
            ans=max(ans,a[i]^st.back());
        st.push_back(a[i]);
    }
}
int main() {
    //freopen(TASK".INP","r",stdin);
    //freopen(TASK".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    a.resize(n);
    FOR(i,0,n-1)
        cin >> a[i];
    solve();
    reverse(a.begin(),a.end());
    solve();
    cout << ans;
}
