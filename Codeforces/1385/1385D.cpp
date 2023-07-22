#include <bits/stdc++.h>
#define TASK "1385D"
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
string s;
int f[N];

int calc(int l, int r, char c) {
    if (f[l]!=-1) return f[l];
    if (l==r) {
        f[l]=(s[l]==c) ? 0:1;
        return f[l];
    }
    int m=(l+r) >> 1;
    int ans1=calc(l,m,c+1);
    FOR(i,m+1,r)
        if (s[i]!=c)
            ans1++;
    int ans2=calc(m+1,r,c+1);
    FOR(i,l,m)
        if (s[i]!=c)
            ans2++;
    f[l]=min(ans1,ans2);
    return f[l];
}
int main() {
    //freopen(TASK".INP","r",stdin);
    //freopen(TASK".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cin >> s;
        s="."+s;
        for (int i=1;i<=n;i++)
            f[i]=-1;
        cout << calc(1,n,'a') << "\n";
    }
}
