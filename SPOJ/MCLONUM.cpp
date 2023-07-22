#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define inp "MCLONUM.INP"
#define out "MCLONUM.OUT"
using namespace std;
const int N=(int)1e5+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
string a,b;
int cnt[11];
void solve1()
{
    int dem[11];
    for (int i=0;i<=9;i++)
        dem[i]=cnt[i];
    int pos=-1;
    for (int i=0;i<a.size();i++)
        if (dem[a[i]-48]) dem[a[i]-48]-- , pos++;
        else break;
    if (pos+1==a.size())
    {
        cout<<a<<"\n";
        return;
    }

    for (int i=pos;i>=-1;i--)
    {
        int j=a[i+1]-48+1;
        while (dem[j]==0 && j<=9) j++;
        if (j==10)
        {
            dem[a[i]-48]++;
            continue;
        }
        for (int k=0;k<=i;k++)
            printf("%c",a[k]);
        printf("%d",j);
        dem[j]--;
        for (int k=0;k<=9;k++)
            while (dem[k]--) printf("%d",k);
        printf("%c",'\n');
        return;
    }
    printf("0\n");

}
void solve2()
{
    int dem[11];
    for (int i=0;i<=9;i++)
        dem[i]=cnt[i];
    int pos=-1;
    for (int i=0;i<a.size();i++)
        if (dem[a[i]-48]) dem[a[i]-48]--,pos++;
        else break;
    if (pos+1==a.size())
        dem[a[pos]-48]++ ,
        pos--;
    for (int i=pos;i>=-1;i--)
    {
        int j=a[i+1]-48-1;
        while (dem[j]==0 && j>=0) j--;
        if (j<0 || (j==0 && i+1==0))
        {
            dem[a[i]-48]++;
            continue;
        }
        for (int k=0;k<=i;k++)
            printf("%c",a[k]);
        printf("%d",j);
        dem[j]--;
        for (int k=9;k>=0;k--)
            while (dem[k]--) printf("%d",k);
        return;
    }
    printf("0\n");
}
int main()
{
    freopen(inp,"r",stdin);
    //freopen(out,"w",stdout);
    cin>>a>>b;
    for (int i=0;i<b.size();i++)
        cnt[b[i]-48]++;

    solve1();
    solve2();
}
