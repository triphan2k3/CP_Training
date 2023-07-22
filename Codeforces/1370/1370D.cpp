#include <bits/stdc++.h>
#define TASK "1370D"
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
int a[N],d[N];
int n,k;
int check(int v) {
    if (a[1]<=v) d[1]=1; else d[1]=0;
    //d[2] = d[1];
    //if (d[2]==0 && a[2]<=v) d[2]=1;
    if (d[1]>=k) return 1;
    for (int i=2;i<n;i++) {
        if (a[i]<=v)
            d[i]=max(d[i-2]+1,d[i-1]);
        else
            d[i]=max(d[i-2],d[i-1]);
        if (d[i]>=k) return 1;
    }
    //if (d[n]>=k &&)
    return 0;
}
int main() {
    freopen(TASK".INP","r",stdin);
    freopen(TASK".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    srand(time(0));
    int st=1;
    cin >> n >> k;
    //n=rand() % 15;
    //k=rand() % n + 2;
    //cout << n<< " "<< k << "\n";
    if (k%2) {
        st=2;
        k++;
        n++;
    }
    k/=2;
    FOR(i,st,n)
        cin >> a[i];
       // { a[i]=rand()%1000000; cout << a[i] << " ";} cout << "\n";
    check(1);
    int ma=a[1];
    FOR(i,2,n)
        ma=max(ma,a[i]);
    int r=ma;
    int l=1;
    int ans=r;
    while (r>=l) {
        int m=(r+l)>>1;
        if (check(m)) {
            ans=m;
            r=m-1;
        } else
            l=m+1;
    }
    reverse(a+1,a+n+1);
    l=1;
    r=ma;
    while (r>=l) {
        int m=(r+l)>>1;
        if (check(m)) {
            ans=min(ans,m);
            r=m-1;
        } else
            l=m+1;
    }
    cout << ans;
}
