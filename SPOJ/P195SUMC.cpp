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
int n,c25,c50,c100,x;
int main()
{
    //freopen(inp,"r",stdin);
    //freopen(out,"w",stdout);
    cin>>n;

    for (int i=1;i<=n;i++)
    {
        cin>>x;
        if (x==25)
        {
            c25++;
            continue;
        }
        if (x==50)
        {
            c50++;
            if (c25==0)
            {
                cout<<"NO";
                return 0;
            }
            c25--;
        }
        if (x==100)
        {
            if (c25==0)
            {
                cout<<"NO";
                return 0;
            }
            if (c50==0)
            {
                if (c25<3)
                {
                    cout<<"NO";
                    return 0;
                }
                c25-=3;
                continue;

            }
            c25--;
            c50--;
        }
    }
    cout<<"YES";

}
