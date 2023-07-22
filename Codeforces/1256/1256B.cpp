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
#define inp "1256B.INP"
#define out "1256B.OUT"
using namespace std;
const int N=(int)1e5+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
int t,n,a[N];

int main()
{
    freopen(inp,"r",stdin);
    freopen(out,"w",stdout);
    cin>>t;
    while (t--)
    {
        cin>>n;
        for (int i=1;i<=n;i++)
            cin>>a[i];
        int pos=0;
        while (1)
        {
            int tmp=0;
            int mi=n+1;
            for (int i=pos+1;i<=n;i++)
                if (a[i]<mi)
                {
                    mi=a[i];
                    tmp=i;
                }
            for (int i=tmp-1;i>=pos+1;i--)
                swap(a[i],a[i+1]);
            if (pos==tmp-1) pos++; else
            pos=tmp-1;
            if (pos+1==n) break;
        }
        for (int i=1;i<=n;i++)
            cout<<a[i]<<" ";
        cout<<"\n";
    }
}
