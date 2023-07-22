#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define inp "1264D.INP"
#define out "1264D.OUT"
using namespace std;
const int N=(int)1e6+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
int a0,a1,a2,a3,a[N];
int main()
{
    cin>>a0>>a1>>a2>>a3;
    if (a0+a2>=a1 && a1+a3>=a2 && a2>=a3 && a1>=a0)
    {
        int r;
        for (int i=1;a0;i++)
        {
            if (i%2) a[i]=0;
            else a[i]=1;
            if (i%2) a0--;
            else a1--;
            r=i;
        }
        a[++r]=1;
        a1--;
        for (int i=1,tp=r;a1 && a2;i++)
        {
            if (i%2) a[i+tp]=2;
            else a[i+tp]=1;
            if (i%2) a2--;
            else a1--;
            r=i+tp;
        }
        if (a[r]!=2)
        {
            a[++r]=2;
            a2--;
        }

        for (int i=1,tp=r;a3 && a2;i++)
        {
            if (i%2) a[i+tp]=3;
            else a[i+tp]=2;
            if (i%2) a3--;
            else a2--;
            r=i+tp;
        }
        if (a[r]!=3 && a3)
        {
            a[++r]=3;
            a3--;
        }
        if (a[r]!=2 && a2)
        {
            a[++r]=2;
            a2--;
        }
        if (a2 || a3)
        {
            cout<<"NO";
            return 0;
        }
        if (a1)
        {
            cout<<"YES\n";
            cout<<"1 ";
            for (int i=1;i<=r;i++)
                cout<<a[i]<<" ";
        }
        else
        {
            cout<<"YES\n";
            for (int i=1;i<=r;i++)
                cout<<a[i]<<" ";
        }
        return 0;
    }
    cout<<"NO";
}
