/*
                                 _ _  _| _   |_     |_  _  _  _ |   _  _|_ _
                                (_(_)(_|(/_  |_)\/  | |(_)| |(_||\/(_|_|| (/_
                                                /             _| /
*/
#include <bits/stdc++.h>
#define ll long long
#define ii pair<ll,ll>
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define inp "1256C.INP"
#define out "1256C.OUT"
using namespace std;
const int N=(int)2e5+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e14+7;

int a[N],res[N],n,m,d,len;

int main()
{
    freopen(inp,"r",stdin);
    freopen(out,"w",stdout);
    cin>>n>>m>>d;
    for(int i=1;i<=m;i++)
    {
    	cin>>a[i];
    	len+=a[i];
    }
    int pos=0,i=0,pre=0;
    while (i<m)
    {
        if (pos<pre+d && pos+len<=n) pos++;
        else
        {
            i++;
            for (int j=0;j<a[i];j++)
                res[pos+j]=i;
            pos=pos+a[i];
            pre=pos-1;
            len-=a[i];
        }
    }
    if (pre+d>n)
    {
    	cout << "YES\n";
    	for(int i = 1; i <= n; i++) cout << res[i] << " ";
    }
    else cout << "NO";
}
