#include <bits/stdc++.h>
#define TASK "1333B"
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
bool solve() {
    int n;
    cin >> n;
    vector<int> a(n),b(n),Add(n,0),Sub(n,0);
    FOr(i, 0, n)
        cin >> a[i];
    FOr(i, 0, n)
        cin >> b[i];
    FOr(i, 1, n) {
        Add[i]=Add[i-1] || (a[i-1]== 1);
        Sub[i]=Sub[i-1] || (a[i-1]==-1);
    }
    FOr(i, 0, n)
        if (a[i]!=b[i]) {
            if (a[i] > b[i] && Sub[i]==0) return 0;
            if (a[i] < b[i] && Add[i]==0) return 0;
    }
    return 1;
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
        if (solve()) cout<<"YES\n";
        else cout<<"NO\n";
    }
}
