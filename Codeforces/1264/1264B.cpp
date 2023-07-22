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
#define inp "1264B.INP"
#define out "1264B.OUT"
using namespace std;
const int N=300009;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
int a[N],ans[N],post[N];
int t,n;

int main()
{
    freopen(inp,"r",stdin);
    freopen(out,"w",stdout);
    cin>>t;
    while (t--)
    {
        cin>>n;
        for (int i=1;i<=n;i++)
        {
            cin>>a[i];
            post[a[i]]=i;
        }
        int l=post[1];
        int r=l;
        int now=1;
        ans[1]=ans[n]=1;
        for (int i=2;i<n;i++)
        {
            int nxt=post[i];
            if (nxt>r) r=nxt;
            if (nxt<l) l=nxt;
            if (r-l+1==i)
                ans[i]=1;
            else ans[i]=0;
        }
        for (int i=1;i<=n;i++)
            cout<<ans[i];
        cout<<"\n";
    }
}
