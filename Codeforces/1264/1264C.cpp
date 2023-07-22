/*
                                 _ _  _| _   |_     |_  _  _  _ |   _  _|_ _
                                (_(_)(_|(/_  |_)\/  | |(_)| |(_||\/(_|_|| (/_
                                                /             _| /
*/
#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define inp "1264C.INP"
#define out "1264C.OUT"
using namespace std;
const int N=(int)5e5+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
int a[N],pos[N];
int n,t;
int main()
{
    freopen(inp,"r",stdin);
    freopen(out,"w",stdout);
    cin>>t;
    while (t--)
    {
        cin>>n;
        int m=-1;
        for (int i=1;i<=n;i++)
        {
            cin>>a[i];
            if (a[i]!=a[i-1])
                pos[++m]=i-1;
        }
        pos[++m]=n;
        while (pos[m]>n/2)
            m--;

        if (m<=2)
        {
            cout<<"0 0 0\n";
            continue;
        }
        int st=pos[1];
        int now=2;
        while (pos[now]<=2*st && now<=m) now++;
        int nd=pos[now]-st;
        int rd=pos[m]-nd-st;
        if (now>m || nd<=st || rd<=st ||rd==0)
            cout<<"0 0 0\n";
        else cout<<st<<" "<<nd<<" "<<rd<<" "<<"\n";
    }
}
