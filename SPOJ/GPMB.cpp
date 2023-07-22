#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define iii pair<ii,int>
#define ri pair<double,int>
#define float double
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define inp "GPMB.INP"
#define out "GPMB.OUT"
using namespace std;
const int N=10007;
const float esp=0.00001;

vector<ri> e;
ii a[N];
int gt[N];
int n;
int ans,res;

ri cos(int i,int j)
{
    float x=a[j].X-a[i].X;
    float y=a[j].Y-a[i].Y;
    int v=gt[j];
    //if (x*x+y*y==0) return {1,v};
    float dis=sqrt(x*x+y*y);
    return {x/dis,v};
}

int sqr(int i)
{
    return i*i;
}
int main()
{
    freopen(inp,"r",stdin);
    freopen(out,"w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>a[i].X>>a[i].Y>>gt[i];
    for (int i=1;i<=n;i++)
    {
        e.clear();
        for (int j=1;j<=n;j++)
            if (j!=i && a[i].Y<=a[j].Y)
                e.push_back(cos(i,j));

        sort(e.begin(),e.end());
        res=sqr(e[0].Y)+5;
        ans=max(ans,res+sqr(gt[i])+5);
        for (int j=1;j<e.size();j++)
        {
            if (abs(e[j].X-e[j-1].X)<esp)
                res+=sqr(e[j].Y)+5;
            else res=sqr(e[j].Y)+5;
            ans=max(ans,res+sqr(gt[i])+5);
        }
    }
    cout<<ans;
}
