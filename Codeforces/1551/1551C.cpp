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
vector<int> r[5];
int c[5];
int main() {
    //freopen(TASK".INP","r",stdin);
    //freopen(TASK".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        FOR(i,1,n) {
            string s;
            cin >> s;
            int sz=s.size();
            FOR(j,0,4)
                c[j]=0;
            for (char ch:s)
                c[ch-'a']++;
            FOR(j,0,4)
                r[j].push_back(c[j]-(sz-c[j]));
        }
        int ans=0;
        FOR(ch,0,4) {
            sort(r[ch].begin(),r[ch].end());
            reverse(r[ch].begin(),r[ch].end());
            int sum=r[ch][0];
            if (sum<=0)
                continue;
            int thisans=1;
            FOr(i,1,r[ch].size()) {
                sum+=r[ch][i];
                if (sum>0)
                    thisans++;
                else break;
            }
            ans=max(ans,thisans);
        }
        FOR(i,0,4)
            r[i].clear();
        cout << ans << '\n';
    }
}
