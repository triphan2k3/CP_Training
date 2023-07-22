#include <bits/stdc++.h>
#define TASK ""
#define pb push_back
#define F first
#define S second
#define FOR(i, a, b) for (int i=a; i<=b; i++)
#define FOr(i, a, b) for (int i=a; i<b ; i++)
#define FOD(i, a, b) for (int i=a; i>=b; i--)
#define FOd(i, a, b) for (int i=a; i>b ; i--)
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef vector<int> vi;

const int N=1e6+7;
const int MOD=1e9+7;
const ll INF=(ll)1e18+7;

int main() {
    #ifdef TriPhann
        freopen("TEST.INP","r",stdin);
        freopen("TEST.OUT","w",stdout);
    #else
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    #endif
    int t; cin >> t;
    while (t--) {
        int s,n,cnt=0;
        cin >> s >> n;
        vector<int> v1, v2;
        for(int i=s,base=1;i>0;i/=10) {
            int num = i%10;
            FOR(j,1,num)
                v1.pb(base);
            cnt+=num;
            if (base < 1000000000) base*=10;
        }
        reverse(v1.begin(),v1.end());
        while (v1.size() + v2.size() < n) {
            int u = v1.back(); v1.pop_back();
            if (u==1) {
                v2.push_back(u);
                continue;
            }
            u/=10;
            FOR(i,1,10)
                v1.push_back(u);
        }
        FOR(i,1,v2.size())
            v1.push_back(1);
        while (v1.size() > n) {
            int u = v1.back(); v1.pop_back();
            int v = v1.back(); v1.pop_back();
            v1.push_back(u+v);
        }
        for (int x:v1)
            cout << x << " ";
        cout << "\n";

    }
}