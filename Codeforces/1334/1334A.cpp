#include <bits/stdc++.h>
using namespace std;
int n,a,b,t;

int main()
{
    freopen("1334A.INP","r",stdin);
    freopen("1334A.OUT","w",stdout);
    cin>>t;
    while (t--)
    {
        cin>>n;
        int kt=1;
        for (int i=1;i<=n;i++)
        {
            int a2,b2;
            cin>>a2>>b2;
            if (a2<a || b2<b || a2<b2 || a2-a<b2-b)
                kt=0;
            a=a2;
            b=b2;
        }
        if (kt) cout<<"YES\n";
        else cout<<"NO\n";
        a=b=0;
    }
}
