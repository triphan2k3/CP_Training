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
typedef pair<ii, ii> iiii;
typedef vector<int> vi;

const int N=1e6+7;
const int MOD=1e9+7;
const ll INF=(ll)1e18+7;

bool cmp(iiii &a, iiii &b) {
    return a.S < b.S;
}

int main() {
    #ifdef TriPhan
        freopen("TEST.INP","r",stdin);
        freopen("TEST.OUT","w",stdout);
    #else
        ios_base::sync_with_stdio(0);
        cin.tie(0);
    #endif
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<iiii> a(n);
        for (iiii &x:a) {
            cin >> x.F.F >> x.F.S >> x.S.F >> x.S.S;
        }
        sort(all(a), cmp);
        vector<ii> event;
        for (int i = 0; i < n; i++) {
            event.push_back({a[i].F.F, i});
            event.push_back({a[i].F.S + 1, - i - 1});
        }

        int q; cin >> q;
        vector<int> query(q);
        for (int i = 0; i < q; i++) {
            cin >> query[i];
            event.push_back({query[i], i + N});
        }
        sort(all(event));
        int maxMove = 0;
        vector<int> curQ;
        for (ii x:event) {
            int pos = x.F;
            int type = x.S;
            if (type >= N) {
                int id = type - N;
                if (pos > maxMove) {
                    continue;
                }
                curQ.push_back(id);
            } else if (type < 0) {
                continue;
            } else {
                if (a[type].F.F > maxMove) {
                    while (curQ.size()) {
                        query[curQ.back()] = maxMove;
                        curQ.pop_back();
                    }
                }
                maxMove = max(maxMove, a[type].S.S);
            }
        }
        while (curQ.size()) {
            query[curQ.back()] = maxMove;
            curQ.pop_back();
        }

        for (int x:query)
            cout << x << " ";
        cout << "\n";
    }
}