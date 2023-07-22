#include <bits/stdc++.h>
#define TASK "1352F"
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
        int a, b, c;
        cin >> a >> b >> c;
        deque<int> q;
        if (a)
        FOR(i,1,a+1)
            q.push_back(0);
        if (c)
        FOR(i,1,c+1)
            q.push_back(1);
        if (a && c) --b;
        if (!(a+c)) q.push_back(0);
        FOR(i,1,b)
            q.push_front(q.front()^1);
        for (int i:q)
            cout << i;
        cout << "\n";
    }
}
