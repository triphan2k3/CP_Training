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

const int N=1e6+7;
const int MOD=1e9+7;
const ll INF=(ll)1e18+7;

vector<int> ans[N];
int a[N], b[N], recover[N], cnt[N];
int n;

int main() {
    #ifdef TriPhan
        freopen("TEST.INP","r",stdin);
        freopen("TEST.OUT","w",stdout);
    #else
        ios_base::sync_with_stdio(0);
        cin.tie(0);
    #endif
    int t;
    cin>> t;
    while (t--) {
        cin >> n;

        FOR(i, 0, n)
            cnt[i] = 0;

        FOR(i, 1, n) {
            cin >> a[i];
            recover[i] = a[i];
            b[i] = 0;
            ++cnt[a[i]];
            ans[i].clear();
        }
        sort(a + 1, a + n + 1);
        reverse(a + 1, a + n + 1);
        int num0 = 0;
        int tn = n;
        int dec = 0;
        int flag = 1;
        for (int i = 1; i <= n; i++) {
            int pos = a[i];
            pos -= dec;
            if (pos > tn) {
                flag = 0;
                break;
            }
            if (pos <= 0) {
                break;
            }
            b[pos] = 1;
            tn = pos - 1;
            dec++;
        }
        if (flag == 0) {
            cout << "NO\n";
            continue;
        }
        FOD(i, n - 1, 1)
            b[i] += b[i + 1];
        b[n + 1] = 0;
        FOR(i, 1, n) {
            int num = b[i + 1];
            if (b[i] > b[i + 1])
                num += i;
                
            if (b[i] > b[i + 1]) // positive
                ans[num].push_back(i);
            else 
                ans[num].push_back(-i);
            cnt[num]--;
        }
        FOR(i, 0, n)
            if (cnt[i] != 0) 
                flag = 0;
        if (flag == 0) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        for (int i = 1; i <= n; i++) {
            cout << ans[recover[i]].back() << " ";
            ans[recover[i]].pop_back();
        }
        cout << "\n";
    }
}