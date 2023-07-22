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
bool f[1001][1001];
int dp[1001];
string s;
int main()
{
    cin >> s;
    int t=s.length();
    for (int i=1;i<=t;i++)
        for (int j=i;j<=t;j++)
        {
            int k=j-i+1;
            f[k][j]=((s[j-1]==s[k-1])&&(j==k || j==k+1 || f[k+1][j-1]));
        }
    dp[1]=1;
    for (int i=2;i<=t;i++)
    {
        dp[i]=10000;
        for (int j=0;j<i;j++)
        if (f[j+1][i]) dp[i]=min(dp[i],dp[j]+1);
    }
    cout << dp[t];
}

