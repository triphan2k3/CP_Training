#include <bits/stdc++.h>
#define TASK "hack"
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
vector<int> e[N];
int q[N],a[N],Left[N],Right[N],QLeft[N],QRight[N],cnt[N],ans[N];
int m,n;
int main() {
    //freopen(".INP","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    FOR(i,1,n)
        cin >> a[i];
    FOR(i,1,m) {
        int u;
        cin >> u >> q[i];
        e[u].push_back(i);
    }
    vector<int> s;
    FOR(i,1,n) {
        int it=lower_bound(s.begin(),s.end(),a[i])-s.begin();
        Left[i]=it+1;
        for (int id:e[i]) {
            int val=q[id];
            QLeft[id]=1+lower_bound(s.begin(),s.end(),val)-s.begin();
        }
        if (it==s.size())
            s.push_back(a[i]);
        s[it]=min(s[it],a[i]);

    }
    int maxlis=s.size();
    s.clear();
    FOD(i,n,1) {
        int it=lower_bound(s.begin(),s.end(),-a[i])-s.begin();
        Right[i]=it+1;
        for (int id:e[i]) {
            int val=-q[id];
            QRight[id]=1+lower_bound(s.begin(),s.end(),val)-s.begin();
        }
        if (it==s.size())
            s.push_back(-a[i]);
        s[it]=min(s[it],-a[i]);

    }
    FOR(i,1,n)
        if (Left[i]+Right[i]-1==maxlis)
            cnt[Left[i]]++;
    FOR(i,1,n)
        for(int id:e[i]) {
            int tmp=QLeft[id]+QRight[id]-1;
            ans[id]=tmp;
            if (Left[i]+Right[i]-1==maxlis && cnt[Left[i]]==1)
                ans[id]=max(ans[id],maxlis-1);
            else
                ans[id]=max(ans[id],maxlis);
        }
    FOR(i,1,m)
        cout << ans[i]<<"\n";
}
