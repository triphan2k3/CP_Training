#include <bits/stdc++.h>
#define TASK ""
#define pb push_back
#define F first
#define S second
#define int long long
#define FOR(i, a, b) for (int i=a; i<=b; i++)
#define FOr(i, a, b) for (int i=a; i<b ; i++)
#define FOD(i, a, b) for (int i=a; i>=b; i--)
#define FOd(i, a, b) for (int i=a; i>b ; i--)
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef vector<int> vi;

const int N=1e6+7;
const int MOD=998244353;
const ll INF=(ll)1e18+7;
ll a[N],lt[N],inv[N];
int Pow(int x,int y) {
    if (y==1) return x;
    int tmp = Pow(x,y/2);
    tmp = 1LL*tmp*tmp%MOD;
    if (y&1)
        tmp = 1LL*tmp*x % MOD;
    return tmp;
}

void setup() {
    int n = 200000;
    lt[0]=1;
    FOR(i,1,n)
        lt[i]=1LL*lt[i-1]*i % MOD;
    inv[n] = Pow(lt[n],MOD-2);
    FOD(i,n-1,0)
        inv[i]=1LL*inv[i+1]*(i+1) % MOD;
}
int A(int x, int y) {// xAy
    if (x>y) return 0;
    return 1LL*lt[y]*inv[y-x]%MOD;
}
main() {
    #ifdef TriPhan
        freopen("TEST.INP","r",stdin);
        freopen("TEST.OUT","w",stdout);
    #else
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    #endif
    setup();
    int t; cin >> t;
    while (t--) {
        int n;
        cin >> n;
        FOR(i,1,n) cin >> a[i];
        sort(a+1,a+n+1);
        int ma = a[n];
        int cnt=0,cnt1=0;
        FOR(i,1,n) {
            if (a[i]==ma) cnt++;
            if (a[i]==ma-1) cnt1++;
        }
        
        if (cnt > 1) {
            cout << lt[n] << "\n";
            continue;
        }
        if (cnt1==0) {
            cout << "0\n";
            continue;
        }
        int ans = lt[n-1];
        int y = n - cnt1-1;
        FOR(x,2,n-1) {
            int szr = n-x;
            int szl = x-1;
            int tmp = 1LL*lt[szl]*(A(szr,n-1)-A(szr,y) + MOD) % MOD;
            ans = (ans+tmp) % MOD;
        }
        cout << ans << "\n";
    }
}