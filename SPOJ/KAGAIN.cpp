#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define inp "KAGAIN.INP"
#define out "KAGAIN.OUT"
using namespace std;
const int N=(int)1e5+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
int a[N],l[N],r[N],st[N];
int main()
{
    freopen(inp,"r",stdin);
    freopen(out,"w",stdout);
    int t,n,top;
    cin>>t;
    while (t--)
    {
        cin>>n;
        for (int i=1;i<=n;i++)
            cin>>a[i];
        top=0;
        for (int i=1;i<=n;i++)
        {
            while (top>0 && a[st[top]]>=a[i])
                top--;
            l[i]=st[top]+1;
            st[++top]=i;
        }
        top=0;
        for (int i=n;i;i--)
        {
            while (top>0 && a[st[top]]>=a[i])
                top--;
            r[i]=(top==0) ? n:st[top]-1;
            st[++top]=i;
        }
        int ft=0,ma=0,lt;
        for (int i=1;i<=n;i++)
        {
            int t=a[i]*(r[i]-l[i]+1);
            if (t>ma)
            {
                ma=t;
                ft=l[i];
                lt=r[i];
            }
            else if (t==ma && l[i]<ft)
            {
                ft=l[i];
                lt=r[i];
            }
        }
        cout<<ma<<char(32)<<ft<<char(32)<<lt<<"\n";
    }
}
