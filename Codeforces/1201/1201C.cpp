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
#define inp "1201C.INP"
#define out "1201C.OUT"
using namespace std;
const int N=(int)1e5+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
int a[N];
int main()
{
    freopen(inp,"r",stdin); freopen(out,"w",stdout);
    int n,k;
    cin>>n>>k;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    int mid=n/2+1;
    int pos=mid;
    while(a[pos+1]==a[pos]) pos++;
    int cur=a[mid];
    while (mid-pos+1<=k)
    {
        int t=(pos==n)? a[pos]:a[pos+1];
        t=t-cur;
        if ((pos-mid+1)> k/t || pos==n)
        {
           cur+=k/(pos-mid+1);
           break;
        }
        k-=(pos-mid+1)*t;
        if (pos<n) pos++;
        while(a[pos+1]==a[pos]) pos++;
        cur+=t;
    }
    cout<<cur;

}
