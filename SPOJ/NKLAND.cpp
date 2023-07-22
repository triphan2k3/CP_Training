#include <bits/stdc++.h>
#define ll long long
#define ii pair<ll,ll>
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define inp "NKLAND.INP"
#define out "NKLAND.OUT"
using namespace std;
const int N=(int)1e4+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
ii a[N],b[N];
int m,n,t;


int chieu(ii a,ii b,ii c)
{
    //vt ab va vt ac
    ll tcheo=a.X*(c.Y-b.Y)+b.X*(a.Y-c.Y)+c.X*(b.Y-a.Y);
    if (tcheo==0) return 0;
    return tcheo > 0 ? 1:-1;
}
bool catnhau(ii a,ii b,ii c,ii d)
{
    //chieu quay cua c a b
    int abac=chieu(a,b,c);
    int abad=chieu(a,b,d);
    if (abac*abad>0) return false;
    int cdcb=chieu(c,d,b);
    int cdca=chieu(c,d,a);
    if (cdcb*cdca>0) return false;
    return true;
}
ll area(ii a,ii b,ii c)
{
    return a.X*(c.Y-b.Y)+b.X*(a.Y-c.Y)+c.X*(b.Y-a.Y);
}
void check()
{
    ll s=0;
    a[m+1]=a[1];
    for (int i=1;i<=m;i++)
        s+=a[i].X*(a[i-1].Y-a[i+1].Y);
    s=abs(s);

    for (int i=1;i<=n;i++)
    {
        ll ss=0;
        for (int j=1;j<=m;j++)
            ss+=abs(area(b[i],a[j],a[j-1]));
        //ss=abs(ss);
        if (ss==s)
        {
            cout<<"YES\n";
            return;
        }
    }
    s=0;
    b[n+1]=b[1];
    for (int i=1;i<=n;i++)
        s+=b[i].X*(b[i-1].Y-b[i+1].Y);
    s=abs(s);

    for (int i=1;i<=m;i++)
    {
        ll ss=0;
        for (int j=1;j<=n;j++)
            ss+=abs(area(a[i],b[j],b[j-1]));
        //ss=abs(ss);
        if (ss==s)
        {
            cout<<"YES\n";
            return;
        }
    }
    //cout<<"NO\n";
    //return;

    for (int i=1;i<=m;i++)
        for (int j=1;j<=n;j++)
            if (catnhau(a[i],a[i-1],b[j],b[j-1]))
            {
                cout<<"YES\n";
                return;
            }
    cout<<"NO\n";
    return;
}
int main()
{
    freopen(inp,"r",stdin);
    freopen(out,"w",stdout);
    cin>>t;
    while (t--)
    {
        cin>>m;
        for (int i=1;i<=m;i++)
            cin>>a[i].X>>a[i].Y;
        cin>>n;
        for (int i=1;i<=n;i++)
            cin>>b[i].X>>b[i].Y;
        a[0]=a[m];
        b[0]=b[n];
        check();
    }
}
