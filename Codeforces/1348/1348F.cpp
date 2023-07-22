#include <bits/stdc++.h>
#define TASK "1348F"
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
struct data {
    int X, Y, Z;

};

const int N=(int)1e6+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
int IT[N];
data a[N],b[N];
int n;

bool cmp(data a, data b) {
    return (a.X != b.X) ? a.X<b.X : a.Y<b.Y;
}

void Insert(int i, int l, int r, int x, int val) {
    if (x < l || x>r) return;
    if (l == r) {
        IT[i]=val;
        return;
    }

    int m = (l+r) >> 1;
    Insert(i*2, l, m, x, val);
    Insert(i*2+1, m+1, r, x, val);
    IT[i]=max(IT[i*2],IT[i*2+1]);
    return;
}
int Get(int i, int l, int r, int L, int R) {
    if (l>=L && r<=R) return IT[i];
    if (L>r || R<l) return 0;
    int m=(l+r) >> 1;
    int x=Get(i*2, l, m, L, R);
    int y=Get(i*2+1, m+1, r, L, R);
    return max(x,y);
}
void show() {
    vector<int> ans(n+1);
    FOR(i,1,n)
        ans[a[i].Z]=i;
    FOR(i,1,n)
        cout<<ans[i]<<" ";
}

void builda() {
    priority_queue<ii,vector<ii>,greater<ii>> q;
    sort(a+1,a+n+1,cmp);
    int l=1;
    FOR(i,1,n) {
        while (a[l].X==i && l<=n)
            q.push({a[l].Y,l++});
        ii gt=q.top();
        q.pop();
        b[i]=a[gt.S];
    }
    FOR(i,1,n)
        a[i]=b[i];
    return;

}
int main() {
    freopen(TASK".INP","r",stdin);
    freopen(TASK".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    FOR(i, 1, n) {
        cin >> a[i].X >> a[i].Y;
        a[i].Z = i;
    }
    builda();
    Insert(1,1,n,1,a[1].Y);
    int l=0;
    FOR(i, 2, n) {
        int R=i, L=a[i].X;
        int ck = Get(1,1,n,L,R);
        Insert(1,1,n,i,a[i].Y);
        if (ck>=i) {
            l=i;
            break;
        }
    }
    int r=0;
    FOr(i, a[l].X, l)
        if (a[i].Y >= l) {
            r=i;
            break;
    }
    if (l) {
        cout << "NO\n";
        show();
        swap(a[l],a[r]);
        cout<<"\n";
        show();
        return 0;
    }
    cout<<"YES\n";
    show();

}
