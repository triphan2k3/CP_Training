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

const int N=4e6+7;
const int MOD=1e9+7;
const ll INF=(ll)1e18+7;
struct node {
    int len,l,r;
    node() {}
    node(int x, int y, ll z) : len(x), l(y), r(z) {} 
} it[N];
int a[N];

node gop(node L,node R) {
    if (R.len==0) return L;
    if (L.len==0) return R;
    node ret(0,0,0);
    if (L.r != R.l) {
        ret.l=L.l;
        ret.r=R.r;
        ret.len=L.len+R.len;
        return ret;
    }
    int mi = min(L.len,R.len);
    L.len-=mi;
    R.len-=mi;
    if (L.len==R.len)
        return ret;
    if (L.len==0) {
        ret.r=R.r;
        ret.l=R.l ^ (mi%2);
        ret.len=R.len;
    }
    if (R.len==0) {
        ret.r=L.r ^ (mi%2);
        ret.l=L.l;
        ret.len=L.len;
    }
    return ret;
}

void build(int i,int l,int r) {
    if (l==r) {
        it[i].l=it[i].r=a[l];
        it[i].len=1;
        return;
    }
    int m = (l+r)>>1;
    build(i*2,l,m);
    build(i*2+1,m+1,r);
    it[i]=gop(it[i*2],it[i*2+1]);
}

node get(int i,int l,int r,int L,int R) {
    if (L<=l && R>=r) return it[i];
    if (R<l || L>r) return node(0,0,0);
    int m = (l+r)>>1;
    node lef = get(i*2,l,m,L,R);
    node rig = get(i*2+1,m+1,r,L,R);
    return gop(lef,rig);
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
    int t;
    cin >> t;
    while(t--) {
        string s; cin >> s;
        FOR(i,1,s.size())
            if (s[i-1]=='[' || s[i-1]==']') 
                a[i]=1;
            else 
                a[i]=0;
        build(1,1,s.size());
        int q;
        cin >> q;
        while(q--) {
            int l,r;
            cin >> l >> r;
            node res = get(1,1,s.size(),l,r);
            //cout << res.l << res.r << res.len << "\n";
            int ans = res.len/2;
            if (res.len%2==1 && res.l==1) ++ans;
            cout << ans << "\n";
        }
    }
}