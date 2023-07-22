#include <bits/stdc++.h>
#define TASK "1409E"
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
int a[N],b[N],L[N],R[N];
int n,k;
int main() {
    //freopen(TASK".INP","r",stdin);
    //freopen(TASK".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n,k;
        cin >> n >> k;
        FOR(i,1,n)
            cin >> a[i];
        FOR(i,1,n)
            cin >> b[i];
        sort(a+1,a+n+1);
        int l=1;
        FOR(i,1,n) {
            while (a[i]-a[l] > k)
                l++;
            L[i]=i-l+1;
        }
        int r=n;
        FOD(i,n,1) {
            while (a[r]-a[i] > k)
                r--;
            R[i]=r-i+1;
        }
        FOR(i,1,n)
            L[i]=max(L[i],L[i-1]);
        FOD(i,n-1,1)
            R[i]=max(R[i],R[i+1]);
        int ans=1;
        FOR(i,1,n-1)
            ans=max(ans,L[i]+R[i+1]);
        cout << ans << "\n";
    }
}
