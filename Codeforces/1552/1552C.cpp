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
int e[N];
int havecut(ii x, ii y)
{
    if (x.F > x.S) swap(x.F, x.S);
    if (y.F > y.S) swap(y.F, y.S);
    if (x.F > y.F) swap(x, y);
    if (x.S > y.F && x.S < y.S) return 1;
    return 0;
}

int main()
{
    freopen(".INP","r",stdin);
    int t;
    cin >> t;
    while (t--)
    {
        int n,k;
        cin >> n >> k;
        vector<ii> a;
        FOR(i, 1, 2 * n) e[i] = 0;
        FOR(i,1,k)
        {
            int u,v;
            cin>>u>>v;
            a.push_back({u,v});
            e[u]=e[v]=1;
        }
        vector<int> v;
        FOR(i,1,2*n)
            if (e[i]==0) v.push_back(i);
        for (int i=0;i<v.size()/2;i++)
            a.push_back({v[i], v[i+v.size()/2]});
        int ans=0;
        if (a.size()>1)
        FOR(i,0,a.size()-2)
            FOr(j,i+1,(int)a.size())
                if (havecut(a[i], a[j]))
                    ans++;
        cout << ans << '\n';
    }
    return 0;
}
