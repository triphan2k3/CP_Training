#include <bits/stdc++.h>
#define TASK "1333D"
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
int main() {
    freopen(TASK".INP","r",stdin);
    freopen(TASK".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,k;
    cin >> n >> k;
    string s; cin >> s;
    vector<int> a(n+1,0);
    vector<int> ans[n+1];
    FOr(i, 0, n)
        a[i+1] = (s[i] == 'L') ? -1:1;
    int sec=0,sumsz=0;
    for (int i=1;;i++) {
        for (int j=1;j<n;j++)
            if (a[j]==1 && a[j+1]==-1)
                ans[i].pb(j);
        if (ans[i].size()==0) {
            sec=i-1;
            break;
        }
        sumsz+=ans[i].size();
        for (int j:ans[i])
            swap(a[j],a[j+1]);
    }
    if (sumsz<k || sec > k) {
        cout<<-1;
        return 0;
    }
    int l=1,r=0,need=k-sec;
    for (;need;) {
        need--;
        cout<<1<<" "<<ans[l][r++]<<"\n";
        if (r==ans[l].size()) {
            ++l;
            need++;
            r=0;
        }
    }
    cout<< ans[l].size()-r;
    for (int j=r;j<ans[l].size();j++)
        cout << " " << ans[l][j];

    for (int i=l+1;i<=sec;i++) {
        cout << "\n" << ans[i].size();
        for (int j=0;j<ans[i].size();j++)
            cout << " " << ans[i][j];
    }

}
