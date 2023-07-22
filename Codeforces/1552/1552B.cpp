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

const int N=(int)5e4+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
int a[N][6];
int n;

int cmp(int i,int j) {
    if (i==j)
        return 1;
    int cnt=0;
    FOR(x,1,5)
        cnt+=a[i][x]<a[j][x];
    return cnt>=3 ? 1:0;
}
int main() {
    freopen(TASK".INP","r",stdin);
    //freopen(TASK".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        FOR(i,1,n)
            FOR(j,1,5)
                cin >> a[i][j];
        int ans=1;
        FOR(i,2,n) {
            if (cmp(ans,i)==0)
                ans=i;
        }
        int tmp=0;
        FOR(i,1,n)
            tmp+=cmp(ans,i);

        if (tmp==n)
            cout << ans << "\n";
        else
            cout <<"-1\n";
    }
}
