#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int N=300000;
int a[N], ok[N];
int t,n,k;
int main()
{
    cin >> t;
    while (t--) {
        cin >> n >> k;
        for (int i=1; i<=n; i++ )
            cin >> a[i];
        FOR(i, 2, n-1)
            if (a[i] > a[i-1] && a[i] > a[i+1]) ok[i]=1;
            else ok[i]=0;

        FOR(i, 2, n-1)
            ok[i]+=ok[i-1];
        int ans=0,pos=1;
        FOR(i, k, n)
            if (ok[i-1] - ok[i-k+1] > ans) {
                ans=ok[i-1] - ok[i-k+1];
                pos=i-k+1;
            }
        cout << ans+1 <<" "<< pos <<"\n";

    }
}
