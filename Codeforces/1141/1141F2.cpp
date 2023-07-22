#include <bits/stdc++.h>
#define TASK "1141F2"
#define pb push_back
#define ii pair<int,int>
#define iii pair<int,ii>
#define ll long long
#define F first
#define S second
#define FOR(i, a, b) for (int i=a; i<=b; i++)
#define FOr(i, a, b) for (int i=a; i<b ; i++)
#define FOD(i, a, b) for (int i=a; i>=b; i--)
#define FOd(i, a, b) for (int i=a; i>b ; i--)
using namespace std;

const int N=(int)1500+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
int a[N];
vector<ii> ans;
vector<iii> b;
int n;
int main() {
    //freopen(TASK".INP","r",stdin);
    //freopen(TASK".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    FOR(i,1,n) {
        cin >> a[i];
        a[i]+=a[i-1];
    }
    FOR(i,1,n) FOR(j,i,n)
        b.push_back({a[j]-a[i-1],{j,i}});
    sort(b.begin(),b.end());
    int l=0;

    FOr(i,0,b.size()) if (i+1==b.size() || b[i].F!=b[i+1].F) {
        vector<ii> c;
        FOR(j,l,i)
            if (c.empty() || c[c.size()-1].F < b[j].S.S)
                c.push_back(b[j].S);
        if (c.size() > ans.size())
            ans=c;
        l=i+1;
    }
    cout << ans.size() << "\n";
    FOr(i,0,ans.size())
        cout << ans[i].S << " " << ans[i].F << "\n";
}
