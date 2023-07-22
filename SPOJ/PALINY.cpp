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
string s,ss;
int n;
int l,r,k;
int ans,res[N];
int main()
{
    //freopen(inp,"r",stdin);
    //freopen(out,"w",stdout);
    cin>>n>>ss;
    r=-1;
    s.resize(2*n+1);
    for (int i=0;i<n;i++)
        s[2*i+1]=ss[i];
    for (int i=0;i<=n;i++)
        s[2*i]='#';

    for (int i=0;i<s.size();i++)
    {
        if (r<i) k=1;
        else k=min(r-i+1,res[l+r-i]);
        while (i+k<s.size() && i-k>=0 && s[i+k]==s[i-k]) k++;

        res[i]=k;
        if (i+k-1>r)
        {
            r=i+k-1;
            l=i-k+1;
        }
        ans=max(ans,res[i]-1);
    }
    cout<<ans;
}
