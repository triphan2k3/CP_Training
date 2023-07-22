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

const int N=(int)1e3+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
int a[N],b[N];
int main() {
    //freopen(TASK".INP","r",stdin);
    //freopen(TASK".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int k,n,m;
        cin >> k >> n >> m;
        FOR(i,1,n)
            cin >> a[i];
        FOR(i,1,m)
            cin >> b[i];
        a[n+1]=b[m+1]=1000;
        vector<int> ans;
        int na=1,nb=1;
        FOR(i,1,m+n) {
            if (a[na]==0) {
                na++;
                k++;
                ans.push_back(0);
                continue;
            }
            if (b[nb]==0) {
                nb++;
                k++;
                ans.push_back(0);
                continue;
            }
            if (a[na]<=k) {
                ans.push_back(a[na]);
                na++;
                continue;
            }
            if (b[nb]<=k) {
                ans.push_back(b[nb]);
                nb++;
                continue;
            }
            break;
        }
        if (ans.size()==m+n) {
            for(int x:ans)
                cout << x << " ";
            cout << "\n";
        }
        else
            cout << "-1\n";

    }
}
