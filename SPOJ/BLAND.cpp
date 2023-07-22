#include <bits/stdc++.h>
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define inp "BLAND.INP"
#define out "BLAND.OUT"
using namespace std;
const int N=301;

int a[N][N],b[N][N];
int pmin[N][N][10],pmax[N][N][10];
int mu[10],lg[N];
int _max[N],_min[N];
int m,n,k;
int rest[N],resb[N];

void setup()
{
    for (int i=2;i<=300;i++)
        lg[i]=lg[i/2]+1;
    mu[0]=1;
    for (int i=1;i<=lg[300];i++)
        mu[i]=mu[i-1]*2;
    //______________________
    //pmin[i][j][] i la cot j la hang
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=m;j++)
        {
            pmin[i][j][0]=a[j][i];
            pmax[i][j][0]=a[j][i];
        }
        for (int k=1;k<=lg[m];k++)
            for (int j=1;j+mu[k]-1<=m;j++)
            {
                pmin[i][j][k]=min(pmin[i][j][k-1],pmin[i][j+mu[k-1]][k-1]);
                pmax[i][j][k]=max(pmax[i][j][k-1],pmax[i][j+mu[k-1]][k-1]);
            }
    }
}

void chosen(int top, int bot)
{
    int k=lg[bot-top+1];
    for (int i=1;i<=n;i++)
    {
        _min[i]=min(pmin[i][top][k],pmin[i][bot-mu[k]+1][k]);
        _max[i]=max(pmax[i][top][k],pmax[i][bot-mu[k]+1][k]);
    }
}

int findmax()
{
    deque<int> mi,ma;
    int res=0;
    int mapos=1,mipos=1;
    if (_max[1]-_min[1]<=k)
    {
        mi.pb(1);
        ma.pb(1);
        res=1;
    } else {mipos++; mapos++;}
    for (int i=2;i<=n;i++)
    {
        while (mi.size() && _min[mi.back()]>_min[i]) mi.pop_back();
        mi.pb(i);
        while (_min[i]-_min[mi.front()]>k) mipos=mi.front()+1,mi.pop_front();

        while (ma.size() && _max[ma.back()]<_max[i]) ma.pop_back();
        ma.pb(i);
        while (_min[ma.front()]-_min[i]>k) mapos=ma.front()+1,ma.pop_front();

        while (mi.size() && ma.size() && (_max[ma.front()]-_min[mi.front()]>k))
            if (ma.front()>mi.front()) mipos=mi.front()+1,mi.pop_front();
                else mapos=ma.front()+1,ma.pop_front();

        if (mi.empty() || ma.empty()) continue;
        int maxpos=max(mipos,mapos);
        res=max(res,i-maxpos+1);
    }
    return res;
}
int main()
{
    freopen(inp,"r",stdin);
    freopen(out,"w",stdout);
    cin>>m>>n>>k;
    for (int i=1;i<=m;i++)
        for (int j=1;j<=n;j++)
        cin>>a[i][j];
    setup();
    int res=0;
    for (int i=1;i<=m;i++)
        for (int j=i;j<=m;j++)
        {
            chosen(i,j);
            int kk=findmax();
            res=(j-i+1)*kk;
            rest[j]=max(rest[j],res);
            resb[i]=max(resb[i],res);
        }
    int fres=0;
    for (int i=2;i<=m;i++)
        rest[i]=max(rest[i],rest[i-1]);

    for (int i=m-1;i>=1;i--)
        resb[i]=max(resb[i],resb[i+1]);

    for (int i=1;i<m;i++)
        fres=max(fres,rest[i]+resb[i+1]);

    for (int i=1;i<=m;i++)
        for (int j=1;j<=n;j++)
        b[i][j]=a[i][j];

    for (int i=1;i<=m;i++)
        for (int j=1;j<=n;j++)
            a[j][i]=b[i][j];
    swap(m,n);

    setup();
    res=0;
    for (int i=1;i<=n;i++)
    {
        rest[i]=0;
        resb[i]=0;
    }
    for (int i=1;i<=m;i++)
        for (int j=i;j<=m;j++)
        {
            chosen(i,j);
            int kk=findmax();
            res=(j-i+1)*kk;
            rest[j]=max(rest[j],res);
            resb[i]=max(resb[i],res);
        }
    for (int i=2;i<=m;i++)
        rest[i]=max(rest[i],rest[i-1]);

    for (int i=m-1;i>=1;i--)
        resb[i]=max(resb[i],resb[i+1]);

    for (int i=1;i<m;i++)
        fres=max(fres,rest[i]+resb[i+1]);

    cout<<fres;

}
