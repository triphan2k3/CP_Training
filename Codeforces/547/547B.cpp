#include <bits/stdc++.h>
#define TASK "547B"
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
int a[N],L[N],R[N],M[N];
int n;
int main() {
    //freopen(TASK".INP","r",stdin);
    //freopen(TASK".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    FOR(i,1,n)
        cin >> a[i];
    stack<int> q;
    q.push(0);
    FOR(i,1,n) {
        while (a[q.top()] >= a[i])
            q.pop();
        L[i]=q.top()+1;
        q.push(i);
    }
    while (q.size())
        q.pop();
    q.push(n+1);
    FOD(i,n,1) {
        while (a[q.top()] >= a[i])
            q.pop();
        R[i]=q.top()-1;
        q.push(i);
    }
    FOR(i,1,n)
        M[R[i]-L[i]+1]=max(M[R[i]-L[i]+1],a[i]);
    FOD(i,n,1)
        M[i]=max(M[i],M[i+1]);
    FOR(i,1,n)
        cout << M[i] << " ";
}
