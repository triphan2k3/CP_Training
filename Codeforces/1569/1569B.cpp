#include <bits/stdc++.h>
#define TASK ""
#define pb push_back
#define F first
#define S second
#define FOR(i, a, b) for (int i=a; i<=b; i++)
#define FOr(i, a, b) for (int i=a; i<b ; i++)
#define FOD(i, a, b) for (int i=a; i>=b; i--)
#define FOd(i, a, b) for (int i=a; i>b ; i--)
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef vector<int> vi;

const int N=1e6+7;
const int MOD=1e9+7;
const ll INF=(ll)1e18+7;
int a[100][100];
int main() {
    #ifdef TriPhann
        freopen("TEST.INP","r",stdin);
        freopen("TEST.OUT","w",stdout);
    #else
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    #endif
    int t; cin >> t;
    while (t--) {
        int n; string s;
        cin >> n >> s;
        s = "#" + s;
        FOR(i,1,n) FOR(j,1,n) a[i][j]=0;
        vector<int> v;
        FOR(i,1,n) 
            if (s[i]=='2') 
                v.pb(i);
        if (v.size()==1 || v.size()==2) {
            cout << "NO\n"; continue;
        }
        //for(int x:v) cout << x << " ";
        //cout << "\n\n";
        cout<< "YES\n";
        int m = v.size()-1;
        if (v.size()) v.pb(v[0]);
        FOR(i,0,m) {
            a[v[i]][v[i+1]]=1;
            a[v[i+1]][v[i]]=-1;
        }
        FOR(i,1,n) {
            FOR(j,1,n) 
                if (i==j) cout << 'X';
                else if (a[i][j]==0) cout << '=';
                else if (a[i][j]==1) cout << '+';
                else cout << '-';
            cout << "\n";
        }
        


    }
}