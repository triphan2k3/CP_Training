#include <bits/stdc++.h>
#define TASK ""
#define pb push_back
#define F first
#define S second
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define FOr(i, a, b) for (int i = a; i < b; i++)
#define FOD(i, a, b) for (int i = a; i >= b; i--)
#define FOd(i, a, b) for (int i = a; i > b; i--)
#define all(a) a.begin(), a.end()
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef vector<int> vi;

const int N = 1e6 + 7;
const int MOD = 1e9 + 7;
const ll INF = (ll)1e18 + 7;

int main()
{
#ifdef TriPhan
    freopen("TEST.INP", "r", stdin);
    freopen("TEST.OUT", "w", stdout);
#else
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int flag = 0;
        string a, b;
        for (char ch : s)
        {
            int num = ch - '0';
            int toA = num / 2;
            int toB = num / 2;
            if (num % 2)
            {
                if (flag == 1)
                    toA++;
                else
                    toB++;
                flag ^= 1;
            }
            if (a.size() != 0 || toA != 0)
                a.push_back(toA + '0');
            if (b.size() != 0 || toB != 0)
                b.push_back(toB + '0');
        }
        if (a.size() == 0)
            a = "0";
        if (b.size() == 0)
            b = "0";
        cout << a << " " << b << "\n";
    }
}