#include <bits/stdc++.h>
#define TASK "1451C"
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
int cnt[10][100];
int solve(int k) {
    FOR(i,0,25) {
        if (cnt[1][i] < cnt[2][i])
            return 0;
        if (cnt[1][i] % k != cnt[2][i] % k)
            return 0;
        cnt[1][i+1]+=cnt[1][i]-cnt[2][i];
    }
    return 1;
}
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
        string a,b;
        cin >> a >> b;
        a=" "+a;
        b=" "+b;
        FOR(i,0,25)
            cnt[1][i]=cnt[2][i]=0;
        FOR(i,1,n) {
            cnt[1][a[i]-'a']++;
            cnt[2][b[i]-'a']++;
        }
        if (solve(k)) cout << "Yes\n";
        else cout << "No\n";

    }
}
