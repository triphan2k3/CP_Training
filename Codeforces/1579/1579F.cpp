#include <bits/stdc++.h>
#define TASK ""
#define pb push_back
#define F first
#define S second
#define FOR(i, a, b) for (int i=a; i<=b; i++)
#define FOr(i, a, b) for (int i=a; i<b ; i++)
#define FOD(i, a, b) for (int i=a; i>=b; i--)
#define FOd(i, a, b) for (int i=a; i>b ; i--)
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef vector<int> vi;

const int N=1e6+7;
const int MOD=1e9+7;
const ll INF=(ll)1e18+7;
int visit[N],h[N];
int main() {
    #ifdef TriPhan
        freopen("TEST.INP","r",stdin);
        freopen("TEST.OUT","w",stdout);
    #else
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    #endif
    int t; cin >> t;
    while (t--) {
        int n,d;
        cin >> n >> d;
        queue<int> q;
        int done = 0;
        FOR(i,0,n-1) {
            int x;
            cin >> x;
            if (x) visit[i]=0;
            else {
                visit[i] = 1;
                q.push(i);
                h[i] = 0;
                done++;
            }
        }
        int ans = 0;
        while (q.size()) {
            int u = q.front();
            q.pop();
            int v = (u+n-d) % n;
            if (visit[v]) continue;
            ans = h[v] = h[u]+1;
            visit[v] = 1;
            q.push(v);
            done++;
        }
        if (done<n)
            cout << "-1\n";
        else 
            cout << ans << "\n";
    }
}