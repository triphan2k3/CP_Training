#include <bits/stdc++.h>
#define TASK "1451E2"
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
int n;
int a[N];
vector<ii> x;
int query(int i,int j,string s) {
    cout << s << " " << i << " " << j << "\n";
    cout.flush();
    int x; cin >> x;
    return x;
}
int main() {
    //freopen(TASK".INP","r",stdin);
    //freopen(TASK".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    FOR(i,2,n)
        x.push_back({query(1,i,"XOR"),i});

    sort(x.begin(),x.end());
    int tmp=0;
    FOR(i,1,n-2)
        if (x[i].F == x[i-1].F)
            tmp=i;
    if (tmp || x[0].F==0) {
        int i=tmp ? x[tmp-1].S:1;
        int j=x[tmp].S;
        a[i]=a[j]=query(i,j,"AND");
        a[1]=tmp ? x[tmp].F^a[i]:a[1];
        FOR(i,0,n-2)
            a[x[i].S]=a[1]^x[i].F;
    } else {
        int i=x[n-2].S;
        int j=x[0].S;
        //a1^ai = n-1 a1&ai = 0 a1^aj = 1
        int a1i=n-1;
        int a1j=1 + 2*query(1,j,"AND");
        int aij=(n-2)+2*query(i,j,"AND");
        a[1]=(a1i+a1j+aij)/2-aij;
        FOR(i,0,n-2)
            a[x[i].S]=a[1]^x[i].F;
    }
    cout << "! ";
    FOR(i,1,n)
        cout << a[i] << " ";
    cout.flush();
}
