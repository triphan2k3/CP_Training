#include <bits/stdc++.h>
using namespace std;
long long x,y,z,n,p,soluong,numbit,t;
int main()
{
    freopen("1339E.INP","r",stdin);
    freopen("1339E.OUT","w",stdout);
    cin>>t;
    while (t--)
    {
        cin>>n;
        p=(n+2)/3;
        numbit=0;
        soluong=0;
        while (soluong+(1LL<<numbit) <=p)
        {
            soluong+=1LL<<numbit;

            numbit+=2;
        }
        if (soluong<p)
            numbit+=2;
        else soluong-=1LL<<(numbit-2);
        p-=soluong;
        x=p>0 ? (p-1)+(1LL<<(numbit-2)): 1LL<<(numbit-2);
        y=1LL<<(numbit-1);
        z=3LL<<(numbit-2);
        for (int i=numbit-2;i>0;i-=2)
        {
            int bit=(x>>(i-2)) & 3;
            if (bit==1)
            {
                y+=2LL<<(i-2);
                z+=3LL<<(i-2);
            }
            if (bit==2)
            {
                y+=3LL<<(i-2);
                z+=1LL<<(i-2);
            }
            if (bit==3)
            {
                y+=1LL<<(i-2);
                z+=2LL<<(i-2);
            }

        }
        if (n%3==0) cout<<z<<"\n";
        if (n%3==1) cout<<x<<"\n";
        if (n%3==2) cout<<y<<"\n";
    }
}

// 0 1   1 0   1 1  0 0
// 1 0   1 1   0 1  0 0
// 1 1   0 1   1 0  0 0
