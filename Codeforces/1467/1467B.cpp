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
int a[N],ck[N];
int n;
int check(int i,int j,int k) {
    if (i<1)
        return 0;
    if (k>n)
        return 0;
    if (a[j]<a[i] && a[j]<a[k])
        return 1;
    if (a[j]>a[i] && a[j]>a[k])
        return 1;
    return 0;
}
int main() {
    //freopen(TASK".INP","r",stdin);
    //freopen(TASK".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >>t;
    while (t--) {
        int ans=0;
        cin >> n;
        FOR(i,1,n) {
            ck[i]=0;
            cin >> a[i];
        }
        FOr(i,2,n) {
            ck[i]=check(i-1,i,i+1);
            ans+=ck[i];
        }

        int dec=0;
        FOR(i,2,n-1) {
            //ai=ai+1 -> ai+1 false ai false
            int state = (check(i-2,i-1,i+1));
            dec=max(dec,ck[i-1]+ck[i]+ck[i+1] - state);
            //ai = ai-1 -> ai-1 false ai false
            state=check(i-1,i+1,i+2);
            dec=max(dec,ck[i-1]+ck[i]+ck[i+1] - state);
        }
        cout << ans-dec << "\n";
    }
}
