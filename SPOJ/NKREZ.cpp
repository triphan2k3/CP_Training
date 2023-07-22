#include <bits/stdc++.h>
using namespace std;
struct data
{
    int k,p;
};
data a[20000];
int n;
long f[20000],res;

bool myfunc(data a, data b)
{
    if (a.k==b.k) return (a.p<b.p);
    return (a.k<b.k);
}

int fin(int i)
{
    int l=0;
    int r=i-1;
    do
    {
        int mid=(l+r)/2;
        if (a[mid].k<=a[i].p) l=mid;
        else r=mid-1;
    } while (r-l>1);
    if (a[r].k<=a[i].p) return(r);
    return(l);

}
int main()
{
   // ifstream ff ("test.inp");
    cin >> n;
    for (int i=1;i<=n;i++)
    cin >> a[i].p >> a[i].k;
    sort(a+1,a+n+1,myfunc);
    f[1]=a[1].k-a[1].p;
    for (int i=2;i<=n;i++)
    {
        f[i]=f[i-1];
        int temp=fin(i);
        f[i]=max(f[i],f[temp]+a[i].k-a[i].p);
    }
    cout << f[n];
    //ff.close();
}
