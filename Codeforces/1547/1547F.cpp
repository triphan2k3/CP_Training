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
int p[N];
int a[N];
int last[N];
int cnt[N];
int valid[N];

void sang() {
    for (int i=2;i*i<=1000000;i++)
        if (!p[i]) {
            p[i]=i;
            for (int j=i*i;j<=1000000;j+=i)
                p[j]=i;
        }
    FOR(i,2,1000000)
        if (!p[i])
            p[i]=i;
}
int Gcd(int A, int B) {
    if (B == 0) return A;
    else return Gcd(B, A % B);
}
int main() {
    freopen(TASK".INP","r",stdin);
    //freopen(TASK".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    sang();
    while (t--) {
        int n;
        cin >> n;
        FOR(i,1,n)
            cin >> a[i];

        int ck=1;
        FOR(i,1,n-1) {
            if (a[i]!=a[i+1])
                ck=0;
        }
        if (ck) {
            cout << "0\n";
            continue;
        }
        int gcd=a[1];
        FOR(i,2,n)
            gcd=Gcd(a[i],gcd);
        FOR(i,1,n)
            a[i]/=gcd;
        //FOR(i,1,1000000)
            //cnt[i]=last[i]=0;

        FOR(i,1,n)
            a[n+i]=a[i];
        //a[n+1]=a[1];
        int ans=1;
        vector<int> xh;
        FOR(i,1,n+n) {
            int m=a[i];
            while (m>1) {
                int uoc=p[m];
                while (m%uoc==0)
                    m/=uoc;
                if (last[uoc]==i-1) {
                    cnt[uoc]++;
                    ans=max(ans,cnt[uoc]);
                }
                else
                    cnt[uoc]=1;
                last[uoc]=i;
                if (!valid[uoc]) {
                    valid[uoc]=1;
                    xh.push_back(uoc);
                }
            }
        }
        ans=min(ans,n-1);
        for(int i:xh) {
            valid[i]=cnt[i]=last[i]=0;
        }
        cout << ans << "\n";

    }
}
