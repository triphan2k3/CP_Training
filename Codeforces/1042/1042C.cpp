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
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
ii a[2*N];
int b[2*N],c[2*N];
int n,aa,bb,cc;

int main()
{
    //freopen(inp,"r",stdin);
    //freopen(out,"w",stdout);
    cin>>n;
    int x;
    for (int i=1;i<=n;i++)
    {
        cin>>x;
        if (x<0)  a[++aa]=mp(x,i);
        if (x==0) b[++bb]=i;
        if (x>0)  c[++cc]=i;
    }
    sort(a+1,a+aa+1);
    for (int i=2;i<=aa-(aa%2);i++)
        cout<<"1 "<<a[i-1].Y<<" "<<a[i].Y<<"\n";

    for (int i=2;i<=bb;i++)
        cout<<"1 "<<b[i-1]<<" "<<b[i]<<"\n";

    for (int i=2;i<=cc;i++)
        cout<<"1 "<<c[i-1]<<" "<<c[i]<<"\n";
    if (aa+cc==0) return 0;
    int del,st,nd,rd;
    if (aa%2) del=a[aa].Y;
    else if (bb>0) del=b[bb]; else del=-1;

    if (aa>0 && aa%2==0)
        st=a[aa].Y;
    else
    if (aa>1)
        st=a[aa-1].Y;
    else st=-1;

    if (aa%2 && bb>0) nd=b[bb]; else nd=-1;
    if (cc>0) rd=c[cc]; else rd=-1;
    if (st==-1)
    {
        if (aa==1 && rd!=-1 && nd!=-1) cout<<"1 "<<nd<<" "<<del<<"\n";
        if (del!=-1)
        cout<<"2 "<<del<<"\n";

        return 0;
    }
    if (nd==-1)
    {
        if (del!=-1)
        cout<<"2 "<<del<<"\n";
        if (rd>0)
            cout<<"1 "<<st<<" "<<rd<<"\n";
        return 0;
    }
    cout<<"1 "<<nd<<" "<<del<<"\n";
    cout<<"2 "<<del<<"\n";
    if (rd>0)
        cout<<"1 "<<st<<" "<<rd<<"\n";
}
