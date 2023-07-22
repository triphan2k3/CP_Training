#include <bits/stdc++.h>
using namespace std;
struct data
{
    int l,w;
};
const int inf=10001;
data a[5002];
int s[5002],ma,n;

bool func(data a, data b)
{
    return (a.w==b.w) ? (a.l<b.l) : (a.w<b.w);
}


int main()
{
    int t;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //ifstream g ("test.inp");
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i=1;i<=n;i++)
            cin >> a[i].l >> a[i].w;
        sort(a+1,a+n+1,func);
        ma=0;
        for (int i=n;i>=1;i--)
        {
            s[n-i+1]=inf;
            f[i]=0;
            int temp=lower_bound(s,s+ma+1,a[i].l)-s;
            ma=max(ma,temp);
            s[temp]=min(s[temp],a[i].l);
        }
        cout << ma << "\n";
    }

}
