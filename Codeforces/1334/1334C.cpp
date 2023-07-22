#include <bits/stdc++.h>
using namespace std;
const int N=300009;
long long a[N],b[N],c[N],p[N];
long long ans;
int n,t;
int main()
{
    freopen("1334C.INP","r",stdin);
    freopen("1334C.OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while (t--)
    {
        cin>>n;
        for (int i=1;i<=n;i++)
            cin>>a[i]>>b[i];
        b[0]=b[n]; a[0]=a[n];
        for (int i=1;i<=n;i++)
            c[i]=(a[i]-b[i-1] > 0) ? a[i]-b[i-1]:0;
        p[n+1]=0;
        for (int i=n;i>=1;i--)
            p[i]=p[i+1]+c[i];
        long long ans=a[1]+p[2];
        for (int i=1;i<=n;i++)
            ans=min(ans,a[i]+p[i+1]+p[1]-p[i]);
        cout<<ans<<"\n";
    }
}
