#include <bits/stdc++.h>
#define TASK "1343C"
#define ll long long
#define FOR(i,a,b) for(int i=a;i<=b;i++)

using namespace std;
const int N=200001;
int a[N];
int n,t;
int f(int a) {
    if (a < 0) return -1;
    return 1;
}
int main()
{
    freopen(TASK".INP","r",stdin);
    freopen(TASK".OUT","w",stdout);
    cin>>t;
    while (t--) {
        cin >> n;
        FOR(i, 1, n)
            cin >> a[i];

        int sign = f(a[1]);
        ll ans = 0;
        int ma = a[1];
        FOR(i, 2, n) {
            if (f(a[i]) == sign) ma = max(ma,a[i]);
            else {
                ans += ma;
                ma = a[i];
                sign = -sign;
            }
        }
        ans += ma;
        cout << ans << "\n";
    }
}
