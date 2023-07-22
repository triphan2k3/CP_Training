#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define inp "MTRIAREA.INP"
#define out "MTRIAREA.OUT"
using namespace std;
const int N=(int)1e5+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
vector<ii> a,tren,duoi;
int n,ans,t;

int area(ii a,ii b,ii c)
{
    return a.X*(c.Y-b.Y)+b.X*(a.Y-c.Y)+c.X*(b.Y-a.Y);
}

void convex_hull()
{
    for (int i=0;i<n;i++)
    {
        while (tren.size()>=2 && area(tren[tren.size()-2],tren[tren.size()-1],a[i])<=0)
            tren.pop_back();
        tren.push_back(a[i]);
        while (duoi.size()>=2 && area(duoi[duoi.size()-2],duoi[duoi.size()-1],a[i])>=0)
            duoi.pop_back();
        duoi.push_back(a[i]);
    }
    a=tren;
    for (int i=duoi.size()-2;i>0;i--)
        a.push_back(duoi[i]);
}
int main()
{
    freopen(inp,"r",stdin);
    freopen(out,"w",stdout);
    while (1)
    {
        cin>>n;
        if (n==-1) return 0;
        a.resize(n);
        for (int i=0;i<n;i++)
            cin>>a[i].X>>a[i].Y;
        sort(a.begin(),a.end());
        convex_hull();

        for (int i=0;i+2<a.size();i++)
        {
            int l=i+2;
            for (int j=i+1;j+1<a.size();j++)
            {
                if (l==j) l++;
                while (l+1<a.size() && abs(area(a[i],a[j],a[l]))<=abs(area(a[i],a[j],a[l+1])))
                    l++;
                ans=max(ans,abs(area(a[i],a[j],a[l])));
            }
        }
        if (ans%2) cout<<ans/2<<".50\n";
        else cout<<ans/2<<".00\n";
        a.clear();
        tren.clear();
        duoi.clear();
        ans=0;
    }
}
    /*
        for (int i=0;i+2<a.size();i++)
            for (int j=i+1;j+1<a.size();j++)
        {
            int l=i+2;
            int r=a.size()-1;
            while (r-l>1)
            {
                int mid=(r+l)>>1;
                int s1=abs(area(a[i],a[j],a[mid]));
                int s2=abs(area(a[i],a[j],a[mid+1]));
                if (s1>s2) r=mid;
                else l=mid;
            }
            ans=max(ans,max(abs(area(a[i],a[j],a[l])),
                            abs(area(a[i],a[j],a[r]))));
        }
        if (ans%2) cout<<ans/2<<".50\n";
        else cout<<ans/2<<".00\n";
        a.clear();
        tren.clear();
        duoi.clear();
        ans=0;
}
    */

