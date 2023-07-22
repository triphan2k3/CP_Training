#include <bits/stdc++.h>
using namespace std;
struct data
{
    int w,h;
};
const int inf=10001;
data a[20001];
int s[20001],ma,n;

bool func(data a, data b)
{
    if (a.h!=b.h) return a.h<b.h;
    return a.w>b.w;
}

void np(int i)
{
    int l=0, r=ma;
    do
    {
        int m=(l+r)/2;
        if (a[s[m]].w<a[i].w) r=m;
        else l=m;
    } while (r-l>1);
    if (a[s[r]].w>=a[i].w) l=r;
    if (l==ma)
        s[++ma]=i;
        else if (a[s[l+1]].w<a[i].w) s[l+1]=i;
}

int main()
{
    int t;
    //ifstream f ("test.inp");
    cin >>t ;
    a[0].w=a[0].h=inf;
    for (int q=1;q<=t;q++)
    {
        cin >> n;
        ma=0;
        for (int i=1;i<=n;i++)
            cin >> a[i].w >> a[i].h;

        sort(a+1,a+(n+1),func);

        for (int i=1;i<=n;i++)
            np(i);

        cout<<ma<<"\n";
    }
}
