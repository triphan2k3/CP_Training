#include <bits/stdc++.h>
#define TASK ""
#define pb push_back
#define F first
#define S second
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
const int MOD=1e9+7;
const ll INF=(ll)1e18+7;
struct data {
    int fst,lst;
    ll ans;
    data() {}
    data(int u,int v,ll w) : fst(u), lst(v), ans(z) {}
}

ll call (int x) {
    ll ans = 1LL*x*(x+1)/2;
    return ans;
}

data xuli(data L, data R,int l,int r) {
    int m = (l+r) >> 1;
    if (L.fst < 0) return R;
    if (R.fst < 0) return L;
    data ret(0,0,0);
    res.ans = L.ans+ R.ans;
    int sz = r-l+1;
    int szl = m-l+1;
    int szr = r-m;
    if (a[m] <= a[m+1]) {
        if (L.fst == szl && R.fst == szr) 
            ret(len,len,0);
        else if (L.fst == szl)
            ret(R.fst + szl,R.lst,R.ans);
        else if (R.fst == szr) 
            ret(L.fst,L.lst + szr,L.ans);
        else
            ret(L.fst,R.lst, call(R.fst + L.lst));        
    } else {
        ret(L.fst,R.lst,0);
        ll r1 = L.lst < szl ? call(L.lst) : 0;
        ll r2 = R.fst < szr ? call(R.fst) : 0;
        ret.ans = r1+r2;
    }
    return ret;
}
void build (int i, int l, int r) {
    if (l==r) {
        it[i]=data(1, 1, 0);
        return;
    }
    int m = (l+r) >> 1;
    build(i*2,l,m);
    build(i*2+1,m+1,r);
    it[id] = xuli(it[i*2],it[i*2+1],l,r);
}

void update(int i,int l,int r,ind pos) {
    if (l>p || r<p) return;
    if (l==r) {
        it[i] = data(1,1,0);
        return;
    }
    int m = (l+r) >> 1;
    update(i*2,l,m,pos);
    update(i*2+1,m+1,r,p);
    it[i] = xuli(it[i*2],it[i*2+1],l,r);
}

data det(int i, int l, int r, int L, int R)
{
    if (l > R || r < L) 
        return data(-1, -1, -1);
    if (L <= l && r <= R) 
        return it[i];
    int m = (l + r) >> 1;
    data lef = 
    return gop(get(lc, l, m, L, R), get(rc, m + 1, r, L, R), max(l, L), min(R, r), m);
}
    #ifdef TriPhan
        freopen("TEST.INP","r",stdin);
        freopen("TEST.OUT","w",stdout);
    #else
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    #endif
    cin >> n >> q;
    FOR(i,1,n)
        cin >> a[i];
    L[1] = 1;
    FOR(i,2,n) {
        L[i] = a[i]>=a[i-1] ? L[i-1]:i;
    }
    R[n]=n;
    FOD(i,n-1,1) {
        R[i] = a[i]<=a[i+1] ? L[i+1]:i;
    }
    FOR(i,1,n)
        if (R[i]==i) update(i,cal(i));
    
    while (q--) {
        int i,u,v;
        cin >> i >> u >> v;
        if (i==1) {
            preR = R[i];
            preL
        } 
    }
}