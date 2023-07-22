#include <bits/stdc++.h>
#define TASK ""
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
int a[N];
int main() {
    //freopen(TASK".INP","r",stdin);
    //freopen(TASK".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >>t;
    while (t--) {
        cin >> n;
        FOR(i,1,n)
            cin >> a[i];
        sort(a+1,a+n+1);
        int mi=a[2]-a[1];
        int id=2;
        FOR(i,2,n) {
            if (a[i]-a[i-1] < mi) {
                mi=a[i]-a[i-1];
                id=i;
            }
        }
        cout << a[id-1] << " ";
        FOR(i,id+1,n)
            cout << a[i] << " ";
        FOR(i,1,id-2)
            cout << a[i] << " ";
        cout << a[id];
        cout << "\n";

    }
}
