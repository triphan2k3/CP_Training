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
int a[N],ans[N];
int main() {
    //freopen(TASK".INP","r",stdin);
    //freopen(TASK".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while (t--) {
        cin >> n;
        FOR(i,1,n)
            ans[i]=0;
        vector<int> p;
        int last_fill=0;
        FOR(i,1,n) {
            cin >> a[i];
            if (a[i]==a[i-1]) continue;
            ans[i]=a[i];
            FOR(j,last_fill+1,a[i]-1)
                p.push_back(j);
            last_fill=a[i];
        }
        int pos_vector=0;
        FOR(i,1,n)
            if (!ans[i])
                ans[i]=p[pos_vector++];
        FOR(i,1,n) {
            cout << ans[i] << " ";
            ans[i]=(a[i]!=a[i-1]) ? a[i]:0;
        }
        cout << "\n";
        //-------------------
        p.clear();
        FOR(i,1,ans[1]-1)
            p.push_back(i);
        last_fill=1;
        FOR(i,2,n+1)
            if (ans[i] || i==n+1) {
                FOR(j,last_fill+1,i-1) {
                    ans[j]=p.back();
                    p.pop_back();
                }
                FOR(j,a[last_fill]+1,ans[i]-1)
                    p.push_back(j);
                last_fill=i;
            }
        FOR(i,1,n)
            cout << ans[i] << " ";
        cout << "\n";
    }
}
