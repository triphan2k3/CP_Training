#include <bits/stdc++.h>
using namespace std;
const long long inf=1e18;
long long a[200000],ll[5],c1,c2,c3,n,u,v,f[200000];
int np(int i, int ca)
{
    int l=u;
    int r=i;
    do
    {
        int mid=(l+r)/2;
        if (a[i]-a[mid]>ll[ca]) l=mid+1;
        else r=mid;
    } while (r-l>1);
    if (a[i]-a[l]<=ll[ca]) return l;
    return r;
}
int main()
{
    //ifstream ff ("test.inp");
    cin >> ll[1] >> ll[2] >> ll[3] >> c1 >> c2 >> c3;
    cin >> n >> u >> v;

    for (int i=2;i<=n;i++)
        cin >>a[i];
    int temp1=u,temp2=u,temp3=u;
    f[u]=0;
    for (int i=u+1; i<=v;i++)
    {
        //int temp1=np(i,1);
        //int temp2=np(i,2);
        //int temp3=np(i,3);
        while (a[i]-a[temp1]>ll[1]) temp1++;
        while (a[i]-a[temp2]>ll[2]) temp2++;
        while (a[i]-a[temp3]>ll[3]) temp3++;
        f[i]=inf;
        if (temp1!=i) f[i]=min(f[i],f[temp1]+c1);
        if (temp2!=i) f[i]=min(f[i],f[temp2]+c2);
        if (temp3!=i) f[i]=min(f[i],f[temp3]+c3);
    }

    cout << f[v];
    //ff.close();
}
