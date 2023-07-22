#include <bits/stdc++.h>
#define TASK "1364C"
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
int a[N],ans[N],used[N];
int main() {
    freopen(TASK".INP","r",stdin);
    freopen(TASK".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i=1;i<=n;i++)
        cin >> a[i];
    int check=0;
    for (int i=1;i<=n;i++)
        if (a[i]>i || a[i]<a[i-1]) check=1;
    if (check) {
        cout << -1;
        return 0;
    }
    a[++n]=n;
    for (int i=1;i<=n;i++)
        ans[i]=-1;
    for (int i=2;i<=n;i++)
        if (a[i]>a[i-1]) {
            ans[i]=a[i-1];
            used[a[i-1]]=1;
        }
    int l=0;
    for (int i=1;i<n;i++)
        if (ans[i]==-1) {
            while (used[l]) l++;
            ans[i]=l++;
        }
    for (int i=1;i<n;i++)
        cout << ans[i] << " ";
}
