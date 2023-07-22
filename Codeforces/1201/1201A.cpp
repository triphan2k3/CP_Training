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
#define inp ".INP"
#define out ".OUT"
using namespace std;
const int N=(int)1e5+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
int a[1001][5];
int b[1001];
int ma(int i)
{
    int res=a[i][0];
    res=max(res,a[i][1]);
    res=max(res,a[i][2]);
    res=max(res,a[i][3]);
    res=max(res,a[i][4]);
    return res;
}
int main()
{
    //freopen(inp,"r",stdin);
    //freopen(out,"w",stdout);
    int n,m;
    cin>>n>>m;
    string s;
    for (int i=1;i<=n;i++)
    {
        cin>>s;
        for (int j=1;j<=m;j++)
            a[j][s[j-1]-'A']++;
    }

    for (int i=1;i<=m;i++)
        cin>>b[i];

    int res=0;
    for (int i=1;i<=m;i++)
        res+=ma(i)*b[i];
    cout<<res;
}
