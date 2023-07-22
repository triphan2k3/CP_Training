#include <bits/stdc++.h>
#define TASK "633E"
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
int a[N][21], b[N][21];
int lg[N];
int n,k;
int getmn(int l,int r) {
    int k=lg[r-l+1];
    return min(b[l][k],b[r-(1<<k)+1][k]);
}

int getmx(int l,int r) {
    int k=lg[r-l+1];
    return max(a[l][k],a[r-(1<<k)+1][k]);
}
int solve(int l,int r) {
    int i=l;
    while (l+1<r) {
        int mid=(l+r) >> 1;
        if (getmn(i,mid) >= getmx(i,mid))
            l=mid;
        else
            r=mid;
    }
    int ans=min(getmn(i,l),getmx(i,l));
    if (l<n)
        ans=max(ans,
                min(getmn(i,l+1),getmx(i,l+1)));
    return ans;
}
int main() {
    freopen(TASK".INP","r",stdin);
    freopen(TASK".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;

    FOR(i,1,n) {
        cin >> a[i][0];
        a[i][0]*=100;
    }
    FOR(i,1,n)
        cin >> b[i][0];

    FOR(k,1,20)
        FOR(i,1,n-(1<<k)+1) {
            a[i][k]=max(a[i][k-1],a[i+(1<<(k-1))][k-1]);
            b[i][k]=min(b[i][k-1],b[i+(1<<(k-1))][k-1]);
        }
    vector<ll> ans;
    FOR(i,2,n)
        lg[i]=lg[i/2]+1;

    FOR(i,1,n)
        ans.push_back(solve(i,n));

    sort(ans.begin(),ans.end());
    long double cur=1.0*k/(long double)n;
    long double res=1.0*ans[0]*cur;
    FOR(i,1,n-k) {
        cur*=(long double)(n-k-i+1)/(long double)(n-i);
        res+=(long double)cur*ans[i];
    }
    cout << setprecision(7) << fixed << res;
}
