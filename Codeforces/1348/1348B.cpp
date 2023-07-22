#include <bits/stdc++.h>
#define TASK "1348B"
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
int main() {
    freopen(TASK".INP","r",stdin);
    freopen(TASK".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n,k;
        cin >> n >> k;
        ++n;
        vector<int> a(n),c(n--,0);
        int cnt=0;
        FOr(i,0,n) {
            cin >> a[i];
            c[a[i]]++;
            if (c[a[i]]==1) ++cnt;
        }
        if (cnt>k) {
            cout << "-1\n";
            continue;
        }
        vector<int> b,ans;
        FOR(i,1,n)
            if (c[i]) b.push_back(i);
        FOR(i,1,n)
            if (!c[i] && cnt<k) {
                b.push_back(i);
                ++cnt;
            }
        int j=0;
        FOr(i,0,n) {
            while (b[j]!=a[i]) {
                ans.pb(b[j++]);
                j%=cnt;
            }
            ans.push_back(b[j++]);
            j%=cnt;
        }
        cout<<ans.size()<<"\n";
        for(int i:ans)
            cout<<i<<" ";
        cout<<"\n";
    }
}
