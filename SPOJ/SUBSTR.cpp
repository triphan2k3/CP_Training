#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define inp "SUBSTR.INP"
#define out "SUBSTR.OUT"
using namespace std;
const int N=(int)1e6+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
string a,b;
int m,n,k,kmp[N];
int main()
{
    freopen(inp,"r",stdin);
    freopen(out,"w",stdout);
    cin>>a>>b;
    n=a.size();
    m=b.size();
    a="_"+a;
    b="_"+b;
    for (int i=2;i<=m;i++)
    {
        k=kmp[i-1];
        while (b[k+1]!=b[i] && k!=0)
            k=kmp[k];
        kmp[i]=k;
        if (b[k+1]==b[i])
            kmp[i]++;
    }
    k=0;
    for (int i=1;i<=n;i++)
    {
        while (k!=0 && a[i]!=b[k+1])
            k=kmp[k];
        if (a[i]==b[k+1]) k++;
        if (k==m)
        {
            cout<<i-m+1<<" ";
            k=kmp[k];
        }
    }
}
