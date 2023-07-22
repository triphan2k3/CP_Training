#include <bits/stdc++.h>
#define TASK "1537D"
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
int W[10000];
int cnt[N];
int main() {
    //freopen(TASK".INP","r",stdin);
    //freopen(TASK".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0); /*
    FOR(i,2,1000)
        FOR(j,2,i-1) {
            if( (i%j==0) && W[i-j]==0)
                W[i]=1;
            if (i%j==0)
                cnt[i]++;
        }
    FOR(i,1,1000)
        cout << W[i]<< " " << cnt[i]+2 << "\n"; */

    int t;
    cin >> t;
    while (t--) {
        int a;
        cin >> a;
        if (a%2==1) {
            cout << "Bob\n";
            continue;
        }
        int numlt2=0;
        while (a%2==0) {
            a/=2;
            numlt2++;
        }
        if (a!=1) {
            cout << "Alice\n";
            continue;
        }
        if (numlt2%2==0)
            cout << "Alice\n";

        else
            cout << "Bob\n";
    }


}
