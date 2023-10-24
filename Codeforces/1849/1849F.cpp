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

struct Node
{
    int cnt, val, id, left, right;
    Node()
    {
        cnt = 0;
        val = 0;
        left = -1;
        right = -1;
    }
};

class Trie
{
public:
    vector<Node> storage;
    int curIndex;
    const int NBit = 30;
    Trie()
    {
        curIndex = 0;
        storage.resize(5 * N);
    }

    vector<int> convertToBits(int v)
    {
        vector<int> bits(30);
        for (int i = 0; i < 30; i++)
            bits[29 - i] = (v >> i) & 1;
        return bits;
    }

    void addInt(int v, int id)
    {
        vector<int> bits = this->convertToBits(v);
        int cur = 0;
        storage[cur].cnt++;
        for (int i = 0; i < 30; i++)
        {
            if (bits[i] == 0)
            {
                if (storage[cur].left == -1)
                    storage[cur].left = ++curIndex;
                cur = storage[cur].left;
                storage[cur].cnt++;
            }
            else
            {
                if (storage[cur].right == -1)
                    storage[cur].right = ++curIndex;
                cur = storage[cur].right;
                storage[cur].cnt++;
            }
        }
        storage[cur].val = v;
        storage[cur].id = id;
    }

    void removeInt(int v)
    {
        vector<int> bits = this->convertToBits(v);
        int cur = 0;
        storage[cur].cnt--;
        for (int i = 0; i < 30; i++)
        {
            if (bits[i] == 0)
            {
                cur = storage[cur].left;
                storage[cur].cnt--;
            }
            else
            {
                cur = storage[cur].right;
                storage[cur].cnt--;
            }
        }
    }

    int findMinXor(int v)
    {
        vector<int> bits = this->convertToBits(v);
        int cur = 0;
        if (storage[0].cnt <= 0)
            return -1;
        for (int i = 0; i < 30; i++)
        {
            int leftId = storage[cur].left;
            int rightId = storage[cur].right;
            if (bits[i] == 0)
            {
                if (leftId != -1 && storage[leftId].cnt > 0)
                    cur = leftId;
                else
                    cur = rightId;
            }
            else
            {
                if (rightId != -1 && storage[rightId].cnt > 0)
                    cur = rightId;
                else
                    cur = leftId;
            }
        }
        return storage[cur].id;
    }
};

class Dsu
{
public:
    vector<int> p;
    int n;
    Dsu(int _n) : n(_n)
    {
        p.resize(n + 1);
        iota(p.begin(), p.end(), 0);
    }
    int get(int x)
    {
        return (p[x] == x ? x : (p[x] = get(p[x])));
    }
    bool unite(int x, int y)
    {
        x = get(x);
        y = get(y);
        if (x == y)
            return false;
        p[x] = y;
        return true;
    }
    bool same(int x, int y)
    {
        return get(x) == get(y);
    }
};

vector<int> e[N];
int cor[N];
void color(int u, int p = 0)
{
    for (int v : e[u])
        if (v != p)
        {
            cor[v] = cor[u] ^ 1;
            color(v, u);
        }
}

int main()
{
#ifdef TriPhan
    freopen("TEST.INP", "r", stdin);
    freopen("TEST.OUT", "w", stdout);
#else
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif
    int n;
    cin >> n;
    vector<int> a(n + 1);
    Trie trie;
    Dsu dsu(n);
    vector<vector<int>> component(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        trie.addInt(a[i], i);
        component[i].push_back(i);
    }

    while (true)
    {
        vector<int> componentList;
        for (int i = 1; i <= n; i++)
            if (dsu.get(i) == i)
                componentList.push_back(i);
        if (componentList.size() == 1)
            break;
        vector<ii> edges;
        for (int &u : componentList)
        {
            vector<int> &v = component[u];
            for (int &i : v)
            {
                trie.removeInt(a[i]);
            }
            int minXorId = -1;
            int minXor = 1 << 30;
            for (int &i : v)
            {
                int j = trie.findMinXor(a[i]);
                if (j == -1)
                    continue;
                int curXor = a[i] ^ a[j];
                if (curXor < minXor)
                {
                    minXor = curXor;
                    minXorId = i;
                }
            }
            if (minXorId == -1)
                continue;
            edges.push_back({minXorId, trie.findMinXor(a[minXorId])});

            for (int &i : v)
            {
                trie.addInt(a[i], i);
            }
        }
        for (ii edge : edges)
        {
            int u = edge.first;
            int v = edge.second;
            if (dsu.same(u, v))
                continue;
            e[u].pb(v);
            e[v].pb(u);
            u = dsu.get(u);
            v = dsu.get(v);
            dsu.unite(v, u);
            for (int vv : component[v])
                component[u].push_back(vv);
            component[v].clear();
            
        }
    }
    color(1);
    for (int i = 1; i <= n; i++)
        cout << cor[i];
}