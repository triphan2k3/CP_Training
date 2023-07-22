#include <bits/stdc++.h>
#define TASK "516C"
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

const int N=(int)2e5+7;
const int K=18;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
ll a[N],h[N],L[N],R[N],lg[N];
ll l[N][K],r[N][K],s[N][K];
ll m,n;
void prepare() {
    FOR(i,n+1,2*n) {
        a[i]=a[i-n];
        h[i]=h[i-n];
    }
    n*=2;
    FOR(i,1,n)
        a[i]+=a[i-1];
    FOR(i,1,n)
        R[i]=a[i-1]+h[i]*2;
    FOR(i,1,n)
        L[i]=h[i]*2-a[i-1];
}
void RMQ() {
    FOR(i,2,n)
        lg[i]=lg[i/2]+1;
    FOR(i,1,n)
        l[i][0]=L[i];
    FOR(i,1,n)
        r[i][0]=R[i];
    FOR(k,1,lg[n])
        FOR(i,1,n) {
            if (i+(1<<k) > n) break;
            int nxt=i+(1<<(k-1));
            l[i][k]=max(l[i][k-1],l[nxt][k-1]);
            r[i][k]=max(r[i][k-1],r[nxt][k-1]);
            s[i][k]=max(max(s[i][k-1],s[nxt][k-1]),
                        l[i][k-1]+r[nxt][k-1]);
        }
}
ll maxl(int x,int y) {
    int k=lg[y-x+1];
    int nxt=y+1-(1<<k);
    return max(l[x][k],l[nxt][k]);
}
void Query(int x,int y) {
    if (y<x)
        y+=n/2;
    x=x+n/2-1;
    y++;
    swap(x,y);
    int k=lg[y-x+1];
    if (k-1==lg[y-x]) k--;
    int nxt=y+1-(1<<k);
    ll an1=max(s[x][k],s[nxt][k]);
    ll an2=maxl(x,nxt-1)+r[nxt][k];
    cout << max(an1,an2) << "\n";
}
int main() {
    //freopen(TASK".INP","r",stdin);
    //freopen(TASK".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;

    FOR(i,1,n)
        cin >> a[i];
    FOR(i,1,n)
        cin >> h[i];

    prepare();
    RMQ();
    while (m--) {
        int x,y;
        cin >> x >> y;
        Query(x,y);
    }
}
