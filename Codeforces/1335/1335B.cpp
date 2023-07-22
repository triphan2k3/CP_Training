#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define inp "1335B.INP"
#define out "1335B.OUT"
using namespace std;
const int N=(int)1e5+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
int n,t,a,b;
int s[N];
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
        cin>>n>>a>>b;

        for (int i=0;i<b;i++)
            s[i]=i;

        for (int i=b;i<a;i++)
            s[i]=0;

        for (int i=a;i<n;i++)
            s[i]=s[i-a];

        for (int i=0;i<n;i++)
            cout<<char(s[i]+'a');
        cout<<"\n";
    }
}
