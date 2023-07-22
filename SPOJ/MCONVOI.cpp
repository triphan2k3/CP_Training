#include <bits/stdc++.h>
#define X first
#define Y second
#define ll long long
#define ii pair<int,int>

using namespace std;
const int N=300005;
const int MOD=1000000007;
ii dp[N];
int a[N],g[N],s[N],b[N],n;
vector<int> len[N];
bool cmp(ii a,ii b)
{
    return (a.Y<b.Y)|| (a.Y==b.Y && a.X>b.X);
}

int get(int x)
{
    int res=0;
    while (x>0)
    {
        res=res+b[x];
        if (res>MOD) res-=MOD;
        x-=x&(-x);
    }
    return res;
}

void update(int x, int val)
{
    while (x<=n)
    {
        b[x]+=val;
        if (b[x]>MOD) b[x]-=MOD;
        if (b[x]<0) b[x]+=MOD;
        x+=x&(-x);
    }
}

int main()
{
    int t;
    //ifstream f ("test.inp");


    cin >> n;
    for (int i=1;i<=n;i++)
        cin >> dp[i].X >> dp[i].Y;

    sort(dp+1,dp+n+1,cmp);

    for (int i=1;i<=n;i++)
        dp[i].Y=i;
    sort(dp+1,dp+n+1);

    a[dp[1].Y]=1;
    for (int i=2;i<=n;i++)
        a[dp[i].Y]=(dp[i].X==dp[i-1].X) ? a[dp[i-1].Y]:i;
    int maxlen=0;
    for (int i=1;i<=n;i++)
    {
        s[i]=n+1;
        int temp=lower_bound(s,s+maxlen+1,a[i])-s;
        if (temp>maxlen)
        {
            maxlen++;
            s[maxlen]=a[i];
        }
        s[temp]=min(s[temp],a[i]);
        len[temp].push_back(i);
    }
    for (int i:len[1]) g[i]=1;
    for (int i=2;i<=maxlen;i++)
    {
        int f1=0,f2=0;
        while (f1<len[i-1].size() ||f2<len[i].size())
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
        for (int j:len[i-1]) update(a[j],-g[j]);
    }
    int res=0;
    for (int i:len[maxlen])
        res=(res+g[i])%MOD;
    cout << maxlen << "\n" << res;

}
