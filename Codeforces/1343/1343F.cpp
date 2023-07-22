#include <bits/stdc++.h>
#define TASK "1343F"
#define pb push_back
#define ii pair<int,int>
#define ll long long
#define F first
#define S second
#define FOR(i, a, b) for (int i=a; i<=b; i++)
#define FOr(i, a, b) for (int i=a; i<b ; i++)
#define FOD(i, a, b) for (int i=a; i>=b; i--)
#define FOd(i, a, b) for (int i=a; i>b ; i--)
using namespace std;
const int N=209;
int a[N][N], b[N][N];
int ft[N], sz[N], ok[N], cnt[N];;
vector<int> ans;
vector<ii> can;
int t,n;

void n_2() {
    freopen(TASK".INP","r",stdin);
    freopen(TASK".OUT","w",stdout);
    cin>>t;
    while(t--) {
        cin>>n;
        FOR(i,1,n-1) {
            int l;
            cin>>l;
            a[i][0]=l;
            FOR(j, 1, l) {
                int u;
                cin>>u;
                ++cnt[u];
                a[i][u]=1;
            }
        }
        vector<int> try_;
        FOR(i,1,n)
            if (cnt[i]==1) try_.pb(i);
        for(int vlast:try_) {
            vector<int> ans(n);
            vector<int> used(n+1,0);
            int pnow;
            FOR(i, 1, n) cnt[i]=ft[i]=0;
            FOR(i,1,n)
                FOR(j,1,n)
                    if (a[i][j]) cnt[j]++;

            FOD(i, n-2, 1) {
                ans[i+1]=vlast;
                FOR(j, 1, n-1)
                    if (a[j][vlast]==1 && !ok[j])
                        pnow=j;
                ok[pnow]=1;
                used[pnow]=1;

                FOR(j, 1, n)
                    if (a[pnow][j]) {
                        cnt[j]--;
                        if (cnt[j]==1) vlast=j;
                        ft[j]=max(ft[j],i+2-a[pnow][0]+1);
                    }

            }
            FOR(i, 1, n-1)
                if (used[i] == 0 && a[i][0]!=2) continue;
            FOR(i, 1, n-1)
                ok[ans[i]]=2;
            vector<int> tp;
            FOR(i, 1, n)
                if (ok[i]!=2) tp.pb(i);
            ans[1]=tp[1];
            ans[0]=tp[0];
            if (ft[tp[0]] > 1) ans[1]=tp[0] ,ans[0]=tp[1];
            FOR(i, 0, n-1)
                cout<<ans[i]<<" ";
            cout<< "\n";
            FOR(i, 1, n)
                cnt[i]=ft[i]=ok[i]=0;
            FOR(i, 0, n)
                FOR(j, 1, n)
                    a[i][j]=0;
            break;
        }
    }
}
//n_2 ngu lon nen la sai roi !!
int main() {
    freopen(TASK".INP","r",stdin);
    freopen(TASK".OUT","w",stdout);
    cin>>t;
    while(t--) {
        cin>>n;
        FOR(i,1,n-1) {
            int l;
            cin>>l;
            a[i][0]=l;
            sz[i]=l;
            FOR(j, 1, l) {
                int u;
                cin>>u;
                if (l==2) can.pb({u,i});
                a[i][u]=1;
            }
        }
        FOR(i,0,n)
            FOR(j,0,n)
                b[i][j]=a[i][j];
        FOR(x,0,can.size()-1) {
            FOR(i, 1, n-1)
                ft[i]=0;
            int val=can[x].F;
            int fp=can[x].S;
            FOR(i,0,n)
            FOR(j,0,n)
                a[i][j]=b[i][j];
            ans.clear();
            ans.pb(val);
            vector<int> nxt;
            //ans.pb(val2);
            FOR(now, 2, n) {
                nxt.clear();
                FOR(i, 1, n-1)
                    if (a[i][val]) {
                        a[i][val]=0;
                        a[i][0]--;
                        if (a[i][0]==1) nxt.pb(i);
                        if (!ft[i]) ft[i]=now-1;
                    }
            if (nxt.size() == 0 || nxt.size() >1) break;
            fp=nxt[0];
            if (sz[fp] != now - ft[fp] + 1) break;
            FOR(j, 1, n)
                if (a[fp][j]==1) val=j;
            ans.pb(val);
            }
            if (ans.size()==n) break;
        }
        FOR(i, 0, n)
            FOR(j, 0, n)
                a[i][j]=0;
        FOR(i, 0, n-1)
            cout << ans[i] << " ";
        cout<<"\n";
    }
}
