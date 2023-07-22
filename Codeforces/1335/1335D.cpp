#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define inp "1335D.INP"
#define out "1335D.OUT"
using namespace std;
const int N=(int)2e5+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
const int c[9]={0,3,6,1,4,7,2,5,8};
int t,a[10][10];
string s;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen(inp,"r",stdin);
    freopen(out,"w",stdout);
    cin>>t;
    while (t--)
    {
        for (int i=0;i<9;i++)
        {
            cin>>s;
            for (int j=0;j<9;j++)
                a[i][j]=s[j]-'0';
        }
        for (int i=0;i<9;i++)
        {
            int j=c[i];
            a[i][j]=a[i][j]%9+1;
        }
        for (int i=0;i<9;i++)
        {
            for (int j=0;j<9;j++)
                cout<<a[i][j];
            cout<<"\n";
        }
    }
}
