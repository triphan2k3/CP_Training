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
int a[100],b[1000];
int main() {
    freopen(TASK".INP","r",stdin);
    //freopen(TASK".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    b['0']=-1;
    b['1']=1;
    b['?']=0;
    while (t--) {
        string s;
        cin >> s;

        FOR(i,1,10)
            a[i]=b[s[i-1]];
        FOR(ans,6,10) {
            if (ans==10) {
                cout << "10\n";
                break;
            }
            int t1=0,t2=0;
            int t10=0,t20=0;
            FOR(i,1,ans)
                if (i%2) {
                    if (a[i]==0) t10++;
                    if (a[i]==1) t1++;
                } else
                {
                    if (a[i]==0) t20++;
                    if (a[i]==1) t2++;
                }
            //team1 win ?
            int score=t1+t10;
            int rem=0;
            FOR(i,ans+1,10)
                if (i%2==0) ++rem;
            if (score>t2+rem) {
                cout << ans << "\n";
                break;
            }
            //team2 win
            score=t2+t20;
            rem=0;
            FOR(i,ans+1,10)
                if (i%2) ++rem;
            if (score>t1+rem) {
                cout << ans << "\n";
                break;
            }
        }

    }
}
