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
    int t; cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int app0 = 0,app1 = 0, lst0 = 0, num0 = 0;
        int n = s.size();
        s = '#'+s;
        FOR(i,1,n) {
            app0|= s[i] == '0';
            app1|= s[i] == '1';
            lst0 = s[i] =='0' ? i:lst0;
            num0+= s[i]=='0';
        }
        if (app0 == 0) {
            cout << "0\n"; continue;
        }
        if (app1 == 0) {
            cout << "1\n"; continue;
        }
        int ans = 1;
        FOR(dec,0,num0-1) 
            if (s[lst0-dec]=='1')
                ans = 2;
        cout << ans << "\n";
    }
        
}