#include <bits/stdc++.h>
#define TASK "1342B"
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
int main() {
    freopen(TASK".INP","r",stdin);
    freopen(TASK".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> q;
    while (q--) {
        string t;
        cin >> t;
        int sum=0;
        for (int i=0; i<t.size(); i++)
            sum+=t[i]-'0';
        if (sum==0 || sum==t.size()) {
            cout << t << "\n";
            continue;
        }
        for (int i=1;i<=t.size()*2;i++)
            cout<<i%2;
        cout<<"\n";
    }
}
