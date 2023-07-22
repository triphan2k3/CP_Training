#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define matrix vector<vector<ll>>
#define inp "LQDFIBO2.INP"
#define out "LQDFIBO2.OUT"
using namespace std;
const int N=(int)1e5+7;
const ll MOD=15111992;
const ll INF=(ll)1e18+7;
string s,s1,s2;
ll x,y,ta,tb;
ll n,sz;
matrix a={{1,1,0,0},
          {1,0,0,0},
          {1,0,0,1},
          {0,0,1,0}};
matrix r={{0,0,0,0},
          {0,0,0,0},
          {0,0,0,0},
          {0,0,0,0}};

matrix operator *(matrix a,matrix b)
{
    matrix c=r;
    for (int i=0;i<4;i++)
        for (int j=0;j<4;j++)
            for (int k=0;k<4;k++)
                c[i][j]=(c[i][j]+a[i][k]*b[k][j])%MOD;
    return c;
}
matrix pow(ll n)
{
    if (n==1) return a;
    matrix t=pow(n>>1);
    t=t*t;
    if (n%2) t=t*a;
    return t;
}
int sosanh(string temps)
{
    int t=0;
    if (temps.size()<s.size()) return 0;

    abc   3
    abcde 5
    for (int i=0;i+s.size()-1<temps.size();i++)
    {
        string tmp=temps.substr(i,s.size());
        if (tmp==s) t++;
    }
    return t;
}
int main()
{
    freopen(inp,"r",stdin);
    freopen(out,"w",stdout);
    cin>>n>>s1>>s2>>s;
    while ((s1.size()<s.size() || s2.size()<s.size()) && n>2)
    {
        s1=s2+s1;
        swap(s1,s2);
        n--;
    }
    if (n==2)
    {
        cout<<sosanh(s2);
        return 0;
    }
    sz=s.size()-1;
    string cuoi1,dau1,cuoi2,dau2;
    if (s1.size()>=s.size())
    cuoi1=s1.substr(s1.size()-s.size()+1,sz);
    else cuoi1=s1.substr(1,s1.size()-1);

    if (s1.size()>=s.size())
    dau1 =s1.substr(0,sz);
    else dau1=s1.substr(0,s1.size()-1);

    if (s2.size()>=s.size())
    dau2 =s2.substr(0,sz);
    else dau2=s2.substr(0,s2.size()-1);

    if (s2.size()>=s.size())
    cuoi2=s2.substr(s2.size()-s.size()+1,sz);
    else cuoi2=s2.substr(1,s2.size()-1);

    string c1d2,c2d1;
    c1d2=cuoi1+dau2;
    c2d1=cuoi2+dau1;
    ta=sosanh(c2d1);
    tb=sosanh(c1d2);
    x=sosanh(s1);
    y=sosanh(s2);
    matrix res=pow(n-2);

    ll finalres=0;
        finalres=(finalres+y*res[0][0])%MOD;
        finalres=(finalres+x*res[1][0])%MOD;
        finalres=(finalres+ta*res[2][0])%MOD;
        finalres=(finalres+tb*res[3][0])%MOD;
    cout<<finalres;

}
