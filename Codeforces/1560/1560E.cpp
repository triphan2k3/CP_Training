#include <bits/stdc++.h>
#define TASK ""
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()
#define ii pair<int,int>
#define iii pair<ii,int>
#define ll long long
#define F first
#define S second
#define sz(x) ((int) (x).size())
#define FOR(i, a, b) for (int i=a; i<=b; i++)
#define FOr(i, a, b) for (int i=a; i<b ; i++)
#define FOD(i, a, b) for (int i=a; i>=b; i--)
#define FOd(i, a, b) for (int i=a; i>b ; i--)
using namespace std;
class dsu {
    public:
    vector<int> p;
    int n;
    dsu(int _n) : n(_n) {
        p.resize(n+1);
        iota(p.begin(), p.end(), 0);
    }
    inline int get(int x) {
        return (x == p[x] ? x : (p[x] = get(p[x])));
    }
    inline bool unite(int x, int y) {
        x = get(x);
        y = get(y);
        if (x != y) {
            p[x] = y;
            return true;
        }
        return false;
    }
};
const int N=1e6+7;
const int MOD=1e9+7;
const ll INF=(ll)1e18+7;
int a[N], cnt[N], valid[N];
int main() {
    #ifdef TriPhan
        freopen("TEST.INP","r",stdin);
        freopen("TEST.OUT","w",stdout);
    #else
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    #endif
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = s.size();
        FOR(i,1,n)
            a[i]=s[i-1]-'a';
        FOR(i,0,25)
            valid[i] = cnt[i] = 0;
        vector<int> p;
        FOD(i,n,1) 
            if (!valid[a[i]]) {
                valid[a[i]]=1;
                p.pb(a[i]);
            }
        reverse(p.begin(),p.end());
        int del = p.size();
        ll dem = 0;
        int cntnum = 0, res = 0;
        FOR(i,1,n) {
            cnt[a[i]]++;
            cntnum += (cnt[a[i]]==1);
            if (cntnum < del) continue;
            dem = 0;
            FOr(j,0,del) 
                dem += 1LL*cnt[p[j]]*(j+1);
            if (dem >= n) {
                res = i;
                break;
            }
        }
        
        if (dem != n) {
            cout << "-1\n";
            continue;
        }
        string t,u,v;
        FOr(i,0,del)
            p[i]+='a';
        FOR(i,1,res)
            u.pb(a[i]+'a');
        t = u;
        string ans = u;
        FOr(i,0,del-1) {
            for(char ch:u)
                if (ch!=p[i])
                    v.pb(ch);
            for(char ch:v)
                t.pb(ch);
            u = v;
            v.clear();
        }
        if (s==t) {
            cout << ans << " ";
            for(int u:p)
                cout << (char)(u);
            cout << "\n";
        } else
            cout << "-1\n";
        
    }
}
