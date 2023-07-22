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
#define matrix vector<vector<ll>>
using namespace std;

const int N=(int)1e6+7;
const ll INF=(ll)1e18+7;
matrix a,r;
ll MOD;
void build_matrix(ll a2) {

    a.resize(4);
    FOr(i,0,4)
        a[i].resize(4);
    a[0][0]=1;  a[0][1]=0;                          a[0][2]=0;  a[0][3]=0;
    a[1][0]=1;  a[1][1]=((a2*a2)%MOD)*4 % MOD;      a[1][2]=1;  a[1][3]=(2LL*a2)%MOD;
    a[2][0]=0;  a[2][1]=1;                          a[2][2]=0;  a[2][3]=0;
    a[3][0]=0;  a[3][1]=4LL*((MOD*MOD-a2)%MOD)%MOD; a[3][2]=0;  a[3][3]=MOD-1;
                //a[1][1]=4LL*a[1][1]%MOD;
                //a[3][1]=(MOD-((4LL*a2)%MOD))%MOD;
    int ijk=1;

    //fi-1 ai^2 ai-1^2 aiai-1
}
void writematrix(matrix a) {
    FOR(i,0,3) {
        FOR(j,0,3)
            cerr << a[i][j] << " ";
            cerr << "\n";
    }
}
void add(ll &a,ll b) {
    b%=MOD;
    a+=b;
    if (a>=MOD)
        a-=MOD;
}
matrix operator *(matrix x,matrix y) {
    matrix c=a;
    FOr(i,0,4)
        FOr(j,0,4) {
            c[i][j]=0;
            FOr(k,0,4)
                c[i][j]=(c[i][j]+x[i][k]*y[k][j])%MOD;
        }
    return c;
}
matrix power(int n) {
    int jjj=1;
    if (n==1)
        return a;
    if (n%2)
        return a*power(n-1);
    matrix p=power(n/2);
    return p*p;
}
int main() {
    freopen(TASK".INP","r",stdin);
    freopen(TASK".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        ll a2,n;
        cin >> a2 >> n >> MOD;
        a2%=MOD;
        build_matrix(a2);
        matrix res=power(n-1);
        ll ans=(res[0][0]*1+res[1][0]*(a2*a2%MOD)+res[2][0]+res[3][0]*a2)%MOD;
        cout << ans << "\n";
    }
}
