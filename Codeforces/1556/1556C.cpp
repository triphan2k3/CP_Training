#include <bits/stdc++.h>
#define TASK ""
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()
#define ii pair<int,int>
#define iii pair<ii,int>
#define ll long long
#define F first
#define S second
#define sz(x) ((int) (x).size())
#define FOR(i, a, b) for (int i=a; i<=b; i++)
#define FOr(i, a, b) for (int i=a; i<b ; i++)
#define FOD(i, a, b) for (int i=a; i>=b; i--)
#define FOd(i, a, b) for (int i=a; i>b ; i--)
using namespace std;

const int N=1e3+7;
const int MOD=1e9+7;
const ll INF=(ll)1e18+7;
ll ans;
int n;
int a[N];
int wrong[N];
ll pre[N],m[N][N];

ll Sum(int l,int r) {
    return pre[r]-pre[l-1];
}
int main() {
    #ifdef TriPhan
        freopen("TEST.INP","r",stdin);
        freopen("TEST.OUT","w",stdout);
    #else
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    #endif
    cin >> n;
    FOR(i,1,n) {
        cin >> a[i];
        if (i%2==0)
            a[i] = -a[i];
    }

    FOR(i,1,n)
            pre[i]=pre[i-1]+a[i];

    FOR(i,1,n) {
        m[i][i]=Sum(i,i);
        FOR(j,i+1,n)
            m[i][j]=min(m[i][j-1],Sum(i,j));
    }
    FOR(i,1,n) if (i%2) {
        ll sum = 0;
        int id=i;
        while (sum>=0 && id <= n) {
            sum+=a[id];
            id++;
        }
        wrong[i]=id;
    }
    FOR(i,1,n) FOR(j,i,n) 
    if (i%2==1 && j%2==0){
        ll mid = Sum(i+1,j-1);
        if (wrong[i]<j) continue;
        ll l = a[i];
        ll r = a[j];
        if (m[i+1][j-1]<0) {
            l+=m[i+1][j-1];
            mid-=m[i+1][j-1];
        }
        if (l<0) continue;
        if (mid < 0) //thieu ngoac mo
            l+=mid;
        else
            r+=mid;
        if (l<0 || r>0) continue;
        if (l!=a[i] && r!=a[j]) ans++;
        ans+=1LL*min(abs(l),abs(r));
    }
    cout << ans;
}
