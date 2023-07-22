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
int n0,n1,k;
int a[N],b[N];
int main() {
    //freopen(TASK".INP","r",stdin);
    //freopen(TASK".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n0 >> n1 >> k;

    int n=n0+n1;
    if (n1==1) {
        if (k>0) {
            cout << "No";
            return 0;
        }
        cout << "Yes\n1";
        FOR(i,2,n)
            cout << 0;
        cout << "\n1";
        FOR(i,2,n)
            cout << 0;
        return 0;
    }
    if (n0==0 && k>0) {
        cout << "No";
        return 0;
    }
    if (k>=n-1) {
        cout << "No";
        return 0;
    }
    if (n0==0) {
        cout << "Yes\n";
        string s;
        FOR(i,1,n1)
            s=s+"1";
        cout << s << "\n" << s;
        return 0;
    }
    a[n-k]=b[n]=1;
    a[1]=b[1]=1;
    n1-=2;
    for (int i=2;i<n && n1>0;i++)
        if (a[i]+b[i]==0) {
            a[i]=b[i]=1;
            n1--;
        }
    cout << "Yes\n";
    FOR(i,1,n)
        cout << a[i];
    cout << "\n";
    FOR(i,1,n)
        cout << b[i];
}
