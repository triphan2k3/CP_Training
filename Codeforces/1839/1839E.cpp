#include <bits/stdc++.h>
#define TASK ""
#define pb push_back
#define F first
#define S second
#define FOR(i, a, b) for (int i=a; i<=b; i++)
#define FOr(i, a, b) for (int i=a; i<b ; i++)
#define FOD(i, a, b) for (int i=a; i>=b; i--)
#define FOd(i, a, b) for (int i=a; i>b ; i--)
#define all(a) a.begin(), a.end()
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef vector<int> vi;

const int N=307;
const int MOD=1e9+7;
const ll INF=(ll)1e18+7;

bitset<N * N> dp[N];
int a[N], gr[N];

int main() {
    #ifdef TriPhan
        freopen("TEST.INP","r",stdin);
        freopen("TEST.OUT","w",stdout);
    #else
        ios_base::sync_with_stdio(0);
        cin.tie(0);
    #endif
    int n;
    cin >> n;
    int sum = 0;
    vector<int> a(n); 
    for (int &x:a) {
        cin >> x;
        sum += x;
    }

    dp[0][0] = 1;
    FOR(i, 1, n)
        dp[i] = dp[i - 1] | (dp[i - 1] << a[i - 1]);

    if (sum % 2 == 0 && dp[n][sum / 2]) {
        sum /= 2;
        for (int i = n; i >= 1; i--)
            if (dp[i - 1][sum] == 0) {
                gr[i] = 1;
                sum -= a[i - 1];
            }
        cout << "Second" << endl;
        int id;
        cin >> id;
        while (id) {
            int choice = 0;
            FOR(i, 1, n)
                if (a[i - 1] != 0 && gr[i] != gr[id])
                    choice = i;
            int dec = min(a[id - 1], a[choice - 1]);
            a[id - 1] -= dec;
            a[choice - 1] -=dec;
            cout << choice << endl;
            cin >> id;
        }
    } else {
        cout << "First" << endl;
        int id = 1;
        while(id) {
            int choice = 0;
            FOR(i, 1, n)
                if (a[i - 1] != 0)
                    choice = i;
            cout << choice << endl;
            cin >> id;
            if (id == 0) break;
            int dec = min(a[id - 1], a[choice - 1]);
            a[id - 1] -= dec;
            a[choice - 1] -= dec;
        }
    }
    return 0;
}