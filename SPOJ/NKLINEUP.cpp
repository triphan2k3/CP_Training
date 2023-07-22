#include <bits/stdc++.h>
using namespace std;
const int N=1e5;
int a[N];
int ma[N];
int mi[N];
int n;

int getmax(int l,int r)
{
    int res=a[r];
    while (l<=r)
    {
        int k=r-r&(-r);
        if (r-(r&(-r))<l-1)
            res=max(res,a[r--]);


        else
        {
            res=max(res,ma[r]);
            r-=r&(-r);
        }
    }
    return res;
}

int getmin(int l,int r)
{
    int res=a[r];
    while (l<=r)
    {
        if (r-(r&(-r))<l-1)
            res=min(res,a[r--]);

        else
        {
            res=min(res,mi[r]);
            r-=r&(-r);
        }
    }
    return res;
}

void updatemax(int x)
{
    int val=a[x];
    while (x<=n)
    {
        ma[x]=max(ma[x],val);
        x+=x&(-x);
    }
}

void updatemin(int x)
{
    int val=a[x];
    while (x<=n)
    {
        mi[x]=min(mi[x],val);
        x+=x&(-x);
    }
}

int main()
{
    int q;

    ifstream f ("test.inp");

    f >> n >> q;
    mi[0]=1e7;
    for (int i=1;i<=n;i++)
    {
        f >> a[i];
        ma[i]=0;
        mi[i]=1e7;
    }

    for (int i=1;i<=n;i++)
    {
        updatemax(i);
        updatemin(i);
    }

    for (int i=1;i<=q;i++)
    {
        int u,v;
        f >> u >> v;
        int res=getmax(u,v)-getmin(u,v);
        cout <<res << "\n";
    }
}
