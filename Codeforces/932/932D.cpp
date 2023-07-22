#include <bits/stdc++.h>
#define TASK "932D"
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
ll f[N][22],s[N][22];
ll a[N];
ll last;
int cnt=1;
void add(ll p, ll q) {
    p^=last;
    q^=last;
    a[++cnt]=q;
    if (a[cnt] <= a[p]) {
        f[cnt][0]=p;
    } else {
        for (int i=20;i>=0;i--)
            if (f[p][i]!=0 && a[f[p][i]] < q)
                p=f[p][i];
        f[cnt][0]=f[p][0];
    }

    s[cnt][0]=a[f[cnt][0]];
    FOR(i,1,20) {
            f[cnt][i]=f[f[cnt][i-1]][i-1];
            if (f[cnt][i]==0) break;
            s[cnt][i]=s[cnt][i-1]+s[f[cnt][i-1]][i-1];
        }
}

void xuli(ll p,ll q) {
    p^=last;
    q^=last;
    q-=a[p];
    if (q<0) {
        cout << "0\n";
        last=0;
        return;
    }
    int ans=1;
    FOD(i,20,0)
        if (f[p][i]!=0 && s[p][i] <= q) {
            ans+=1<<i;
            q-=s[p][i];
            p=f[p][i];
        }
    last=ans;
    cout << ans << "\n";
}
int main() {
    freopen(TASK".INP","r",stdin);
    freopen(TASK".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> q;

    while (q--) {
        ll x,p,q;
        cin >> x >> p >> q;
        if (x==1)
            add(p,q);
        else
            xuli(p,q);
    }
}
