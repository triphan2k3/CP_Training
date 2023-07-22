#include <bits/stdc++.h>
using namespace std;

vector<int> a[400000],ans;
int n;
int dfs(int u,int p)
{
    int c0=0;
    int c1=0;
    for (int i=0;i<a[u].size();i++)
    {
        int v=a[u][i];
        if (v!=p)
        {
            int k=dfs(v,u);
            if (k==2) return 2;
            if (k==1) c1=1;
            if (k==0) c0=1;
        }
    }
    if (c1 & c0) return 2;
    if (c0) return 1;
    return 0;
}
int main()
{
    freopen("1339D.INP","r",stdin);
    freopen("1339D.OUT","w",stdout);
    cin>>n;
    for (int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    int r=0;
    for (int i=1;i<=n;i++)
        if (a[i].size()==1) r=i;
    if (dfs(r,0)!=0) cout<<"3 "; else cout<<"1 ";
    for (int i=1;i<=n;i++)
        if (a[i].size()==1) ans.push_back(a[i][0]);
    sort(ans.begin(),ans.end());
    int sub=0;
    for (int i=1;i<ans.size();i++)
        if (ans[i]==ans[i-1]) sub++;
    cout<<n-1-sub;
}
