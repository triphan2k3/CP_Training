#include <bits/stdc++.h>
#pragma GCC("O3")
#define ii pair<int, int>
#define pb push_back
#define F first
#define S second
#define FOR(i, a, b) for (int i = a; i <= b; i++)
using namespace std;

const int BLOCK_SIZE = 300;
const int N = 100007;
vector<int> e[N];
vector<int> que[N];
ii queList[N];
int ans[N];
int deg[N];
map<ii, int> edgeid;
vector<int> queFind;
vector<ii> eventA[N], eventR[N];
int nextFind[N];
int tmp[N];
int n, m, q;

int main() {
    freopen("TEST.INP","r",stdin);
    freopen("TEST.OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    // cerr << n << " " << m << endl;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
        deg[u]++;
        deg[v]++;
        if (u > v) swap(u, v);
        edgeid[{u, v}] = i;
    }
    cin >> q;
    FOR(i, 1, q) {
        char c;
        int u;
        cin >> c;
        if (c == '?') {
            queList[i] = {0, 0};
            queFind.pb(i);
        } else {
            cin >> u;
            queList[i].F = (c == '+') ? 1:-1;
            queList[i].S = u;
            que[u].push_back(i);
        }
    }
    int lastFind = -1;
    for (int i = 1; i > 0; i--) {
        if (queList[i].F == 0) {
            lastFind = i;
        }
        nextFind[i] = (lastFind == -1) ? i:lastFind;
    }

    FOR(u, 1, n) if (deg[u] >= BLOCK_SIZE) {
        cerr << u << endl;
        unordered_set<int> U[2];
        int uinU = 0;
        for (int &v:e[u]) {
            if (edgeid[{min(u, v), max(u, v)}] < 0) continue;
            U[0].insert(v);
        }
        FOR(i, 1, q) {
            int type = queList[i].F;
            int id = queList[i].S;
            if (type == 0) {
                if (ans[i] > 0) continue;
                int needCheck = 1;
                if (uinU) {
                    needCheck = 0;
                }
                if (U[needCheck].size()) {
                    int v = *U[needCheck].begin();
                    if (edgeid[{min(u, v), max(u, v)}] > 0)
                        ans[i] = edgeid[{min(u, v), max(u, v)}];
                    edgeid[{min(u, v), max(u, v)}] = -1;
                }
            } else {
                if (edgeid[{min(u, id), max(u, id)}] == 0) continue;
                if (id == u) {
                    uinU ^= 1;
                    continue;
                }
                int flip = 0;
                if (type == -1) {
                    flip = 1;
                }
                U[flip].erase(id);
                U[flip ^ 1].insert(id);
            }
        }
    } 
    FOR(u, 1, n) if (deg[u] < BLOCK_SIZE) {
        // cerr << u << endl;
        vector<int> caredQue;
        for (int v:e[u]) if (deg[v] < BLOCK_SIZE) {
            for (int &x:que[v]) {
                caredQue.push_back(x);
            }
        }
        for (int &x:que[u]) {
            caredQue.push_back(x);
        }
        sort(caredQue.begin(), caredQue.end());

        for (int &x:caredQue) {
            int v = queList[x].second;
            tmp[v] ^= 1;
            if (tmp[v] != tmp[u]) {
                eventA[x].push_back({u, v});
            } else {
                eventR[x].push_back({u, v});
            }
        }
        for (int v:e[u])
            tmp[v] = 0;
        tmp[u] = 0;
    }
    set<ii> event;
    FOR(i, 1, q) {
        for(ii &item:eventA[i]) {
            int u = item.F;
            int v = item.S;
            if (u > v) swap(u, v);
            if (edgeid[{u,v}] < 0) continue;
            event.insert({u, v});
        }
        for(ii &item:eventR[i]) {
            int u = item.F;
            int v = item.S;
            if (u > v) swap(u, v);
            if (edgeid[{u,v}] < 0) continue;
            event.erase({u, v});
        }
        if (queList[i].F == 0 && ans[i] == 0) {
            while (event.size()) {
                ii item = *event.begin();
                event.erase(event.begin());
                int u = item.F;
                int v = item.S;
                if (u > v) swap(u, v);
                if (edgeid[{u,v}] == -1) continue;
                ans[i] = edgeid[{u,v}];
                edgeid[{u,v}] = -1;
                break;
            }
        }
    }
    for (int &x:queFind) {
        cout << ans[x] << "\n";
    }
}