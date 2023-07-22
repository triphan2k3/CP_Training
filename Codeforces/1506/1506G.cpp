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

const int N=(int)1e6+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
int inq[N],appear[N];
int main() {
    //freopen(TASK".INP","r",stdin);
    //freopen(TASK".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n=s.size();
        s="T"+s;
        FOR(i,'a','z')
            appear[i]=0;
        FOD(i,n,1)
            appear[s[i]]=max(appear[s[i]],i);
        vector<int> p;
        FOR(i,'a','z')
            inq[i]=0;
        FOR(i,1,n) if (!inq[s[i]]) {
            inq[s[i]]=1;
            while (p.size() && s[p.back()] < s[i]
                && appear[s[p.back()]] > i) {
                    inq[s[p.back()]]=0;
                    p.pop_back();
                }
            p.push_back(i);
        }
        for (int i:p)
            cout << s[i];
        cout << "\n";

    }
}
