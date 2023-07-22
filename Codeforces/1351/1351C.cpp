#include <bits/stdc++.h>
#define TASK "1351C"
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
        string s;
        cin >> s;
        map<ii,int> m;
        int I=0,J=0,ans=0;
        FOr(i, 0, s.size()) {
            int ni=I;
            int nj=J;
            if (s[i]=='N')
                I--;
            if (s[i]=='S')
                I++;
            if (s[i]=='W')
                J--;
            if (s[i]=='E')
                J++;
            if (m[{I+ni,J+nj}]) ans++;
            else {
                m[{I+ni,J+nj}]=1;
                ans+=5;
            }
        }
        cout << ans << "\n";
    }
}
