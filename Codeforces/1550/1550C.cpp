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
int a[N];
int check3(int a,int b,int c) {
    if (a<=b && b<=c)
        return 0;
    if (a>=b && b>=c)
        return 0;
    return 1;
}

int check4(int a,int b,int c,int d) {
    if (check3(a,b,c)==0)
        return 0;
    if (check3(a,b,d)==0)
        return 0;
    if (check3(a,c,d)==0)
        return 0;
    if (check3(b,c,d)==0)
        return 0;
    return 1;
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
        int n;
        cin >> n;
        FOR(i,1,n)
            cin >> a[i];
        int ans=n+n-1;
        FOR(i,1,n)
        FOR(j,3,4)
            if (i+j-1<=n) {
                if (j==3)
                    ans+=check3(a[i],a[i+1],a[i+2]);
                else
                    ans+=check4(a[i],a[i+1],a[i+2],a[i+3]);

            }
        cout << ans << "\n";
    }
}
