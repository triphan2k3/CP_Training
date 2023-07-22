#include <bits/stdc++.h>
#define TASK "1380B"
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
    //freopen(TASK".INP","r",stdin);
    //freopen(TASK".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int R=0,S=0,P=0;
        for (int i=0;i<s.size();i++) {
            if (s[i]=='R') P++;
            if (s[i]=='P') S++;
            if (s[i]=='S') R++;
        }
        if (R>=P && R>=S) {
            for (int i=1;i<=s.size();i++)
                cout<<"R";
            cout<<"\n";
            continue;
        }
        if (P>=R && P>=S) {
            for (int i=1;i<=s.size();i++)
                cout<<"P";
            cout<<"\n";
            continue;
        }
        if (S>=P && S>=R) {
            for (int i=1;i<=s.size();i++)
                cout<<"S";
            cout<<"\n";
            continue;
        }
    }
}
