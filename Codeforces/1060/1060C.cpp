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

const int N=(int)4e6+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
int f[N];
int a[2002],b[2002];
int n,m,s;
int main() {
    //freopen(TASK".INP","r",stdin);
    //freopen(TASK".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    FOR(i,1,n) {
        cin >> a[i];
        a[i]+=a[i-1];
    }

    FOR(i,1,m) {
        cin >> b[i];
        b[i]+=b[i-1];
    }
    cin >> s;
    FOR(i,1,m)
        FOR(j,i,m) {
            int val=b[j]-b[i-1];
            f[val]=max(f[val],j-i+1);
        }
    FOR(i,1,4000000)
        f[i]=max(f[i-1],f[i]);

    int ans = 0;
    FOR(i,1,n)
        FOR(j,i,n) {
            int sum=a[j]-a[i-1];
            int maxsumb=min(4000000,s/sum);
            ans=max(ans,(j-i+1)*f[maxsumb]);
        }
    cout << ans;

}
