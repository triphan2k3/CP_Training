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
vector<int> a[20];
int mask[41][26];
int dp[41][1 << 21];
int n;

int call(int dia = 0, int curMask = 1, int ch = a[0][0]) {
    int secondd = dia % 2;
    

    if (dp[dia][curMask] != MOD)
        return dp[dia][curMask];

    int ans = MOD;
    if (dia == 2 * n - 2)
        ans = 0;
    else
        for (int nextCh = 0; nextCh < 26; nextCh++) {
            int nextMask = (curMask | (curMask << 1)) & mask[dia + 1][nextCh];
            if (nextMask != 0)
                ans = min(ans, -call(dia + 1, nextMask, nextCh));
        }
    if (secondd) {
        if (ch == 0)
            ans--;
        else if (ch == 1)
            ans++;
    } else {
        if (ch == 0)
            ans++;
        else if (ch == 1)
            ans--;
    }
    return dp[dia][curMask] = ans;
}

int main() {
    #ifdef TriPhan
        freopen("TEST.INP","r",stdin);
        freopen("TEST.OUT","w",stdout);
    #else
        ios_base::sync_with_stdio(0);
        cin.tie(0);
    #endif
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (char ch:s)
            a[i].push_back(ch - 'a');
    }
    for (int i = 0; i < 41; i++) for (int j = 0; j < (1 << 21); j++) dp[i][j] = MOD;
    for (int ch = 0; ch < 26; ch++) {
        for (int dia = 0; dia < 2 * n - 1; dia++)
            for (int i = 0; i < n; i++) {
                int j = dia - i;
                if (j >= 0 && j < n && a[i][j] == ch)
                    mask[dia][ch] |= (1 << i);
            }
    }
    int ans = call();
    if (ans > 0)
        cout << "FIRST";
    else if (ans < 0)
        cout << "SECOND";
    else 
        cout << "DRAW";
}