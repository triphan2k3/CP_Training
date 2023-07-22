#include <bits/stdc++.h>
#define TASK ""
#define pb push_back
#define ll long long
#define ii pair<int,int>
#define pll pair<ll,ll>
#define F first
#define S second
#define FOR(i, a, b) for (int i=a; i<=b; i++)
#define FOr(i, a, b) for (int i=a; i<b ; i++)
#define FOD(i, a, b) for (int i=a; i>=b; i--)
#define FOd(i, a, b) for (int i=a; i>b ; i--)
using namespace std;

typedef array<int,3> iii;


const int N=(int)1e6+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
int n, m, vitri[N];
iii a[N];
int it[N/2], lz[N/2];
void downlz(int i, int l, int r)
{
    if (lz[i]==0) return;
    it[i]+=lz[i];
    if (l==r) return;
    int id=i<<1;
    lz[id]+=lz[i];
    lz[id|1]+=lz[i];
    lz[i] = 0;
}
void update(int i,int l,int r,int L,int R,int x)
{
    downlz(i, l, r);
    if (l>R || r<L) return;
    if (L<=l && r<=R)
    {
        lz[i]+=x;
        downlz(i,l,r);
        return;
    }
    int m=(l+r)>>1;
    int id=i<<1;
    update(id,l,m,L,R,x);
    update(id|1,m+1,r,L,R,x);
    it[i] = min(it[id], it[id|1]);
}

int main()
{
    cin >>n>>m;
    FOR(i,1,n){
        vitri[i]=i;
        int x,y,z;
        cin>>x>>y>>z;
        a[i] = {x,y-1, z};
    }
    sort(vitri + 1, vitri + 1 + n, [&](const int &A, const int &B)
    {
        return a[A][2] < a[B][2];
    });
    int l=1,ans=N;
    FOR(i,1,n)
    {
        update(1,1,m-1,a[vitri[i]][0],a[vitri[i]][1],1);
        while (l<=i)
        {
            downlz(1,1,m-1);
            if (it[1]>0)
                ans=min(ans,a[vitri[i]][2]-a[vitri[l]][2]);
            else break;
            update(1, 1, m - 1, a[vitri[l]][0], a[vitri[l]][1], -1);
            l++;
        }
        downlz(1,1,m-1);
        int ret = it[1];
        ans = ret>0? min(ans, a[vitri[i]][2] - a[vitri[l]][2]):0;
    }
    cout << ans;
    return 0;
}
