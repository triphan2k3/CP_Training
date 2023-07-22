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
int f[15][2][2];
int main() {
    #ifdef TriPhan
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
        string s;
        cin >> s;
        int n = s.size();
        reverse(s.begin(),s.end());
        s = "#" + s;
        FOR(i,1,10)
            f[i][0][0]=f[i][1][1]=f[i][1][0]=f[i][0][1]=0;
        f[0][0][0]=1;
        FOR(i,1,n) {
            FOR(u,0,9) FOR(v,0,9) {
                int sum = u+v;
                if (sum%10 == s[i]-'0') {
                    int mem = u+v > 9;
                    f[i][mem][0] += f[i-1][0][0];
                    f[i][mem][1] += f[i-1][1][0];

                }
                if ((sum+1)% 10 == s[i]-'0') {
                    int mem = (sum+1) > 9;
                    f[i][mem][0] += f[i-1][0][1];
                    f[i][mem][1] += f[i-1][1][1];
                }
            }
        }
        cout << f[n][0][0]-2 << "\n";
    }
}