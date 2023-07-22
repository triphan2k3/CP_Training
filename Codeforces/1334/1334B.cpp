#include <bits/stdc++.h>
using namespace std;
long long n,x,t,ans;
long long a[200000];

int main()
{
    freopen("1334B.INP","r",stdin);
    freopen("1334B.OUT","w",stdout);
    cin>>t;
    while (t--)
    {
        cin>>n>>x;
        for (int i=1;i<=n;i++)
            cin>>a[i];
        sort(a+1,a+n+1);
        reverse(a+1,a+n+1);
        long long sum=0;
        for (long long i=1;i<=n;i++)
        {
            sum=sum+a[i];
            if (sum>=x*i) ans=i;
            else break;
        }
        cout<<ans<<"\n";
        ans=0;
    }
}
