#include <bits/stdc++.h>
#define TASK "1352D"
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
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n,0);
        FOr(i, 0, n)
            cin >> a[i];
        int sl=0,sr=0,ps=0;
        int l=0,r=n-1;
        int turn=1,m=0;;
        while (l<=r) {
            turn^=1;
            int ns=0;
            if (!turn) {
                while (ns<=ps && l<=r)
                    ns+=a[l++];
                sl+=ns;
                ps=ns;
            }
            else {
                while (ns<=ps && l<=r)
                    ns+=a[r--];
                sr+=ns;
                ps=ns;
            }
            m++;
        }
        cout << m << " " << sl << " " << sr << "\n";
    }
}
