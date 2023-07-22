#include <bits/stdc++.h>
#define TASK "1010D"
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
int a[N],b[N];
string type[N];
bool c[N],e[N][2];
int n;
int d(string s,bool a,bool b) {
    if (s=="AND")
        return a&&b;
    if (s=="OR")
        return a||b;
    if (s=="XOR")
        return a^b;
    if (s=="NOT")
        return !a;
}
void dfs(int i) {
    if (type[i]=="IN") {
        c[i]=a[i];
        return;
    }
    dfs(a[i]);
    if (type[i]=="NOT") {
        c[i]=!c[a[i]];
        return;
    }
    dfs(b[i]);
    c[i]=d(type[i],c[a[i]],c[b[i]]);
}

void fdfs(int i,int j) {
    if (j!=0) {
        e[i][0]=e[j][d(type[j],0,c[a[j]^i^b[j]])];
        e[i][1]=e[j][d(type[j],1,c[a[j]^i^b[j]])];
    }
    if (type[i]=="IN")
        return;
    fdfs(a[i],i);
    if (type[i]=="NOT")
        return;
    fdfs(b[i],i);
}
int main() {
    freopen(TASK".INP","r",stdin);
    freopen(TASK".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    FOR(i,1,n) {
        cin >> type[i] >> a[i];
        if (type[i]=="IN" || type[i]=="NOT")
            continue;
        cin >> b[i];
    }
    dfs(1);
    e[1][1]=1;
    fdfs(1,0);
    FOR(i,1,n)
        if (type[i]=="IN")
            cout << e[i][a[i]^1];

}
