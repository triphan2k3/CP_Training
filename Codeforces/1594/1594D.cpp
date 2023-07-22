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
vector<ii> say[N],said[N];
int role[N][2];
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
        int n,m;
        cin >> n >> m;
        FOR(i,1,n) {
            say[i].clear();
            said[i].clear();
            role[i][0] = role[i][1] = 0;
        }
        FOR(i,1,m) {
            int u,v,mk;
            string s;
            cin >> u >> v >> s;
            if (s[0] == 'i') mk = -1;
            else mk = 1;
            say[u].pb({v,mk});
            said[v].pb({u,mk});
        }
        int ans = 0;
        FOR(i,1,n) if (!role[i][0])  
        {
            int thisans = -1;
            FOR(j,0,1) {
                int flag = 1;
                int numim = j;
                queue<int> q;
                q.push(i);
                role[i][j] = j==0 ? 1:-1;
                while(q.size() && flag) {
                    int u = q.front();
                    q.pop();
                    for(ii e:say[u]) {
                        int v = e.F;
                        int r = e.S;
                        int truerole = r*role[u][j];
                        if (truerole != role[v][j] && role[v][j] != 0) {
                            flag = 0;
                            break;
                        }
                        if (role[v][j]!=0) continue;
                        role[v][j] = truerole;
                        numim += role[v][j]==-1;
                        q.push(v);
                    }
                    for(ii e:said[u]) {
                        int v = e.F;
                        int r = e.S;
                        int truerole = role[u][j] == r ? 1:-1;
                        if (truerole != role[v][j] && role[v][j] != 0) {
                            flag = 0;
                            break;
                        }
                        if (role[v][j]!=0) continue;
                        role[v][j] = truerole;
                        numim += role[v][j]==-1;
                        q.push(v);
                    }
                } 
                if (flag==0) continue;
                thisans = max(thisans,numim);  
            }
            if (thisans == -1 || ans == -1) ans = -1;
            else ans += thisans;
            if (ans==-1)
                break;
        }
        cout << ans << "\n";
    }
}