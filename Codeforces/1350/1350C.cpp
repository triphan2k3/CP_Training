#include <bits/stdc++.h>
#define TASK "1350C"
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
    freopen(TASK".INP","r",stdin);
    freopen(TASK".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    FOr(i, 0, n)
        cin >> a[i];
    vector<ii> p;
    int x=a[0];
    int y=a[1];
    if (x<y) swap(x,y);
    for (int i=2;i*i<=x;i++)
        if (x%i==0 || y%i==0) {
            int cnt=0;
            while (x%i==0 || y%i==0) {
                if (x%i==0) x/=i;
                if (y%i==0) y/=i;
                cnt++;
            }
            p.push_back({i,cnt});
        }
    if (x>1) p.push_back({x,1});
    if (y!=x && y>1) p.push_back({y,1});
    ll ans=1;
    FOr(i, 0, p.size()) {
        int tmp=1;
        int ma=0;
        FOR(j,1,p[i].S) {
            tmp*=p[i].F;
            int cnt=0;
            FOr(k,0,n)
                if (a[k]%tmp==0) cnt++;
            if (cnt>=n-1) ma=j;
        }
        FOR(j,1,ma)
            ans=1LL*ans*p[i].F;
    }
    cout << ans;
}
