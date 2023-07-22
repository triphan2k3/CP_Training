#include <bits/stdc++.h>
#define TASK ""
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
int a[N];
int main() {
    //freopen(TASK".INP","r",stdin);
    //freopen(TASK".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n,k;
        string s;
        cin >> n >> k >> s;
        s="@"+s;
        int l=n+1;int r=0;
        FOR(i,1,n)
            if (s[i]=='*') {
                l=min(l,i);
                r=max(r,i);
                a[i]=1;
            } else a[i]=0;
        if (l>r) {
            cout << "0\n";
            continue;
        }
        if (l==r) {
            cout << "1\n";
            continue;
        }
        int ans=2;
        int past=l;
        while (past+k<r) {
            ans++;
            FOD(i,past+k,past+1)
                if (a[i]) {
                    past=i;
                    break;
                }
        }
        cout << ans << "\n";
    }
}
