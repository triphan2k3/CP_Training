#include <bits/stdc++.h>
#define TASK ""
#define pb push_back
#define F first
#define S second
#define FOR(i, a, b) for (int i=a; i<=b; i++)
#define FOr(i, a, b) for (int i=a; i<b ; i++)
#define FOD(i, a, b) for (int i=a; i>=b; i--)
#define FOd(i, a, b) for (int i=a; i>b ; i--)
#define all(a) a.begin(), a.end()
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
    #endif
    int t; cin >> t; 
    while (t--) {
        int n; cin >> n;
        vector<int> a;
        set<int> s;
        FOR(i, 1, n) s.insert(i);
        FOR(i, 1, n) {
            if (s.find(i) == s.end()) continue;
            for (int j = i; j <= n; j <<= 1) {
                a.push_back(j);
                s.erase(j);                
            }
        }
        for (int &x:a) cout << x << " ";
        cout << "\n";
    }
}