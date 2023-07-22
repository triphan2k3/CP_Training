#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define inp "1256F.INP"
#define out "1256F.OUT"
using namespace std;
const int N=(int)1e5+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
int n,q;
int ns[N],nt[N],poss[N],post[N];
string s,t;
int solve()
{
        cin>>n>>s>>t;
        for (int i=0;i<26;i++)
            ns[i]=nt[i]=0;
        for (int i=0;i<n;i++)
        {
            ns[s[i]-'a']++;
            nt[t[i]-'a']++;
        }
        for (int i=0;i<26;i++)
            if (ns[i]!=nt[i])
                return 0;
        for (int i=0;i<26;i++)
            if (ns[i]>=2) return 1;
        for (int i=0;i<26;i++)
            poss[i]=post[i]=-1;
        for (int i=0;i<n;i++)
        {
            poss[s[i]-'a']=i;
            post[t[i]-'a']=i;
        }
        int ans=0;
        for (int i=0;i<26;i++)
        if (poss[i]>=0 && poss[i]!=post[i])
        {
            ans++;
            s[poss[i]]=s[post[i]];
            poss[s[poss[i]]-'a']=poss[i];

        }
        return (1-ans%2);
}
int main()
{
    freopen(inp,"r",stdin);
    freopen(out,"w",stdout);
    cin>>q;
    while (q--)
    {
        if (solve()) cout<<"YES\n";
        else cout<<"NO\n";
    }
}
