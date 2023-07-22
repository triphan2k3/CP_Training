#include <bits/stdc++.h>
#define TASK "1374E1"
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
int n,k,na,nb,nc;
int a[N],b[N],c[N];
int main() {
    freopen(TASK".INP","r",stdin);
    freopen(TASK".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,k;
    cin >> n >> k;
    FOR(i,1,n) {
        int x,y,z;
        cin >> x >> y >> z;
        if (y+z==2)
            c[++nc]=x;
        else if (z)
            b[++nb]=x;
        else if (y)
            a[++na]=x;
    }
    if (min(na,nb)+nc<k) {
        cout << -1;
        return 0;
    }
    sort(a+1,a+na+1); reverse(a+1,a+na+1);
    sort(b+1,b+nb+1); reverse(b+1,b+nb+1);
    sort(c+1,c+nc+1); reverse(c+1,c+nc+1);
    int ans=0;
    int v1,v2;
    FOR(i,1,k) {
        if (na>0 && nb>0)
            v1=a[na] + b[nb];
        else
            v1=MOD;
        if (nc)
            v2=c[nc];
        else
            v2=MOD;

        ans+=min(v1,v2);
        if (v1<v2)
            na--,nb--;
        else
            nc--;
    }
    cout << ans;
}
