#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define inp "EQSTR.INP"
#define out "EQSTR.OUT"
using namespace std;
const int N=(int)1e5+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
string s,t;
void dp()
{
    int n=s.size();
    for (int i=0;i<n;i++)
        if (s[i]==t[i])
            cout<<t[i];
        else
        {
            if (abs(s[i]-t[i])<13)
                cout<<min(s[i],t[i]);
            else cout<<'a';
        }
}
int main()
{
    freopen(inp,"r",stdin);
    freopen(out,"w",stdout);
    cin>>s;
    while (s[1]=='C')
    {
        cin>>s>>t;
        dp();
        cout<<"\n";
        cin>>s;
    }
}
