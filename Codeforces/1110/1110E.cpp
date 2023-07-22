#include <bits/stdc++.h>
#define TASK "1110E"
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

const int N=(int)1e5+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
int a[N],b[N];
int main() {
    //freopen(TASK".INP","r",stdin);
    //freopen(TASK".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    FOR(i,1,n)
        cin >> a[i];
    FOR(i,1,n)
        cin >> b[i];

    if (a[1]!=b[1] || a[n]!=b[n]) {
        cout << "No";
        return 0;
    }
    FOD(i,n,2) {
        a[i]-=a[i-1];
        b[i]-=b[i-1];
    }

    sort(a+2,a+n+1);
    sort(b+2,b+n+1);

    FOR(i,2,n)
        if (a[i]!=b[i]) {
            cout << "No";
            return 0;
        }
    cout << "Yes";
}
