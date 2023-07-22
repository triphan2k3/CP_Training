#include <bits/stdc++.h>
#define TASK "1385C"
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
int a[N];
int main() {
    //freopen(TASK".INP","r",stdin);
    //freopen(TASK".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        FOR(i,1,n)
            cin >> a[i];
        int it=n;
        for (int i=n;i>=2;i--)
            if (a[i]<=a[i-1])
                it=i-1;
            else break;
        for (int i=it;i>=2;i--)
            if (a[i]>=a[i-1])
                it=i-1;
            else break;
        cout << it-1 << "\n";
    }
}
