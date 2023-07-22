#include <bits/stdc++.h>
using namespace std;
struct out
{
    int val,x1,y1,x2,y2;
};
const int inf=250001;
long f[501][501],a[501][501],k;
long sum(int x1, int y1, int x2, int y2)
{
    return (f[x2][y2]-f[x1-1][y2]-f[x2][y1-1]+f[x1-1][y1-1]);
}

int dientich(int x1, int y1, int x2, int y2)
{
    return ((x2-x1+1)*(y2-y1+1));
}
int main()
{
    int m,n;
    long s;
    cin >> m >> n >> k;
    for (int i=1;i<=m;i++)
        for (int j=1;j<=n;j++)
        cin >> a[i][j];

    for (int i=1;i<=m;i++)
        for (int j=1;j<=n;j++)
            f[i][j]=f[i-1][j]+f[i][j-1]-f[i-1][j-1]+a[i][j];
    int l,r;
    out res;
    res.val=inf;
    for (int i=1;i<=m;i++)
        for (int j=i;j<=m;j++)
    {
        s=sum(i,1,j,1);
        l=1;
        r=1;
        while (r<=n)
        if (s<k)
        {
            r++;
            s=sum(i,l,j,r);
        }
        else
        {
            if (res.val>dientich(i,l,j,r))
            {
                res.val=dientich(i,l,j,r);
                res.x1=i;
                res.y1=l;
                res.x2=j;
                res.y2=r;
            }
            l++;
            s=sum(i,l,j,r);
        }
    }
    if (res.val==inf)
    {
        cout << "-1";
        return 0;
    }
    cout << res.val << "\n" << res.x1 << " " <<res.y1 << " " <<res.x2 << " " <<res.y2 ;

}
