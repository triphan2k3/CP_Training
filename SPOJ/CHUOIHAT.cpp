#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define inp "CHUOIHAT.INP"
#define out "CHUOIHAT.OUT"
using namespace std;
const int N=(int)1e5+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
struct bignum
{
    int en;
    int so[250];
};
bignum def;
bignum f[501][501];
string s;
int n;

bignum operator + (bignum a,bignum b)
{
    bignum res=def;
    while (a.en<b.en) a.en++;
    while (a.en>b.en) b.en++;
    int now=0;
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

bignum operator - (bignum a,bignum b)
{
    bignum res=def;
    while (a.en<b.en) a.en++;
    while (a.en>b.en) b.en++;
    int now=0,car=0;;
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
int main()
{
    freopen(inp,"r",stdin);
    freopen(out,"w",stdout);
    int t;

    cin>>n;
    string s;
    cin >> s;
    bignum res=str2big(s);
    for (int i=1;i<=2*n;i++)
        f[n][i]=str2big("1");

    for (int i=n-1;i>=1;i--)
        for (int j=2*i+1;j>=i;j--)
        f[i][j]=f[i+1][j+1]+f[i][j+1];

    int cur=0;
    for (int i=1;i<=n;i++)
    {
        int j=cur+1;
        for (;j<=2*i;j++)
            if (f[i][j]<res) res=res-f[i][j]; else break;
        cout<<j<<" ";
        cur =j;
    }
}
