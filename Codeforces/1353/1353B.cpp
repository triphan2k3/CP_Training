#include <bits/stdc++.h>
#define TASK "1353B"
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
int main() {
    //freopen(TASK".INP","r",stdin);
    //freopen(TASK".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n,k;
        cin >> n >> k;
        vector<ii> a(n*2);
        FOr(i,0,n) {
            cin >> a[i].F;
            a[i].S=0;
        }
        FOr(i,n,2*n) {
            cin >> a[i].F;
            a[i].S=1;
        }
        sort(a.begin(),a.end());
        reverse(a.begin(),a.end());
        int sum=0,nn=2*n;
        FOr(i,0,nn) {
            if (a[i].S && k) {
                sum+=a[i].F;
                k--;
                n--;
            }
            if (a[i].S==0) {
                sum+=a[i].F;
                n--;
            }
            if (n==0) break;
        }
        cout << sum << "\n";
    }
}
