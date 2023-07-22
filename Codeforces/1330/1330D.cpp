#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll m,t,d;


int main()
{
    freopen("1330D.INP","r",stdin);
    freopen("1330D.OUT","w",stdout);
    cin>>t;
    while (t--)
    {
        cin>>d>>m;
        ll tmp=1;
        ll ans=1%m;
        while (d)
        {
            ans=ans*(min(d,tmp)+1)%m;
            d-=min(d,tmp);
            tmp*=2;
        }
        cout<<(ans-1+m)%m<<"\n";
    }
}
