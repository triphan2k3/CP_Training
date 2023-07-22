#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define inp "MINK.INP"
#define out "MINK.OUT"
using namespace std;
const int N=(int)1e5+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
int a[N];
int st[N];
int r[N];

int main()
{
    freopen(inp,"r",stdin);
    freopen(out,"w",stdout);
    int n,t,k;
    cin>>t;
    while (t--)
    {
        cin>>n>>k;
        for (int i=1;i<=n;i++)
            cin>>a[i];
        int top=0;
        for (int i=n;i;i--)
        {
            while (top>0 && a[st[top]]>=a[i]) top--;
            r[i]=(top==0) ? min(n,i+k-1):min(i+k-1,st[top]-1);
            st[++top]=i;
        }
        int l=1;
        for (int i=1;i<=n;i++)
        {
            if (r[i]-l+1<k) continue;
            while (r[i]-l+1>=k )
            {
                cout<<a[i]<<char(32);
                l++;
            }
        }
        cout<<"\n";
    }
}
