#include <bits/stdc++.h>
#define TASK ""
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()
#define ii pair<int,int>
#define iii pair<ii,int>
#define ll long long
#define F first
#define S second
#define sz(x) ((int) (x).size())
#define FOR(i, a, b) for (int i=a; i<=b; i++)
#define FOr(i, a, b) for (int i=a; i<b ; i++)
#define FOD(i, a, b) for (int i=a; i>=b; i--)
#define FOd(i, a, b) for (int i=a; i>b ; i--)
using namespace std;

const int N=1e6+7;
const int MOD=1e9+7;
const ll INF=(ll)1e18+7;

int main() {
  #ifdef TriPhann
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
      int n;
      cin >> n;
      int loop = sqrt(n);
      if (loop*loop == n) {
          cout << loop << " 1\n";
          continue;
      }
      int rem = n - loop*loop;
      if (rem <= loop) 
          cout << rem << " " << loop+1 << "\n";
      else
          cout << loop+1 << " " << 2*loop - rem + 2 << "\n";
  }
}
