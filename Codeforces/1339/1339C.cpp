#include <bits/stdc++.h>
using namespace std;
const int N=100009;
int a[N],mi[N],ma[N],sum,n,t;
int main()
{
    freopen("1339C.INP","r",stdin);
    freopen("1339C.OUT","w",stdout);
    cin>>t;
    while (t--)
    {
        cin>>n;
        for (int i=1;i<=n;i++)
            cin>>a[i];
        ma[1]=a[1];
        for (int i=2;i<=n;i++)
            ma[i]=max(ma[i-1],a[i]);

        mi[n]=a[n];
        for (int i=n-1;i>=1;i--)
            mi[i]=min(mi[i+1],a[i]);

        sum=0;
        for (int i=1;i<n;i++)
            sum=max(sum,ma[i]-mi[i+1]);

        if (sum==0)
        {
            cout<<"0\n";
            continue;
        }
        for (int i=0;i<=31;i++)
        {
            sum-=1<<i;
            if (sum<=0)
            {
                cout<<i+1<<"\n";
                break;
            }
        }

    }
}
