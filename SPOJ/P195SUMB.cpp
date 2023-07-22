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
int a[N];
int n,tl,tr,l,r;
int main()
{
    //freopen(inp,"r",stdin);
    //freopen(out,"w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>a[i];

    l=0;
    r=n+1;
    while (l+1!=r)
    {
        if (tl==tr)
        {
            if (l+1!=r-1)
            {
                tl+=a[++l];
                tr+=a[--r];
            }
            else
                tl+=a[++l];
            continue;
        }
        if (tl<tr) tl+=a[++l];
        else tr+=a[--r];
    }
    cout<<l<<" "<<n-l;

}
