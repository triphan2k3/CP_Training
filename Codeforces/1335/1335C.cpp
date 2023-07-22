#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define inp "1335C.INP"
#define out "1335C.OUT"
using namespace std;
const int N=(int)2e5+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
int t,n,a[N],ma,num;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen(inp,"r",stdin);
    freopen(out,"w",stdout);
    cin>>t;
    while (t--)
    {
        cin>>n;
        for (int i=1;i<=n;i++)
            a[i]=0;
        ma=num=0;
        for (int i=1;i<=n;i++)
        {
            int k;
            cin>>k;
            a[k]++;
            if (a[k]==1)
                num++;
            ma=max(ma,a[k]);
        }
        if (ma==num) ma--;
        cout<<min(ma,num)<<"\n";

    }
}
