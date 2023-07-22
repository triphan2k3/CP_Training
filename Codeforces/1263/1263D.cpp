/*
                                 _ _  _| _   |_     |_  _  _  _ |   _  _|_ _
                                (_(_)(_|(/_  |_)\/  | |(_)| |(_||\/(_|_|| (/_
                                                /             _| /
*/
#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define inp "1263D.INP"
#define out "1263D.OUT"
using namespace std;
const int N=(int)1e5+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
int n,ans;
int par[26],co[26];
int head(int i)
{
    return (par[i]<0 ? i:par[i]=head(par[i]));
}
void gop(int u,int v)
{
    int x=head(u);
    int y=head(v);
    if (x==y) return;
    if (par[x]>par[y]) swap(x,y);
    par[x]+=par[y];
    par[y]=x;
}
int main()
{
    freopen(inp,"r",stdin);
    freopen(out,"w",stdout);
    cin>>n;
    for (int i=0;i<26;i++)
        par[i]=-1;
    for (int i=1;i<=n;i++)
    {
        string s;
        cin>>s;
        co[s[0]-'a']=1;
        for (int j=1;j<s.size();j++)
        {
            co[s[j]-'a']=1;
            gop(s[j]-'a',s[j-1]-'a');
        }
    }
    for (int i=0;i<26;i++)
        if (par[i]<0 && co[i]) ans++;
    cout<<ans;
}
