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

const int N=(int)302;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;

int num[N];
vector<int> pr;
int p[N];
void sieve()
{
    FOR(i, 2, N - 2)
    {
        if (!p[i]) p[i] = i, pr.emplace_back(i);
        for (int j = 0; j < pr.size() && pr[j] <= p[i] && pr[j] * i < N - 1; j++)
            p[i * pr[j]] = pr[j];
    }
}
int main()
{
    sieve();
    for (int p : pr)
    {
        for (int i = p; i < N - 1; i *= p) num[i] = p;
    }
    int t;
    cin >> t;
    while (t--)
    {
        ll n, ans = 0;
        cin >> n;
        ll cur=1;
        if (n==1) {
            cout << "2\n";
            continue;
        }
        if (n==2) {
            cout << "5\n";
            continue;
        }
        FOR(i, 2, 300) if (num[i] > 0) {
            (ans+=i*1LL*(max(0LL, (n / cur - n / (cur * num[i]))) % MOD) % MOD) %= MOD;
            cur *= num[i];
            if (cur > n) break;
        }
        cout << ans << '\n';
    }
}
