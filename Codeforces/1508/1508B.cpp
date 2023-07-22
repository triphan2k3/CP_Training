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
using namespace std;

const int N=(int)1e6+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
const int M=70;
int n;
ll k, dp[M], s[M], dp1[M];

int main() {
    //freopen(TASK".INP","w",stdin);
    //freopen(TASK".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    dp[0]=1;
    dp[1]=dp1[1]=s[0]=1;
    s[1]=2;
    FOR(i, 2, 63) {
        dp1[i]=s[i - 2];
        dp[i] =dp[i - 1]+dp1[i];
        s[i]  = s[i - 1]+dp[i];
    }
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        if (k==1) {
            FOR(i,1,n)
                cout << i << " ";
            cout <<"\n";
            continue;
        }
        --k;
        int i=-1;
        FOR(st,2,n)
            if (k>dp1[st]) k-=dp1[st];
        else {
            i=n-st+1;
            break;
        }
        if (i==-1) {
            cout << i << "\n";
            continue;
        }
        vector<int> p;
        FOR(j,1,i-1) {
            p.push_back(j);
        }

        FOR(j,i,n) {
            int ed=(j==i) ? 2:1;
            FOR(st,ed,n-j+1)
                if (k>dp[n-j-st+1])
                    k-=dp[n-j-st+1];
                else {
                    FOD(x,j+st-1,j)
                        p.pb(x);
                    j+=st-1;
                    break;
                }
        }
        for (int x:p)
            cout << x << " ";
        cout << "\n";
    }

}
