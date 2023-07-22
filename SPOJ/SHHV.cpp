#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define inp "SHHV.INP"
#define out "SHHV.OUT"
using namespace std;
const int N=(int)1e5+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;

int hv[13];
int a[13];
int n;
int t;
int used[13];
int b[13];

void init()
{
    hv[0]=1;
    for (int i=1;i<=12;i++)
        hv[i]=hv[i-1]*i;
}

int solve1()
{
    int res=0;
    for (int i=1;i<=n;i++)
    {
        used[a[i]]=1;
        int k=0;
        for (int j=1;j<a[i];j++)
            if (!used[j]) k++;
        res+=hv[n-i]*k;
    }
    return res+1;
}
void solve2()
{
    for (int i=1;i<=12;i++) used[i]=0;

    for (int i=1;i<=n;i++)
    {
        int j=1;
        int k=1;
        while (t-hv[n-i]>0)
        {
            k++;
            t-=hv[n-i];
        }
        for (;k>0;)
            if (!used[j++]) k--;
        b[i]=--j;
        used[j]=1;
    }
}
int main()
{
    freopen(inp,"r",stdin);
    freopen(out,"w",stdout);
    char c;
    scanf("%c",&c);
    init();
    while (c!='\n')
    {
        if (c=='1')
        {
            scanf("%c",&c);
            if (c==' ')
                a[++n]=1;
            else a[++n]=10+c-48;
        }
        else if (c!=' ') a[++n]=c-48;
        if (c!='\n') scanf("%c",&c);
    }
    cin>>t;
    cout<<solve1()<<"\n";
    solve2();
    for (int i=1;i<=n;i++)
        cout<<b[i]<<" ";

}
