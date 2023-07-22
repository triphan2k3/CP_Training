#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define inp "CRECT.INP"
#define out "CRECT.OUT"
using namespace std;
const int N=405;
const char ch='F';
int a[N][N];
int h[N][N];
ll f[N][N];
char s[N][N];
int m,n;
ll res;

void setup(char x,char y,char z)
{
    for (int i=1;i<=m;i++)
        for (int j=1;j<=n;j++)
        {
            if (s[i][j]==x || s[i][j]==y || s[i][j]==z) a[i][j]=1;
            else a[i][j]=0;
            h[i][j]=(a[i][j]==1) ? h[i-1][j]+1 : 0;
        }
}

ll sol(int i)
{
    deque<int> d;
    int res=0;
    int pos;
    for (int j=1;j<=n;j++)
    {
        while (d.size() && h[i][d.back()]>=h[i][j]) d.pop_back();
        if (d.empty()) pos=1; else pos=d.back()+1;
        d.pb(j);
        f[i][j]=f[i][pos-1]+(ll)h[i][j]*((ll)j-(ll)pos+1ll);
        res+=f[i][j];
    }
    return res;
}
ll solve()
{
    ll res=0;
    for (int i=1;i<=m;i++)
        res+=sol(i);
    return res;
}
void proces(char a,char b,char c)
{
    setup(a,ch,ch); res+=solve();
    setup(ch,b,ch); res+=solve();
    setup(ch,ch,c); res+=solve();
    setup(a,b,ch);  res-=solve();
    setup(a,ch,c);  res-=solve();
    setup(ch,b,c);  res-=solve();
    setup(a,b,c);   res+=solve();
}
int main()
{
    freopen(inp,"r",stdin);
    freopen(out,"w",stdout);
    cin>>m>>n;
    string ss;
    for (int i=1;i<=m;i++)
    {
        cin>>ss;
        for (int j=1;j<=n;j++)
            s[i][j]=ss[j-1];
    }

    for (int i='A';i<='C';i++)
        for (int j=i+1;j<='D';j++)
            for (int k=j+1;k<='E';k++)
                proces((char) i,(char) j,(char) k);
    cout<<res;
}
