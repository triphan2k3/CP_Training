#include <bits/stdc++.h>
#define TASK ""
#define pb push_back
#define F first
#define S second
#define FOR(i, a, b) for (int i=a; i<=b; i++)
#define FOr(i, a, b) for (int i=a; i<b ; i++)
#define FOD(i, a, b) for (int i=a; i>=b; i--)
#define FOd(i, a, b) for (int i=a; i>b ; i--)
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef vector<int> vi;

const int N=1e6+7;
const int MOD=1e9+7;
const ll INF=(ll)1e18+7;
int n;
int a[N],big[N];
int main() {
    #ifdef TriPhan
        freopen("TEST.INP","r",stdin);
        freopen("TEST.OUT","w",stdout);
    #else
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    #endif
    cin >> n;
    FOR(i,1,n)
        cin >> a[i];
    int ans = 0;
    FOD(Bit,19,0) {
        FOR(i,1,n)
            if (a[i] & (1<<Bit))
                big[i] = max(big[i],Bit);
        int l = 1, r = 1;
        while (l<=n) {
            while(big[l] > Bit && l<=n) l++;
            if (l>n) break;
            r = l;
            int cnt = big[l]==Bit;
            int l2 = cnt*l;
            while (big[r+1] <= Bit && r<n) {
                r++;
                cnt+= (big[r] == Bit);
                if (cnt%2==0 && cnt>0) 
                    ans = max(ans,r-l+1);
                if (cnt%2==1 && l2==0) 
                    l2=r;
                if (cnt%2==1 && cnt > 2)
                    ans = max(ans,r-l2);
            }
            l = r+1;
        }
    }
    cout << ans;
}