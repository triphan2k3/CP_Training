#include <bits/stdc++.h>
#define TASK "1451E1"
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
int query(int a,int b,string s) {
    cout << s << " " << a << " " << b << "\n";
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
    int x=query(1,2,"XOR");
    int y=query(2,3,"XOR");
    int z=x^y;
    int a12=x+2*query(1,2,"AND");
    int a23=y+2*query(2,3,"AND");
    int a31=z+2*query(3,1,"AND");
    int a123=(a12+a23+a31)/2;
    a[1]=a123-a23;
    a[2]=a123-a31;
    a[3]=a123-a12;
    FOR(i,4,n)
        a[i]=query(1,i,"XOR")^a[1];

    cout << "! ";
    FOR(i,1,n)
        cout << a[i] << " ";
    cout.flush();
}
