#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N=300000;
int n,m,a[N],ans[N];
int main()
{
    cin>>n>>m;
    for (int i=1;i<=m;i++)
        cin>>a[i];
    int last=n;
    for (int i=m;i>=1;i--) {
        int k=max(last-a[i],i);
        if (k<i || k>n-a[i]+1)
        {
            cout<<-1;
            return 0;
        }
        last=k;
        ans[i]=k;
    }
    if (last>1)
    {
        cout<<-1;
        return 0;
    }
    for (int i=1;i<=m;i++)
        cout<<ans[i]<<' ';
}
