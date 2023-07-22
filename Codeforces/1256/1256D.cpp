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
#define inp "1256D.INP"
#define out "1256D.OUT"
using namespace std;
const int N=(int)1e5+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
string s;
vector<ll> a;
ll n,k,t;

int main()
{
    freopen(inp,"r",stdin);
    //freopen(out,"w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while (t--)
    {
        cin>>n>>k>>s;
        a.clear();
        for (int i=0;i<n;i++)
            if (s[i]=='0') a.pb(i);

        ll right=0;
        ll last=0;
        //cerr<<s<<"\n\n";
        for (int i=0;i<=a.size();i++)
        {

            if (i==a.size())
            {
                for (int j=1;j<=a.size();j++)
                    cout<<0;
                for (int j=a.size()+1;j<=n;j++)
                    cout<<1;
                break;
            }
            if (a[i]-right<=k)
            {
                k-=(a[i]-right);
                right++;
                continue;
            }
            a.pb(n);
            last=a[i]-k;
            for (int j=0;j<right;j++)
                cout<<0;
            for (int j=right;j<last;j++)
                cout<<1;
            cout<<0;
            for (int j=last+1ll;j<a[i+1];j++)
                cout<<1;
            for (int j=a[i+1];j<n;j++)
                cout<<s[j];
            break;
        }
        cout<<"\n";

    }
}
