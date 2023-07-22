#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define inp "1335E.INP"
#define out "1335E.OUT"
using namespace std;
const int N=(int)2e5+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
int t,n,l,r,L,R,ans,ma;
int a[N],p[300];
vector<ii> pos;
void rsp()
{
    for (int i=1;i<=200;i++)
        p[i]=0;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen(inp,"r",stdin);
    freopen(out,"w",stdout);
    cin>>t;
    while (t--)
    {
        cin>>n;
        for (int i=1;i<=n;i++)
            cin>>a[i];
        a[n+1]=0;
        if (n==1)
        {
            cout<<"1\n";
            continue;
        }
        if (n==2)
        {
            if (a[1]==a[2])
                cout<<"2\n";
            else cout<<"1\n";
            continue;
        }
        rsp();
        for (int i=1;i<=n;i++)
            ma=max(ma,++p[a[i]]);
        ans=ma;
        for (int x=1;x<=200;x++)
        {
            pos.clear();
            l=0;
            r=n+1;
            ma=0;
            while (l<r)
            {
                while (a[l]!=x && l<=r) l++;
                while (a[r]!=x && l<=r) r--;
                if (l<r)
                {
                    L=l;
                    R=r;
                    pos.push_back({l++,r--});
                }
            }
            if (pos.size()==0) continue;
            rsp();
            for (int i=L+1;i<R;i++)
                ma=max(ma,++p[a[i]]);

            ans=max(ans,ma+(int)pos.size()*2);
            for (int i=pos.size()-2;i>=0;i--)
            {
                int u=pos[i].X;
                int v=pos[i].Y;
                for (int j=u+1;j<L;j++)
                    ma=max(ma,++p[a[j]]);
                for (int j=R+1;j<v;j++)
                    ma=max(ma,++p[a[j]]);
                ans=max(ans,ma+(i+1)*2);
                L=u;
                R=v;
            }
        }
        cout<<ans<<"\n";
        ma=0;
    }
}
