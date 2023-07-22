#include <bits/stdc++.h>
#define task "1330A"

using namespace std;
int a[10000],n,t,x;
int main()
{
    freopen("1330A.INP","r",stdin);
    freopen("1330A.OUT","w",stdout);
    cin>>t;
    while (t--)
    {
        for (int i=1;i<=1000;i++)
            a[i]=0;
        cin>>n>>x;
        for (int i=1;i<=n;i++)
        {
            int x;
            cin>>x;
            a[x]=1;
        }
        int p=1;
        while (x)
        {
            if (a[p]==0) x--;
            if (x!=0) p++;
        }
        int ans=p++;
        while (a[p])
        {
            ans=p;
            p++;
        }
        cout<<ans<<"\n";
    }
}
