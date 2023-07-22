
#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define inp "SHTH.INP"
#define out "SHTH.OUT"
using namespace std;
const int N=(int)1e5+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
struct bignum
{
    int en;
    int so[2000];
};
bignum f[301][301];
bignum def;
int a[301];
int b[301];
int used[301];

bignum operator + (bignum a, bignum b)
{
    while (a.en<b.en) a.en++;
    while (a.en>b.en) b.en++;
    int now=0;
    bignum res=def;
    for (int i=0;i<=a.en;i++)
    {
        now+=a.so[i]+b.so[i];
        res.so[i]=now%10;
        now/=10;
    }
    res.en=a.en;
    if (now==1) res.so[++res.en]=1;
    return res;
}
bignum operator - (bignum a, bignum b)
{
    while (a.en<b.en) a.en++;
    while (b.en<a.en) b.en++;
    int now=0,car=0;;
    bignum res=def;
    for (int i=0;i<=a.en;i++)
    {
        now=a.so[i]-b.so[i]-car;
        if (now<0)
        {
            now+=10;
            car=1;
        } else car=0;
        res.so[i]=now;
    }
    res.en=a.en;
    while (res.so[res.en]==0 && res.en>0) res.en--;
    return res;
}

bool operator < (bignum a,bignum b)
{
    if (a.en!=b.en) return a.en<b.en;
    for (int i=a.en;i>=0;i--)
        if (a.so[i]!=b.so[i]) return a.so[i]<b.so[i];
    return 0;
}

bignum str2big(string s)
{
    bignum res=def;
    res.en=s.size()-1;
    for (int i=0;i<=res.en;i++)
        res.so[i]=s[res.en-i]-48;
    return res;
}
void write(bignum a)
{
    for (int i=a.en;i>=0;i--)
        cout<<a.so[i];
}
int main()
{
    //freopen(inp,"r",stdin);
    //freopen(out,"w",stdout);
    int n,k;
    string s;
    cin>>n>>k;
    cin>>s;
    for (int i=1;i<=k;i++)
        cin>>a[i];
    f[0][0]=str2big("1");
    for (int i=1;i<=n;i++)
        for (int j=0;j<=i;j++)
            f[j][i]= (j==0 || i==j) ? str2big("1"):f[j-1][i-1]+f[j][i-1];



    bignum res=str2big("1");
    for (int i=1;i<=k;i++)
    {
        for (int j=a[i-1]+1;j<a[i];j++)
        if (!used[j])
            res=res+f[k-i][n-j];
        used[a[i]]=1;
    }
    bignum r=str2big(s);
    for (int i=1;i<=n;i++) used[i]=0;
    for (int i=1;i<=k;i++)
    {
        int j=b[i-1]+1;
        for (;j<=n-k+i;j++)
        if (f[k-i][n-j]<r)
            r=r-f[k-i][n-j];
        else break;
        b[i]=j;
        cout<<j<<" ";
    }
    cout<<"\n";
    write(res);
}
