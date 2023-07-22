
#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define inp "NKLEXIC.INP"
#define out "NKLEXIC.OUT"
using namespace std;
const int N=(int)1e5+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e11+7;
ll f[27][27];
ll used[27];
ll k;
string s;
ll m;
ll n;
ll maxr;

void solveP()
{
    for (int i=0;i<26;i++)
    used[i]=0;

    if (s.size()!=m || n<1 || n>26 || m>n) {cout<<"Incorrect data\n"; return;}
    for (int i=0;i<s.size();i++)
    if (used[s[i]-'a']) {cout<<"Incorrect data\n"; return;} else used[s[i]-'a']=1;
    for (int i=n;i<26;i++)
    if (used[i]) {cout<<"Incorrect data\n"; return;}

    fill(used,used+26,0);
    ll res=0;
    for (int i=0;i<s.size();i++)
    {
        for (int j=0;j<s[i]-'a';j++)
        if (!used[j])
            res+=f[m-i-1][n-i-1];
        used[s[i]-'a']=1;
    }
    cout<<res+1<<"\n";
}
void solveW()
{
    if (k>f[m][n] || n<1 || n>26 || m>n)
    {
        cout<<"Incorrect data\n";
        return;
    }
    fill(used,used+26,0);
    for (int i=1;i<=m;i++)
    {
        int t=1;
        while (k-f[m-i][n-i]>0)
        {
            k-=f[m-i][n-i];
            t++;
        }
        int j=0;
        for (;t>0;j++)
            if (!used[j]) t--;

        j--;
        cout<<(char)(j+'a');
        used[j]=1;
    }
    cout<<"\n";
}
int main()
{
    //freopen(inp,"r",stdin);
    //freopen(out,"w",stdout);
    ll T;
    maxr=2000000000;
    for (int i=0;i<=26;i++)
        f[0][i]=1;

    for (int i=1;i<=26;i++)
        for (int j=1;j<=i;j++)
        f[j][i]=(f[j-1][i-1]*i>maxr) ? INF:f[j-1][i-1]*i;

    char ch;
    cin>>T;
    while (T--)
    {
        cin>>n>>m;
        cin>>ch;
        if (ch=='P')
        {
            cin>>s;
            solveP();
        }
        else
        {
            cin>>k;
            solveW();
        }
    }
}
