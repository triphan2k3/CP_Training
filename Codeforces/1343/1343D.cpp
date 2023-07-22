#include <bits/stdc++.h>
#define ll long long
#define TASK "1343D"
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FOD(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
const int N = 400009;
int a[N];
int e[N], d[N], u[N];
int n, k, t;
int main()
{
    freopen(TASK".INP","r",stdin);
    freopen(TASK".OUT","w",stdout);
    cin >> t;
    while (t--) {
        cin >> n >> k;
        FOR(i, 2, 2*k+1)
            e[i] = d[i] = u[i] = 0;
        FOR(i, 1, n)
            cin >> a[i];
        FOR(i, 1, n/2){
            int l = a[i];
            int r = a[n-i+1];
            ++e[l+r];
            ++u[max(l,r)+k];
            ++d[min(l,r)+1];
        }
        FOR(i, 3, 2*k)
            u[i] += u[i-1];
        FOD(i, 2*k, 2)
            d[i] += d[i+1];
        int ans=n/2;
        FOR(i, 2, 2*k)
            ans = min(ans, n/2 - e[i] + u[i-1] + d[i+1]);
        cout << ans << "\n";
    }

}
