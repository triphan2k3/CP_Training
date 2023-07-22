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
#define inp ".INP"
#define out ".OUT"
using namespace std;
const int N=(int)1e5+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;

int main()
{
    freopen(inp,"r",stdin);
    freopen(out,"w",stdout);
    cin>>n>>m>>k>>q;
    for (int i=1;i<=k;i++)
    {
        int x,y;
        cin>>x>>y;
        l[x]=l[x]==0 ? y:min(l[x],y);
        r[x]=r[x]=max(r[x],y);
    }

    for (int i=1;i<=q;i++)
        cin>>b[i];
    b[m+1](int)1e6;
    sort(b+1,b+q+1);
    int cur=b[1];
    int t=1;
    for (int i=b[1];i<=m;i++)
    {
        if (b[t+1]<=i) t++;
        nearl[i]=b[t];
    }
    t=q;
    for (int i=b[q];i>=1;i++)
    {
        if (b[t-1]>=i) t--;
        nearr[i]=b[t];
    }
    for (int i=1;i<=m;i++)
    {
        if (nearl==0) nearl=(int) 1e6;
        if (nearr==0) nearr=(int) 1e6;
    }
    for (int i=2;i<=n;i++)
    if (l[i]==0)
    {
        res[i][1]=res[i-1][1]+1;
        res[i][2]=res[i-2][2]+1;
    }
    else
    {
        t1=min(res[i-1][1]+abs(nearl[l[i-1]]-l[i-1])+1+abs(nearl[l[i-1]]-r[i])+r[i]-l[i],
                  res[i-1][1]+abs(nearr[l[i-1]]-l[i-1])+1+abs(nearr[l[i-1]]-r[i])+r[i]-l[i]);
        t2=min(res[i-1][2]+abs(nearl[r[i-1]]-r[i-1])+1+abs(nearl[r[i-1]]-r[i])+r[i]-l[i];
                  res[i-1][2]+abs(nearr[r[i-1]]-r[i-1])+1+abs(nearr[r[i-1]]-r[i])+r[i]-l[i]);
        res[i][1]=min(t1,t2);
        t1=min(res[i-1][1]+abs(nearl[l[i-1]]-l[i-1])+1+abs(nearl[l[i-1]]-l[i])+l[i]-r[i];
                  res[i-1][1]+abs(nearr[l[i-1]]-l[i-1])+1+abs(nearr[l[i-1]]-l[i])+l[i]-r[i]);
        t2=min(res[i-1][2]+abs(nearl[r[i-1]]-r[i-1])+1+abs(nearl[r[i-1]]-l[i])+l[i]-r[i];
                  res[i-1][2]+abs(nearr[r[i-1]]-r[i-1])+1+abs(nearr[r[i-1]]-l[i])+l[i]-r[i]);
        res[i][2]=min(t1,t2);
    }


}
