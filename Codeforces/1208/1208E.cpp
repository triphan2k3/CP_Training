#include <bits/stdc++.h>
#define TASK "1208E"
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
int n,li,w;
ll pre[N],ans[N],a[N];
void solve() {
    cin >> li;
    int nw=min(w,li*2);
    int l=1;
    ll ma=0;
    FOR(i,1,li) {
        cin >> a[i];
        ma=max(ma,a[i]);
    }
    if (nw!=w) {
        pre[li+1]+=ma;
        pre[w-li+1]-=ma;
    }
    deque<int> q;
    int L0=nw-li;
    int R0=nw-L0+1;
    FOR(i,1,nw) {
        l=max(1,li-nw+i);
        while (q.size() && q.front() < l)
            q.pop_front();
        if (i<=li) {
            while (q.size() && a[q.back()] <= a[i])
                q.pop_back();
            q.push_back(i);
        }
        int it;
        ll val=a[q.front()];
        if (i<=L0 || i>=R0)
            val=max(0LL,val);
        if (nw==w) it=i;
        else
            it=i<=li ? i:w-li+i-li;
        ans[it]+=val;
    }

}
int main() {
    freopen(TASK".INP","r",stdin);
    freopen(TASK".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> w;
    FOR(i,1,n)
        solve();
    FOR(i,1,w) {
        pre[i]+=pre[i-1];
        ans[i]+=pre[i];
    }
    FOR(i,1,w)
        cout << ans[i] << " ";
}
