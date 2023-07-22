#include <bits/stdc++.h>
#define TASK "1354C"
#define pb push_back
#define ii pair<int,int>
#define iii pair<ii,int>
#define ll long long
#define ld long double
#define F first
#define S second
#define FOR(i, a, b) for (int i=a; i<=b; i++)
#define FOr(i, a, b) for (int i=a; i<b ; i++)
#define FOD(i, a, b) for (int i=a; i>=b; i--)
#define FOd(i, a, b) for (int i=a; i>b ; i--)
#define PI 3.14159265
using namespace std;

const int N=(int)1e6+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
long double dp[500],goc[500];
ld Sin(ld i) {
    return sin(i*PI/180);
}
ld Cos(ld i) {
    return Sin(90-i);
}
int main() {
    freopen(TASK".INP","r",stdin);
    freopen(TASK".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    dp[2]=1.0;
    goc[2]=360;
    for (int i=3;i<=200;i++) {
        goc[i]=goc[i-1]+360;
        ld n=i*2;
        ld u=goc[i]/n;
        ld x=u-90;
        ld z=(180-u)*(i-3)/2;
        ld y=u-z-90+x;
        ld a=Cos(x);
        ld b=Sin(x);
        ld f=b/Cos(y);
        ld e=sqrt(f*f-b*b);
        dp[i]=e+a;
        if (i%2) {
            a = sqrt(dp[i]*dp[i]+1)/2;
            x=(180-u)*(i+1)/4;
            b = a*Sin(x);
            e = sqrt(a*a-b*b);
            dp[i] = sqrt(2)*(e+b);
        }

    }
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << setprecision(6) << fixed << dp[n];
        cout <<"\n";
    }
}
