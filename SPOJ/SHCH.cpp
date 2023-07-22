
#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define inp "SHCH.INP"
#define out "SHCH.OUT"
using namespace std;
const int N=(int)1e5+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
struct bignum
{
    int en;
    int so[1000];
};
bignum f[301];
bignum def;
int a[301];
int used[301];

bignum operator +(bignum a,bignum b)
{
    while (a.en<b.en) a.en++;
    while (b.en<a.en) b.en++;
    int now=0;
    bignum res=def;
    for (int i=0;i<=a.en;i++)
    {
        now+=a.so[i]+b.so[i];
        res.so[i]=now%10;
        now/=10;
    }
    if (now!=0)
    {
        res.en=a.en+1;
        res.so[res.en]=1;
    } else res.en=a.en;
    return res;
}
bignum operator -(bignum a,bignum b)
{
    while (a.en<b.en) a.en++;
    while (b.en<a.en) b.en++;
    int now=0,c=0;
    bignum res=def;
    for (int i=0;i<=a.en;i++)
    {
        now=a.so[i]-b.so[i]-c;
        if (now<0)
        {
            now+=10;
            c=1;
        } else c=0;
        res.so[i]=now;
    }
    res.en=a.en;
    while (res.en>0 && res.so[res.en]==0)
        res.en--;
    return res;
}

bignum operator *(bignum a,bignum b)
{
    bignum res=def;
    int now=0;
    for (int i=0;i<=a.en+b.en;i++)
    {
        int fir=max(0,i-b.en);
        int las=min(i,a.en);
        for (int j=fir;j<=las;j++)
            now+=a.so[j]*b.so[i-j];
        res.so[i]=now%10;
        now/=10;
    }
    res.en=a.en+b.en;
    if (now>0)
        res.so[++res.en]=now;

    while (res.en>0 && res.so[res.en]==0)
        res.en--;
    return res;
}
bool operator < (bignum a,bignum b)
{
    if (a.en!=b.en)
        return a.en<b.en;
    for (int i=a.en;i>=0;i--)
        if (a.so[i]!=b.so[i]) return a.so[i]<b.so[i];
    return 0;
}
bignum str2big(string s)
{
    bignum res=def;
    res.en=s.size()-1;
    for (int i=0;i<s.size();i++)
        res.so[res.en-i]=s[i]-48;
    return res;
}
bignum int2big(int a)
{
    bignum res=def;
    if (a==0) return res;
    res.en=-1;
    while (a!=0)
    {
        res.so[++res.en]=a%10;
        a/=10;
    }
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
    cin>>n>>k;

    string s;
    cin>>s;

    for (int i=1;i<=n;i++)
        cin>>a[i];

    f[0]=str2big("1");
    for (int i=1;i<=k;i++)
        f[i]=f[i-1]*int2big(n-k+i);

    bignum res=int2big(0);
    for (int i=1;i<=k;i++)
    {
        int t=0;
        for (int j=1;j<a[i];j++)
            if (!used[j]) t++;

        res=res+(int2big(t)*f[k-i]);
        used[a[i]]=1;
    }
    bignum r=res+int2big(1);
    res=str2big(s);
    for (int i=1;i<=n;i++)
        used[i]=0;

    for (int i=1;i<=k;i++)
    {
        int t=1;
        while (f[k-i]<res)
        {
            t++;
            res=res-f[k-i];
        }
        int j=1;
        for (;t>0;)
            if (!used[j++]) t--;
        cout<<--j<<" ";
        used[j]=1;
    }
    cout<<"\n";
    write(r);

}
