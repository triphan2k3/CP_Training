#include <bits/stdc++.h>
#define TASK "1353E"
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
int pre[N];
int S(int i,int j) {
    if (i>j) return 0;
    return pre[j]-pre[i-1];
}
int main() {
    freopen(TASK".INP","r",stdin);
    freopen(TASK".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n,k;
        cin >> n >> k;
        string s;
        cin >> s;
        s=" "+s;
        vector<int> L(n+1,0),R(n+1,0);
        FOR(i,1,n)
            pre[i]=pre[i-1]+(s[i]-'0');
        FOR(i,1,k)
            L[i]=S(1,i-1);
        FOR(i,k+1,n)
            L[i]=min(L[i-k]+S(i-k+1,i-1)+(s[i]=='0'),S(1,i));

        FOD(i,n,n-k+1)
            R[i]=S(i+1,n);
        FOD(i,n-k,1)
            R[i]=min(R[i+k]+S(i+1,i+k-1)+(s[i]=='0'),S(i,n));

        int ans=S(1,n);
        FOR(i,1,n)
            ans=min(ans,L[i]+R[i]-(s[i]==0));
        cout << ans << "\n";
    }
}
