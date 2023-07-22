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
#define inp "1264A.INP"
#define out "1264A.OUT"
using namespace std;
const int N=(int)1e5+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;

int main()
{
    freopen(inp,"r",stdin);
    freopen(out,"w",stdout);
    int t=0;
    string s;
    int a[4];
    cin>>t;
    while (t--)
    {
        cin>>s;
        int kt=1;
        s="d"+s;
        s=s+"d";
        for (int i=1;i+1<s.size();i++)
        if (s[i]=='?')
        {
            a[0]=a[1]=a[2]=0;
            if (s[i+1]!='?')
                a[s[i+1]-'a']=1;
            if (s[i-1]!='?')
                a[s[i-1]-'a']=1;
            if (a[0]==0)
                s[i]='a';
            else if (a[1]==0)
                s[i]='b';
            else s[i]='c';
        } else if (s[i]==s[i+1])
        {
            kt=0;
            break;
        }
        if (kt)
            for (int i=1;i+1<s.size();i++)
            cout<<s[i];
        else cout<<"-1";
        cout<<"\n";
    }
}
