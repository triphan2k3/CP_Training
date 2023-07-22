#include <bits/stdc++.h>

#define ll long long
#define ii pair<int,int>
#define X first
#define Y second

using namespace std;
const int MOD=1000000007;
const int N=1e5+2;
ii dp[N];
int b[N],ff[N],a[N],c[N],n,g[N],s[N];
vector<int> len[N];
void update(int x,int val)
{
    while (x<=n)
    {
        b[x]+=val;
        if (b[x]>MOD) b[x]-=MOD;
        if (b[x]<0)   b[x]+=MOD;
        x+=x&(-x);
    }
}
int get(int x)
{
    int res=0;
    while (x>0)
    {
        res+=b[x];
        if (res>MOD) res-=MOD;
        x-=x&(-x);
    }
    return res;
}
int getmax(int x)
{
    int res=0;
    while (x>0)
    {
        res=max(res,c[x]);
        x-=x&(-x);
    }
    return res;
}
void updatemax(int x, int val)
{
    while (x<=n)
    {
        c[x]=max(c[x],val);
        x+=x&(-x);
    }
}
bool cmp(ii a, ii b)
{
    return (a.X<b.X) || (a.X==b.X && a.Y>b.Y);
}
int main()
{
    //ifstream f ("test.inp");
    cin >> n;
    for (int i=1;i<=n;i++)
    {
        dp[i].Y=i;
        cin >> dp[i].X;
    }
    sort(dp+1,dp+n+1,cmp);
    int t=0;
    //a[0]=-MOD;
    a[dp[1].Y]=1;
    for (int i=2;i<=n;i++)

        a[dp[i].Y]=(dp[i].X!=dp[i-1].X) ? i:(a[dp[i-1].Y]);

    int maxl=0;
    for (int i=1;i<=n;i++)
    {
        s[i]=n+100;
        int temp=lower_bound(s,s+maxl+1,a[i])-s;
        ff[i]=temp;
        len[temp].push_back(i);
        if (temp>maxl)
        {
            maxl++;
            s[maxl]=a[i];
        }
        s[temp]=min(s[temp],a[i]);

    }

    for (int i=0;i<len[1].size();i++) g[len[1][i]]=1;
    for (int i=2;i<=maxl;i++)
    {
        int f1=0,f2=0;
        while (f1<len[i-1].size() || f2<len[i].size())
        {
            if (f2==len[i].size() || (f1<len[i-1].size() && len[i-1][f1]<len[i][f2]))
                {
                    update(a[len[i-1][f1]],g[len[i-1][f1]]);
                    f1++;
                }
            else
                {
                    g[len[i][f2]]=get(a[len[i][f2]]-1);
                    f2++;
                }
        }
            for (auto j:len[i-1]) update(a[j],-g[j]);

    }
    int res=0;
    for (int i=1;i<=n;i++)
      if (ff[i]==maxl) res=(res+g[i])%MOD;
    cout << res;
}
