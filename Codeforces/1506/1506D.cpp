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
int n;

int main() {
    //freopen(TASK".INP","r",stdin);
    //freopen(TASK".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin>> n;
        FOR(i,1,n)
            cin >> a[i];
        sort(a+1,a+n+1);
        a[n+1]=0;
        int cntmax=1;
        int ans=n%2;
        int nowcnt=1;

        FOR(i,1,n)
            if (a[i]==a[i+1]) {
                nowcnt++;
                cntmax=max(nowcnt,cntmax);
            } else nowcnt=1;

        cout << max(ans,cntmax-(n-cntmax)) << "\n";
    }
}
