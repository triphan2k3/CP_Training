#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define inp ".INP"
#define out ".OUT"
using namespace std;
const int N=(int)1e5+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
ll a[31];
int main()
{
    //freopen(inp,"r",stdin);
    //freopen(out,"w",stdout);
    a[0]=1;
    a[2]=3;
    ll tmp=1;
    for (int i=4;i<=30;i+=2)
    {
        a[i]=a[i-2]*3+tmp*2;
        tmp+=a[i-2];
    }

    while (1)
    {
        int i;
        cin>> i;
        if (i==-1) return 0;
        cout<<a[i]<<"\n";
    }
}
