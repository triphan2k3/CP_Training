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
#define inp "TEST.INP"
#define out "TEST.OUT"
using namespace std;
const int N=(int)1e5+7;
const int MOD=(int)1e8+7;
const ll INF=(ll)1e18+7;
int a[10];
int main()
{
    freopen(inp,"r",stdin);
    freopen(out,"w",stdout);
    int pr,n;
    string s;
    cin>>n;
    a[1]=a[2]=a[3]=a[4]=a[5]=a[6]=a[7]=MOD;
    for (int i=1;i<=n;i++)
    {
        cin>>pr;
        cin>>s;
        sort(s.begin(),s.end());
            if (s=="A")   a[1]=min(a[1],pr);
            if (s=="B")   a[2]=min(a[2],pr);
            if (s=="C")   a[3]=min(a[3],pr);
            if (s=="AB")  {a[4]=min(a[4],pr); a[1]=min(a[1],pr); a[2]=min(a[2],pr);}
            if (s=="AC")  {a[5]=min(a[5],pr); a[1]=min(a[1],pr); a[3]=min(a[3],pr);}
            if (s=="BC")  {a[6]=min(a[6],pr); a[2]=min(a[2],pr); a[3]=min(a[3],pr);}
            if (s=="ABC") {a[7]=min(a[7],pr); a[1]=min(a[1],pr); a[2]=min(a[2],pr);
                           a[3]=min(a[3],pr); a[4]=min(a[4],pr); a[5]=min(a[5],pr);
                           a[6]=min(a[6],pr);
                           }

    }
    int res=MOD+1;
    res=min(res,a[1]+a[2]+a[3]);
    res=min(res,a[1]+a[6]);
    res=min(res,a[2]+a[5]);
    res=min(res,a[3]+a[4]);
    res=min(res,a[7]);
    if (res>=MOD) cout<<"-1";
    else
    cout<<res;
}
