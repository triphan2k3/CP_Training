#include <bits/stdc++.h>
#define TASK "1463B"
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

int n;
ll a[100];
ll sum[2];
int main() {
    //freopen(TASK".INP","r",stdin);
    //freopen(TASK".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while (t--) {
        cin >> n;
        sum[0]=sum[1]=0;
        FOR(i,1,n) {
            cin >> a[i];
            sum[i%2]+=a[i];
        }
        if (n==1) {
            cout << a[1] << "\n";
            continue;
        }
        int kt=1;
        if (sum[0]<sum[1]) kt=0;

        for (int i=1;i<=n;i++)
            if (i%2==kt)
                cout << 1  << " ";
            else
                cout <<a[i]<< " ";
        cout << "\n";
    }
}
