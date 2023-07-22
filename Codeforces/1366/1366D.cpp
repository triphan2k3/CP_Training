#include <bits/stdc++.h>
#define TASK "1366D"
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

const int N=(int)1e5+7;
const int P=(int)1e7+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
int a[N],p[P],ans[N][2];
int main() {
    freopen(TASK".INP","r",stdin);
    freopen(TASK".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for (int i=2;i*i<=P;i++)
        if (p[i]==0)
        for (int j=i*i;j<=10000000;j+=i)
            if (p[j]==0) p[j]=i;
    for (int i=2;i<=10000000;i++)
        if (p[i]==0) p[i]=i;
    int n;
    cin >> n;
    for (int i=1;i<=n;i++)
        cin>>a[i];

    for (int i=1;i<=n;i++) {
        int st=p[a[i]];
        int t=a[i];
        if (a[i]%2) {
            while (a[i]%st==0)
                a[i]/=st;
            if (a[i]==1)
                ans[i][0]=ans[i][1]=-1;
            else {
                int nd=p[a[i]];
                ans[i][0]=st;
                ans[i][1]=nd;
            }
        }
        else {
            int nd=0;
            while (a[i]%2==0)
                a[i]/=2;
            if (a[i]>1) {
                ans[i][0]=st;
                ans[i][1]=a[i];
            }
            else
                ans[i][0]=ans[i][1]=-1;
        }

    }
    for (int i=1;i<=n;i++)
        cout<<ans[i][0]<<" ";
    cout << "\n";
    for (int i=1;i<=n;i++)
        cout<<ans[i][1]<<" ";

}
