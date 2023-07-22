#include <bits/stdc++.h>
#define TASK "1330E"
#define pb push_back
#define ii pair<int,int>
#define ll long long
#define F first
#define S second
#define FOR(i, a, b) for (int i=a; i<=b; i++)
#define FOr(i, a, b) for (int i=a; i<b ; i++)
#define FOD(i, a, b) for (int i=a; i>=b; i--)
#define FOd(i, a, b) for (int i=a; i>b ; i--)

using namespace std;
const int N=2194304;
int t, h, g, a[N], Get[N], ok[N];
ll ans;
vector<ii> dnc(int i) {

    vector<ii> q;
    if (i >= 1<<h) return q;


    vector<ii> ql = dnc(i*2);
    vector<ii> qr = dnc(i*2+1);
    // merge
    int il=0, ir=0;
    q.push_back({a[i],i});
    while (il < ql.size() || ir < qr.size()) {
        if (il==ql.size()) {
            q.push_back(qr[ir++]);
            continue;
        }
        if (ir==qr.size()) {
            q.push_back(ql[il++]);
            continue;
        }
        if (ql[il].F > qr[ir].F)
            q.push_back(ql[il++]);
        else
            q.push_back(qr[ir++]);
    }
    if (i >= 1<<g) return q;
    int before = max(Get[i*2],Get[i*2 + 1]);
    while (q.back().F < before) q.pop_back();

    ii val = q.back();
    q.pop_back();
    ok[val.S] = 1;
    ans += 1LL*val.F;
    Get[i]=val.F;
    return q;
}
int main()
{
    freopen(TASK".INP","r",stdin);
    freopen(TASK".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> h >> g;

        for (int i=1; i<= 1<<(h+1); i++)
            a[i] = Get[i] = ok[i] = 0;
        for (int i=1; i< 1<<h; i++)
            cin >> a[i];
        ans=0;
        dnc(1);
        cout << ans << "\n";
        for (int i= (1<<h) - 1; i>0; i--)
            if (!ok[i]) cout << i << " ";
        cout << "\n";

    }
}
