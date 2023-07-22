#include <bits/stdc++.h>
#define TASK "375B"
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

const int N=(int)5e3+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
int a[N][N];
int b[N];
int n,m,ans;
int main() {
    //freopen(TASK".INP","r",stdin);
    //freopen(TASK".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    FOR(i,1,n) {
        string s;
        cin >> s;
        FOR(j,1,m)
            a[i][j]=s[j-1]-'0';
    }
    FOR(i,1,n) FOD(j,m,1)
        a[i][j]+= a[i][j] ? a[i][j+1]:0;
    FOR(j,1,m) {
        FOR(i,1,n)
            b[i]=a[i][j];
        sort(b+1,b+n+1);
        int l=1;
        FOR(i,1,b[n]) {
            while (b[l] < i)
                l++;
            ans=max(ans,(n-l+1)*i);
        }
    }
    cout << ans;
}
