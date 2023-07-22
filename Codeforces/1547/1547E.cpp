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
const int MOD=(int)2e9;
const ll INF=(ll)1e18+7;
ii a[N];
int L[N];
int R[N];
int main() {
    //freopen(TASK".INP","r",stdin);
    //freopen(TASK".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n,k;
        cin >>n >> k;
        FOR(i,1,k)
            cin >> a[i].F;
        FOR(i,1,k)
            cin >> a[i].S;
        FOR(i,0,n+1)
            L[i]=R[i]=MOD;

        FOR(i,1,k) {
            L[a[i].F]=a[i].S+a[i].F; //ti+ |ai-i|=ti+i-ai
            //L[0]=min(L[i],L[a[i].F]);

            R[a[i].F]=a[i].S-a[i].F; //ti+ |ai-i|=ti+ai-i
            //R[n+1]=min(R[n+1],R[a[i].F]);
        }

        FOD(i,n,1)
            L[i]=min(L[i],L[i+1]);
        FOR(i,1,n)
            R[i]=min(R[i-1],R[i]);
        FOR(i,1,n)
            cout << min(L[i]-i,R[i]+i) << " ";
        cout << "\n";


    }
}
