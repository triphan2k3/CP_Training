#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define inp "MSE08G.INP"
#define out "MSE08G.OUT"
using namespace std;
const int N=(int)1e5+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e12;
vector<long long> a,ans;

void prepare(long long n)
{
    if (n>INF) return;
    if (n>0) a.push_back(n);
    prepare(n*10ll+4ll);
    prepare(n*10ll+7ll);
}
void dfs(long long n,int pos)
{
    if (n>INF) return;
    if (n>1) ans.push_back(n);
    for (int i=pos;i<a.size();i++)
        if (INF/n<a[i]) return;
            else dfs(n*a[i],i);
}
int main()
{
    freopen(inp,"r",stdin);
    freopen(out,"w",stdout);
    prepare(0);
    sort(a.begin(),a.end());
    dfs(1,0);
    sort(ans.begin(),ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    int t;
    cin>>t;

    while (t--)
    {
        ll a,b;
        cin>>a>>b;
        int st=upper_bound(ans.begin(),ans.end(),a-1)-ans.begin()-1;
        int nd=upper_bound(ans.begin(),ans.end(),b)-ans.begin()-1;
        cout<<nd-st<<"\n";
    }
}
