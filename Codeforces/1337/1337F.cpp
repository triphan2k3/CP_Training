#include <bits/stdc++.h>
#define inp "1337F.INP"
#define out "1337F.OUT"
using namespace std;
const int N=107;
int a[N],b[N],gt[N],ans[N],val[N*N*N];
int cnt[N],aa,bb;
int n,x,y,t;
void checker()
{
    aa=bb=0;
    for (int i=1;i<=n;i++)
    {
        aa+=cnt[i]*(cnt[i]-1)*(cnt[i]-2);
        bb+=cnt[i]*cnt[i+1]*cnt[i+2];
    }
    aa/=6;
    cout<<aa<<" "<<bb<<"\n";
}
void admin()
{
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>cnt[i];
    checker();
    for (int i=1;i<n;i++)
    {
        cnt[i]++;
        checker();
    }
    cnt[1]++;
    checker();
}
int main()
{
    freopen(inp,"r",stdin);
    freopen(out,"w",stdout);

    //admin(); return 0;
    cin>>n;
    cin>>a[0]>>b[0];
    for (int i=3;i<=n+2;i++)
        gt[i]=i*(i-1)*(i-2)/6;

    for (int i=3;i<=n+2;i++)
        val[gt[i]-gt[i-1]]=i;

    for (int i=1;i<=n-1;i++)
    {
        cout<<"+ "<<i<<"\n";
        cout.flush();
        cin>>a[i]>>b[i];
    }

    cout<<"+ 1\n";
    cout.flush();
    cin>>a[n]>>b[n];
    for (int i=n;i>=1;i--)
    {
        a[i]-=a[i-1];
        b[i]-=b[i-1];
    }
    ans[1]=max(val[a[n]]-2,0);

    if (b[1]==0)
    {
        if (b[1]==b[2]) ans[3]=0,ans[2]=b[n]-1;
            else ans[3]=b[n]-1,ans[2]=0;

    }
    else if (b[n]==4) ans[2]=ans[3]=1;
    else
    {
        ans[2]=(a[2]>0) ? val[a[2]]-1 : 0;
        ans[3]=(a[3]>0) ? val[a[3]]-1 : 0;
        if (ans[2]==0) ans[2]=b[1]/ans[3];
        else ans[3]=b[1]/ans[2];
    }
    int pre=(ans[1]+1)*(ans[2]+1);
    for (int i=4;i<n;i++)
    {

        if (a[i]>0)
            ans[i]=val[a[i]]-1;
        else
            ans[i]=(pre<b[i-1]) ? 1:0;
        pre=(ans[i-1]+1)*(ans[i-2]+1);
    }
    ans[n]=(b[n-1]-(ans[n-3]+1)*(ans[n-2]+1))/(ans[n-2]+1);
    cout<<"!";
    for (int i=1;i<=n;i++)
        cout<<" "<<ans[i];
}

