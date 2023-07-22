#include <bits/stdc++.h>
using namespace std;
const int N=300000;
int a[N],b[N],l[N],r[N];
int all,ma,t,n;
int main()
{
    freopen("1330B.INP","r",stdin);
    freopen("1330B.OUT","w",stdout);
    cin>>t;
    while (t--)
    {
        cin>>n;
        for (int i=1;i<=n;i++)
            cin>>a[i];
        all=1;
        ma=0;
        for (int i=1;i<=n;i++)
        {
            b[a[i]]++;
            ma=max(ma,a[i]);
            if (b[a[i]]>1)
                all=0;
            l[i]=((ma==i) && all) ? 1:0;
        }
        for (int i=1;i<=n;i++)
            b[i]=0;
        ma=0;
        all=1;
        for (int i=n;i>=1;i--)
        {
            b[a[i]]++;
            ma=max(ma,a[i]);
            if (b[a[i]]>1)
                all=0;
            r[i]=((ma==n-i+1) && all) ? 1:0;
        }
        int ans=0;
        for (int i=1;i<n;i++)
            if (l[i] & r[i+1]) ans++;
        cout<<ans<<"\n";
        for (int i=1;i<n;i++)
            if (l[i] & r[i+1])
                cout<<i<<" "<<n-i<<"\n";
        for (int i=1;i<=n;i++)
            b[i]=0;
    }
}
