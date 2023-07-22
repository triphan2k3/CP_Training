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
#define inp ".INP"
#define out ".OUT"
using namespace std;
const int N=(int)1e5+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;

int main()
{
    int t,m,n,x,y;
    cin>>t;
    while (t--)
    {
        cin>>x>>y;
        if (x>3)
        {
            cout<<"YES\n";
            continue;
        }
        if (x==1 && y>1)
        {
            cout<<"NO\n";
            continue;
        }
        if (y<=3)
        {
            cout<<"YES\n";
            continue;
        }
        cout<<"NO\n";
    }
}
