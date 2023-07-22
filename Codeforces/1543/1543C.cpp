#include <bits/stdc++.h>
#define TASK ""
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
#define float double
using namespace std;

const int N=(int)1e6+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
const float esp=1e-7;
float c,m,p,v,ans;
int cnt;

void backtrack(float c,float m,float p,float chance,int turn) {
    ans+=p*chance*turn;
    ++cnt;
    //choice m
    if (m>esp) {
        float newm=m>v ? m-v:0;
        float dec=min(v,m);
        if (c>esp)
            backtrack(c+0.5*dec,newm,p+0.5*dec,chance*m,turn+1);
        else
            backtrack(0,newm,p+dec,chance*m,turn+1);
    }
    //choice c
    if (c>esp) {
        float newc=c>v ?c-v:0;
        float dec=min(v,c);
        if (m>esp)
            backtrack(newc,m+0.5*dec,p+0.5*dec,chance*c,turn+1);
        else
            backtrack(newc,0,p+dec,chance*c,turn+1);
    }
}
int main() {
    //freopen(TASK".INP","r",stdin);
    //freopen(TASK".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> c >> m >> p >> v;
        ans=0;
        cnt=0;
        backtrack(c,m,p,1,1);
        cout << setprecision(7)<< fixed <<  ans << '\n';
    }
}
