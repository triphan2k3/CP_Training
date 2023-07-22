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

const int N=(int)1e5+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
int p[N][27];
int last[27][2];
int f[N][2];
int main() {
    //freopen(TASK".INP","r",stdin);
    //freopen(TASK".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        string s,t;
        cin >> s >> t;
        int n=s.size();
        int m=t.size();
        s=" "+s;
        t=" "+t;
        FOR(i,0,25)
            last[i][0]=last[i][1]=0;
        FOR(i,1,n) {
            FOR(ch,0,25)
                p[i][ch]=last[ch][(i+1)%2];
                last[s[i]-'a'][i%2]=i;
            }
        f[m][0]=last[t[m]-'a'][0];
        f[m][1]=last[t[m]-'a'][1];
        if (m%2) f[m][1] = 0;
        else f[m][0] = 0;
        FOD(i,m-1,1) {
            int id0=f[i+1][0];
            int id1=f[i+1][1];

            if (id0) f[i][1]=p[id0][t[i]-'a'];
            else f[i][1]=0;

            if (id1) f[i][0]=p[id1][t[i]-'a'];
            else f[i][0]=0;
        }
        if (f[1][0] || f[1][1])
            cout << "YES\n";
        else
            cout << "NO\n";

    }
}