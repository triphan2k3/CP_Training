#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,t,l,r,start,star,have;
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("1334D.INP","r",stdin);
    freopen("1334D.OUT","w",stdout);
    cin>>t;
    while (t--)
    {
        cin>>n>>l>>r;
        have=0;
        star=start=n+1;
        for (ll i=1;i<=n;i++)
            if (2LL*n*i-i*(i+1LL)>=l)
            {
                start=i;
                have=2LL*n*(i-1LL)-(i-1LL)*i;
                break;
            }
        for (ll i=start+1;i<=n;i++)
            if (have+2<l) have+=2LL;
                else
                {
                    have+=2LL;
                    if (have==l)
                    {
                        cout<<i<<" ";
                        l++;
                        star=i+1;
                    } else
                        star=i;
                    break;
                }


        for (ll i=start;i<=n;i++)
            for (ll j=(i==start) ? star:i+1;j<=n;j++)
            {
                if (l==r)
                {
                    cout<<i<<" ";
                    i=n+1;
                    break;
                }
                if (l>r)
                {
                    i=n+1;
                    break;
                }
                l+=2;
                cout<<i<<" "<<j<<" ";
            }
        if (r==n*(n-1LL)+1)
            cout<<"1";
        cout<<"\n";
    }
}
