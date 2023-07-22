#include <bits/stdc++.h>
using namespace std;

int b[70000],a[70000];
int n;

int get(int x)
{
    int r=0,l=n;
    while (l>x)
    if (l-(l&(-l))<x)
    {
        r+=a[l];
        l--;
    } else
    {
        r+=b[l];
        l-=l&(-l);
    }
    return r;
}
void update(int x)
{
    while (x<=n)
    {
        b[x]++;
        x+=x&(-x);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    int m;
    int res=0;
    for (int i=1;i<=n;i++)
    {
        cin >> m;
        res+=get(m);
        update(m);
        a[m]++;
    }
    cout <<res;
}
