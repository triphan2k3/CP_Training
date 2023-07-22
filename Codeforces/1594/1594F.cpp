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
    while(t--) {
        ll s,n,k;
        cin >> s >> n >> k;
        if (s<k) {
            cout << "NO\n";
            continue;
        }
        if (k==1) {
            if (s<n*2) 
                cout << "YES\n";
            else
                cout << "NO\n";
            continue;
        }
        ll numseg = n/k;
        ll endnumber = numseg*2*k + (n%k);
        if (endnumber <= s && (s-endnumber>=n%k)) cout << "NO\n";
        else cout << "YES\n";

    }
}