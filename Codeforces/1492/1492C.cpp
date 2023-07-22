#include <bits/stdc++.h>
#define TASK "1492C"
#define pb push_back
#define ii pair<int,int>
#define iii pair<ii,int>
#define ll long long
#define F first
#define S second
#define FOR(i, a, b) for (int i=a; i<=b; i++)
#define FOr(i, a, b) for (int i=a; i<b ; i++)
#define FOD(i, a, b) for (int i=a; i>=b; i--)
#define FOd(i, a, b) for (int i=a; i>b ; i--)
using namespace std;

const int N=(int)1e6+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
int m,n;
int Righ[N],Left[N];
string s,t;

int main() {
    //freopen(TASK".INP","r",stdin);
    //freopen(TASK".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    cin >> s >> t;
    s=" "+s;
    t=" "+t;
    int it=1;
    for (int i=1;it<=m;i++)
        if (s[i]==t[it])
            Left[it++]=i;

    it=m;
    for (int i=n;it>=1;i--)
        if (s[i]==t[it])
            Righ[it--]=i;
    int ans=0;
    for (int i=1;i<m;i++)
        ans=max(ans,Righ[i+1]-Left[i]);
    cout << ans;
}
