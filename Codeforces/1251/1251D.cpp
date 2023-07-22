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
ll s;
int n,num;
int avail[N];
ii a[N];

int check(int x) {
    priority_queue<ii,vector<ii>,less<ii>> pq;
    FOR(i,1,n) {
        if (a[i].S >= x)
            pq.push({a[i].F,i});
        avail[i]=0;
    }
    if (pq.size()< num)
        return 0;
    ll cost=0;

    FOR(i,1,num) {
        int id=pq.top().S;
        pq.pop();
        cost+=max(x,a[id].F);
        avail[id]=1;
    }
    FOR(i,1,n)
        if (!avail[i])
            cost+=a[i].F;
    return cost<=s;

}
int main() {
    //freopen(TASK".INP","r",stdin);
    //freopen(TASK".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> s;
        num=n/2+1;
        int l=MOD,r=0;
        FOR(i,1,n) {
            cin >> a[i].F >> a[i].S;
            r=max(r,a[i].S);
            l=min(l,a[i].F);
        }
        int ans=l;
        while (l<=r) {
            int m=(l+r)>>1;
            if (check(m)) {
                ans=m;
                l=m+1;
            }
            else
                r=m-1;
        }
        cout << ans << '\n';
    }
}
