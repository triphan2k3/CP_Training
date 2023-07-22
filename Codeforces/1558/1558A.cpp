#include <bits/stdc++.h>
#define TASK ""
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()
#define ii pair<int,int>
#define iii pair<ii,int>
#define ll long long
#define F first
#define S second
#define sz(x) ((int) (x).size())
#define FOR(i, a, b) for (int i=a; i<=b; i++)
#define FOr(i, a, b) for (int i=a; i<b ; i++)
#define FOD(i, a, b) for (int i=a; i>=b; i--)
#define FOd(i, a, b) for (int i=a; i>b ; i--)
using namespace std;

const int N=1e6+7;
const int MOD=1e9+7;
const ll INF=(ll)1e18+7;
int c[N];
int main() {
    #ifdef TriPhann
        freopen("TEST.INP","r",stdin);
        freopen("TEST.OUT","w",stdout);
    #else
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    #endif
    int t;
    cin >> t;
    while (t--) {
        int a,b;
        cin >> a >> b;
        int n = a+b;
        if (b>a) swap(a,b);
        // B first, a>b
        int na=n/2;
        int nb=n-na;
        vector<int> ans;
        for(int i=a;i<=n;i++) {
            if (!c[i-na + i-a])
                ans.push_back(i-na + i-a);
            c[i-na + i-a] = 1;
        }
        if (na!=nb) {
            na++;
            nb--;
            for(int i=a;i<=n;i++) {
                if (!c[i-na + i-a])
                    ans.push_back(i-na + i-a);
                c[i-na + i-a] = 1;
                }
        }
        sort(ans.begin(),ans.end());
        cout << ans.size() << "\n";
        for(int x:ans) {
            cout << x << " ";
            c[x]=0;
        }
        cout << "\n";

    }
}
