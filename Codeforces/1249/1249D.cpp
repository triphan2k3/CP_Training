#include <bits/stdc++.h>
#define TASK "1249D"
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
iii a[N];
int n,k;
int main() {
    //freopen(TASK".INP","r",stdin);
    //freopen(TASK".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    FOR(i,1,n) {
        cin >> a[i].F.F >> a[i].F.S;
        a[i].S=i;
    }
    sort(a+1,a+n+1);
    set<ii> s;
    vector<int> ans;
    int j=1;
    FOR(i,1,200000) {
        while (a[j].F.F==i)
            s.insert({a[j].F.S,a[j++].S});
        while (s.size() > k) {
            ii tmp=*s.begin();
            if (tmp.F < i)
                s.erase(s.begin());
            else {
                ii it=*s.rbegin();
                ans.push_back(it.S);
                s.erase(prev(s.end()));
            }
        }
    }
    cout << ans.size() << "\n";
    sort(ans.begin(),ans.end());
    for (int i:ans)
        cout << i << " ";
}
