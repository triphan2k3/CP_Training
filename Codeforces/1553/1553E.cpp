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
int n,m;
int cnt[N],b[N],a[N],pos[N],ni[N];
int check(int x)
{
    int id=0;
    int num=0;
    FOr(i,n-x,n)
        b[id++] = pos[i];
    FOr(i,0,n-x)
        b[id++] = pos[i];
    // PR(a, 0, n - 1)
    FOr(i,0,n)
        ni[i]=0;
    FOr(i,0,n)
    if (!ni[i])
    {
        num++;
        ni[i]=1;
        for (int u=b[i];u!=i;u=b[u])
            ni[u] = 1;
    }
    // DB(num)
    if (num>=n-m)
        return 1;
    return 0;
}

int main() {
    //freopen(TASK".INP","r",stdin);
    //freopen(TASK".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        FOr(i,0,n)
            cnt[i]=0;
        FOr(i,0,n)
        {
            cin >> a[i];
            a[i]=a[i]-1;
            pos[a[i]] = i;
            int id=(i-a[i]+n)%n;
            cnt[id]++;
        }
        vector<int> ans;
        FOr(i,0,n)
            if (cnt[i]>=n-2*m)
            if(check(i)) ans.push_back(i);

        cout << (int)ans.size() << " ";
        for (int x : ans)
            cout << x << " ";
        cout << "\n";
    }
}
