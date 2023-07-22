#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define inp "NTSURF.INP"
#define out "NTSURF.OUT"
#define vt vector<int>
using namespace std;
struct bignum
{
    int en;
    int so[2000];
};
const int N=(int)1e5+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
bignum ft[56][56];
bignum fg[56][56];
bignum k,def;
int used[56],d[56];
int n;

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
void solve()
{
    if (n==1)
    {
        cout<<"1\n";
        return;
    }
    if (n==2)
    {
        if (k.so[0]==1)
        cout<<"1 2\n";
        else cout<<"2 1\n";
        return;
    }
    fill(used,used+51,0);
    for (int i=1;i<=50;i++)
        d[i]=i;
    //--------------
    int pre=1;
    int state;
    while (ft[n][pre]+fg[n][pre]<k)
    {
        bignum temp=ft[n][pre]+fg[n][pre];
        k=k-temp;
        pre++;
    }
    used[pre]=1;
    for (int i=pre+1;i<=n;i++)
        d[i]--;

    printf("%d",pre);
    printf("%c",' ');

    for (int i=1;i<=n;i++)
        if (i<pre)
        {
            if (ft[n-1][i]<k) k=k-ft[n-1][i];
            else {pre=i; state=1; break;}
        } else
        if (i>pre)
        {
            if (fg[n-1][i-1]<k) k=k-fg[n-1][i-1];
            else {pre=i; state=0; break;}
        }
    used[pre]=1;
    printf("%d",pre);
    printf("%c",' ');
    for (int i=pre+1;i<=n;i++)
        d[i]--;
    int t;
    for (int i=3;i<=n-1;i++)
    {
        int cl=n-i+1;
        if (state==1)
        {
            t=pre+1;
            for (t=pre+1;t<=n;t++)
            if (!used[t])
            {
                if (fg[cl][d[t]]<k)
                k=k-fg[cl][d[t]];
                else break;

            }
        }
        if (state==0)
        {
            t=1;
            for (t=1;t<pre;t++)
            if (!used[t])
            {
                if (ft[cl][d[t]]<k)
                k=k-ft[cl][d[t]];
                else break;
            }
        }
        printf("%d",t);
        printf("%c",' ');
        used[t]=1;
        state=1-state;
        for (int z=t+1;z<=n;z++) d[z]--;
        pre=t;
    }
    for (int i=1;i<=n;i++)
        if (!used[i])
        {
            printf("%d",i);
            printf("%c",'\n');
            return;
        }
}
int main()
{
    freopen(inp,"r",stdin);
    freopen(out,"w",stdout);
    ft[3][1].so[0]=1; //1 3 2
    ft[3][2].so[0]=1; //2 3 1
    ft[3][3].so[0]=0;

    fg[3][1].so[0]=0;
    fg[3][2].so[0]=1;//2 1 3
    fg[3][3].so[0]=1;//3 1 2

    ft[2][1].so[0]=1;
    ft[2][2].so[0]=0;

    fg[2][2].so[0]=1;
    fg[2][1].so[0]=0;

    ft[1][1].so[0]=0;
    fg[1][1].so[0]=0;
    for (int i=4;i<=53;i++)
    {
        for (int j=1;j<=i;j++)
            fg[i][j]=fg[i][j-1]+ft[i-1][j-1];
        for (int j=i;j>=1;j--)
            ft[i][j]=ft[i][j+1]+fg[i-1][j];
    }
    string s;
    while (scanf("%d",&n)==1 && n!=0)
    {
        cin>>s;
        k=str2big(s);
        solve();
    }
}
