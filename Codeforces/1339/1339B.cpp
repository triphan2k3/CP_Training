#include <bits/stdc++.h>
using namespace std;
const int N=100009;
int a[N],b[N],n,l,r,t;
int main()
{
    freopen("1339B.INP","r",stdin);
    freopen("1339B.OUT","w",stdout);
    cin>>t;
    while (t--)
    {
        cin>>n;
        for (int i=1;i<=n;i++)
            cin>>a[i];
        sort (a+1,a+n+1);
        l=1; r=n;
        int u=1;
        while (r>l)
        {
            b[u++]=a[r];
            b[u++]=a[l];
            r--;
            l++;
        }
        if (r==l) b[u]=a[r];
        for (int i=n;i>=1;i--)
            cout<<b[i]<<" ";
        cout<<"\n";
    }
}
