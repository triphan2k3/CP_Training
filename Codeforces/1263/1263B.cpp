/*
                                 _ _  _| _   |_     |_  _  _  _ |   _  _|_ _
                                (_(_)(_|(/_  |_)\/  | |(_)| |(_||\/(_|_|| (/_
                                                /             _| /
*/
#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define inp "1263B.INP"
#define out "1263B.OUT"
using namespace std;
const int N=(int)1e5+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
int t,n,a[1000],ck[100];
void write(int a)
{
    if (a<10)
    {
        cout<<"000"<<a<<"\n";
        return;
    }
    if (a<100)
    {
        cout<<"00"<<a<<"\n";
        return;
    }
    if (a<1000)
    {
        cout<<"0"<<a<<"\n";
        return;
    }
    cout<<a<<"\n";
    return;

}
int main()
{
    freopen(inp,"r",stdin);
    freopen(out,"w",stdout);
    cin>>t;
    while (t--)
    {
        cin>>n;
        for (int i=1;i<=n;i++)
            cin>>a[i];

        for (int i=0;i<10;i++)
            ck[i]=0;

        for (int i=1;i<=n;i++)
            ck[a[i]%10]++;

        int ans=0;
        for (int i=1;i<=n;i++)
            for (int k=n;k>=1;k--)
            if (a[i]==a[k] && k!=i)
            {
                ans++;
                for (int j=0;j<10;j++)
                    if (!ck[j])
                    {
                        ck[a[i]%10]--;
                        a[i]=(a[i]-a[i]%10)+j;
                        ck[j]++;
                        break;
                    }
                break;
            }
        cout<<ans<<"\n";
        for (int i=1;i<=n;i++)
            write(a[i]);
    }
}
