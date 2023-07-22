#include <bits/stdc++.h>
#define TASK "1074D"
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
map<int,int> pos;
int dsu[N],gt[N];
int q,lst,cnt;

int  par(int u) {
    if (dsu[u]<0) return u;
    int t=dsu[u];
    int rt=par(t);
    dsu[u]=rt;
    gt[u]^=gt[t];
    return rt;
}
void gop(int l,int r, int val) {
    int u=par(l);
    int v=par(r);
    if (u==v) return;
    if (dsu[u] < dsu[v])
        swap(u,v);
    dsu[u]+=dsu[v];
    dsu[v]=u;
    gt[v]=gt[l]^gt[r]^val;

}
int main() {
    //freopen(TASK".INP","r",stdin);
    //freopen(TASK".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> q;

    for (int i=1;i<=2*q;i++)
        dsu[i]=-1;

    while (q--) {
        int t,l,r,x;
        cin >> t;
        if (t==1) {
            cin >> l >> r >> x;
            l^=lst; r^=lst; x^=lst;
            ++l,++r;
            if (l>r) swap(l,r); r++;

            int pl= pos[l];
            int pr= pos[r];

            if (!pl) {
                pl=++cnt;
                pos[l]=cnt;
            }
            if (!pr) {
                pr=++cnt;
                pos[r]=cnt;
            }

            gop(pl,pr,x);
        } else {
            cin >> l >> r;
            l^=lst; r^=lst;
            l++; r++;
            if (l>r) swap(l,r); r++;

            int pl=pos[l];
            int pr=pos[r];
            int res=0;

            if (pl==0 || pr==0) res=-1;
                else if (par(pl)!=par(pr)) res=-1;
                    else res=gt[pl]^gt[pr];

            cout << res << "\n";
            lst=(res==-1) ? 1:res;
        }
    }
}
