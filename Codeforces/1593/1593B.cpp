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

int main() {
    #ifdef TriPhan
        freopen("TEST.INP","r",stdin);
        freopen("TEST.OUT","w",stdout);
    #else
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    #endif
    int t; cin >>t;
    while (t--) {
        string s;
        cin >> s;
        int n = s.size(); s=" " + s;
        int pos5=0,pos0=0;
        int ans = n;
        FOR(i,1,n)
            if (s[i]=='0') pos0 = i;
            else if (s[i]=='5') pos5=i;
        FOD(i,pos0-1,1)
            if (s[i]=='0' || s[i]=='5')
                ans = min(ans,n-i-1);
        FOD(i,pos5-1,1)
            if (s[i]=='2' || s[i]=='7')
                ans = min(ans,n-i-1);
        cout << ans << "\n";
    }
}