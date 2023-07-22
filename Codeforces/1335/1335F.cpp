#include <bits/stdc++.h>
#define TASK "1335F"
#define pb push_back
#define ii pair<int,int>
#define ll long long
#define F first
#define S second
#define FOR(i, a, b) for (int i=a; i<=b; i++)
#define FOr(i, a, b) for (int i=a; i<b ; i++)
#define FOD(i, a, b) for (int i=a; i>=b; i--)
#define FOd(i, a, b) for (int i=1; i>b ; i--)
using namespace std;

void solution1()
{
    freopen(TASK".INP", "r", stdin);
    freopen(TASK".OUT", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=0;
    cin >> t;
    while (t--) {
        int m,n;
        cin >> m >> n;
        vector<string> s(m);
        vector<string> c(m);
        FOr(i, 0, m) cin >> c[i];
        FOr(i, 0, m) cin >> s[i];
        vector<int> deg(m*n,0);
        vector<int> f(m*n);
        vector<vector<int>> e(m*n);

        FOr(i, 0, m)
            FOr(j, 0, n) {
                int x = i, y = j;
                if (s[x][y] == 'L') y--;
                else if (s[x][y] == 'R') y++;
                else if (s[x][y] == 'U') x--;
                else if (s[x][y] == 'D') x++;

                f[i*n + j] = x*n + y;

            }
        FOr(x, 0, m*n)
            deg[f[x]]++;

        vector<int> q;
        FOr(x, 0, m*n)
            if (deg[x] == 0)
                q.pb(x);

        while (q.size()) {
            int x=q.back();
            q.pop_back();
            if (--deg[f[x]] == 0)
                q.pb(f[x]);
            e[f[x]].pb(x);
        }

        vector<ii> qu;
        int ans=0,ans2=0;
        FOr(i, 0, m*n)
            if (deg[i]>0) {
                int len = 1;
                for (int x = f[i]; x != i; ++len, x=f[x])
                    e[f[x]].pb(x);

                ans += len;
                vector<int> kt(len,0);
                qu.pb({i,0});
                while (qu.size()) {
                    int j=qu.back().F;
                    int d=qu.back().S;
                    --deg[j];
                    if (c[j / n][j % n] == '0') kt[d % len]=1;
                    qu.pop_back();
                    for (int x:e[j]) {
                        qu.pb({x, d+1});
                    }
                }
                for (int i:kt)
                    ans2 += i;
            }
        cout << ans << " " << ans2 << "\n";
    }
}
string s;
const int N=1e6;
int t,m,n;
int val[N],res[N],ans[N];
int f[N][22];


int main() {
    freopen(TASK".INP", "r", stdin);
    freopen(TASK".OUT", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> m >> n;
        FOr(i, 0, m) {
            cin>>s;
            FOr(j, 0, n)
                val[i*n + j]=(s[j]-'0')^1;
        }
        FOr(i, 0, m) {
            cin >> s;
            FOr(j, 0, n) {
                int x = i,y = j;
                if (s[j] == 'U') x--;
                if (s[j] == 'D') x++;
                if (s[j] == 'L') y--;
                if (s[j] == 'R') y++;
                f[i*n + j][0] = x*n + y;
            }
        }
        FOR(d, 1, 21)
            FOr(i, 0, m*n)
                f[i][d]=f[f[i][d - 1]][d - 1];
        FOr(i, 0, m*n) {
            ans[f[i][21]]++;
            res[f[i][21]]+=val[i];
        }
        int R1=0,R2=0;
        FOr(i, 0, m*n) {
            R1 += (ans[i] > 0);
            R2 += (res[i] > 0);
        }
        FOr(i, 0, m*n)
            ans[i] = res[i] = 0;
        cout<<R1<<' '<<R2<<'\n';



    }
}
