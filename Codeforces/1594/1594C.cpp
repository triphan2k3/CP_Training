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
    int t;
    cin >> t;
    while(t--) {
        int n;
        char c;
        string s;
        cin >> n >> c >> s;
        int flag = 1;
        for(char ch:s)
            flag &= (ch==c);
        if (flag) {
            cout << "0\n";
            continue;
        }
        int half = n/2 + 1;
        s = " "+s;
        int pos = 0;
        FOR(i,half,n) 
            if (s[i]==c) {
                pos = i;
                break;
            }
        if (pos) {
            cout << "1\n" << pos << "\n";
            continue;
        } 
        cout << "2\n";
        cout << n-1 << " " << n << "\n";
    }
}