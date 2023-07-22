#include <bits/stdc++.h>
#define TASK ""
#define pb push_back
#define F first
#define S second
#define FOR(i, a, b) for (int i=a; i<=b; i++)
#define FOr(i, a, b) for (int i=a; i<b ; i++)
#define FOD(i, a, b) for (int i=a; i>=b; i--)
#define FOd(i, a, b) for (int i=a; i>b ; i--)
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef vector<iii> viii;

const int N=1e6+7;
const int MOD=1e9+7;
const ll INF=(ll)1e18+7;
int a[N];
int n;

ii mpair(int i,int j) {
    return make_pair(i-j,j);
}
// congsai, start, len
bool check3(int x,int y,int z) {
    return y-x == z-y;
}

viii call(int l,int r) {
    viii ans,tmp;
    int length = r-l+1;
    if (length == 2) {
        ans.pb({mpair(a[l+1],a[l]),2});
        return ans;
    }
    if (length == 3) {
        if (a[l+1]-a[l] == a[l+2]-a[l+1]) {
            ans.pb({mpair(a[l+1],a[l]),3});
            ans.pb({mpair(a[l+2],a[l]),2});
            return ans;
        }
        ans.pb({mpair(a[l+1],a[l]),2});
        ans.pb({mpair(a[l+2],a[l]),2}); 
        ans.pb({mpair(a[l+2],a[l+1]),2});
        return ans;
    }
    if (length == 4) {
        if (a[l+1] == a[l] && a[l+2] == a[l+1] && a[l+3] == a[l+2]) {
             ans.pb({mpair(a[l+1],a[l]),4});
             ans.pb({mpair(a[l+2],a[l]),2});
             ans.pb({mpair(a[l+3],a[l]),2});
             ans.pb({mpair(a[l+3],a[l+1]),2});
             return ans;
        }
        FOR(i,l,l+1) FOR(j,i+1,l+2) FOR(k,j+1,l+3) 
            if (check3(a[i],a[j],a[k])) {
                ans.pb({mpair(a[j],a[i]),3});
                ans.pb({mpair(a[k],a[i]),2});
                int mis = l ^ (l+1) ^ (l+2) ^ (l+3) ^ i ^ j ^ k;
                ans.pb({mpair(a[max(mis,i)],a[min(mis,i)]),2});
                ans.pb({mpair(a[max(mis,j)],a[min(mis,j)]),2});
                ans.pb({mpair(a[max(mis,k)],a[min(mis,k)]),2});
                return ans;
            }
        FOR(i,l,l+2)
            FOR(j,i+1,l+3)
                ans.pb({mpair(a[j],a[i]),2});
        return ans;
        
    }
    length = (length + 1)/2;
    int mid = (r+l)/2;
    viii L = call(l    , mid);
    viii R = call(mid+1, r  );
    // congsai, start, len
    for(iii x:L) {
        int fst = x.F.S;
        int add = x.F.F;
        int len = x.S;
        int value = fst + len*add;
        FOR(i, mid+1, r) 
            if (a[i] == value) {
                value += add;
                len++;
            }
        
        if (len >= length) 
            ans.push_back({{add,fst},len});
    }
    for(iii x:R) {
        int fst = x.F.S;
        int add = x.F.F;
        int len = x.S;
        int value = fst;
        FOD(i, mid, l) 
            if (a[i]==value-add) {
                value -= add;
                len++;
            }
        if (len >= length)
            ans.push_back({{add,value},len});
    }
    sort(ans.begin(),ans.end());
    if (ans.size()) 
        ans.resize(distance(ans.begin(),unique(ans.begin(), ans.end()) ));
    return ans;
}

int main() {
    #ifdef TriPhan
        freopen("TEST.INP","r",stdin);
        freopen("TEST.OUT","w",stdout);
    #else
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    #endif
    cin >> n;
    FOR(i,1,2*n)
        cin >> a[i];
    sort(a+1,a+2*n+1);
    viii ans = call(1,2*n);
    if (ans.size()==0) {
        cout << -1;
        return 0;
    }
    cout << ans[0].F.S << " " << ans[0].F.F;
}