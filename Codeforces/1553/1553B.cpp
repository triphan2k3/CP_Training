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

const int N=(int)1e6+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
int main() {
    freopen(TASK".INP","r",stdin);
    //freopen(TASK".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> q;
    while (q--) {
        string s,t;
        cin >> s >> t;
        int n=s.size();
        int m=t.size();
        s=" "+s;
        t=" "+t;
        int ans=0;
        FOR(st,1,n)
            FOR(ed,st,n) {
                if (ed-1+(ed-st+1) < m) continue;
                string tmp=" ";
                FOR(i,st,ed)
                    tmp.push_back(s[i]);
                int rem=m-(ed-st+1);
                FOR(i,1,rem)
                    tmp.push_back(s[ed-i]);
                if (tmp==t)
                    ans=1;
            }
        if (ans)
            cout << "YES\n";
        else
            cout << "NO\n";

    }
}
