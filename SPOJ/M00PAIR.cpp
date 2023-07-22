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
#define inp "M00PAIR.INP"
#define out "M00PAIR.OUT"
#define vt vector<int>
using namespace std;
const int N=(int)1e5+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
vt a[1001];
vt b[1001];
vt t[2];
vt operator +(vt a, vt b)
{
    while (a.size()<b.size()) a.pb(0);
    while (a.size()>b.size()) b.pb(0);
    vt c;
    int now=0;
    for (int i=0;i<a.size();i++)
    {
        now+=a[i]+b[i];
        c.pb(now%10);
        now/=10;
    }
    if (now>0) c.pb(1);
    return c;
}
void write(vt a)
{
    while (a.size())
    {
        printf("%d",a.back());
        a.pop_back();
    }
    printf("%c",'\n');
}
int main()
{
    //freopen(inp,"r",stdin);
    //freopen(out,"w",stdout);
    t[0].pb(1);
    t[1].pb(0);
    a[1].pb(0);
    b[1].pb(0);

    for (int i=2;i<=1000;i++)
    {
        a[i]=a[i-1]+b[i-1]+t[i%2];
        b[i]=a[i-1]+b[i-1];
    }
    int n;
    while (scanf("%d",&n)==1 && n>0)
            write(a[n]);
}
