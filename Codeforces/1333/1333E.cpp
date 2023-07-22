#include <bits/stdc++.h>
#define TASK "1333E"
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
    int n;
    cin >> n;
    if (n<3) {
        cout << -1;
        return 0;
    }
    vector<int> a[n+1];
    for (int i=0;i<=n;i++)
        a[i].resize(n+1);
    a[1][1]=1;
    a[1][2]=5;
    a[1][3]=4;
    a[2][1]=3;
    a[2][2]=8;
    a[2][3]=2;
    a[3][1]=9;
    a[3][2]=7;
    a[3][3]=6;
    int cnt=9;
    FOR(row,4,n) {
        if (row % 2) {
            FOR(i,1,row)
                a[i][row]=++cnt;
            FOD(i,row-1,1)
                a[row][i]=++cnt;
        }
        else {
            FOR(i,1,row)
                a[row][i]=++cnt;
            FOD(i,row-1,1)
                a[i][row]=++cnt;
        }
    }
    int all=n*n+1;
    FOR(i,1,n) {
        FOR(j,1,n)
            cout<<all-a[i][j]<<" ";
        cout<<"\n";
    }
    return 0;
}
