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
const int N=(int)501;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
int n;
int b[N][N];
int a[N][N];
vector<int> res;

int main()
{
    freopen(inp,"r",stdin);
    freopen(out,"w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++)
            cin>>b[i][j];

    for (int i=0;i+1<n;i++)
        a[i][i+1]=1;
    a[n-1][0]=1;
    for (int range=3;range<=n;range++)
        for (int d=0;d<n;d++)
            for (int temp=1;temp+1<range;temp++)
            {
                int c=d+range-1;
                if (c>=n) c-=n;
                int figh=d+temp;
                if (figh>=n) figh-=n;
                a[d][c]=a[d][c] | (a[d][figh] & a[figh][c] & (b[d][figh] | b[c][figh]));
            }
    for (int i=0;i<n;i++)
        for (int range=2;range<=n;range++)
        {
            int j=i+range-1;
            if (j>=n) j-=n;
            if (a[i][j] & a[j][i] & b[i][j])
            {
                res.pb(i);
                break;
            }
        }
    cout<<res.size();
    for (int i=0;i<res.size();i++)
        cout<<"\n"<<res[i]+1;
}
