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
int n;
int cnt[30];
int main() {
   // freopen(TASK".INP","r",stdin);
    //freopen(TASK".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    map<int,int> mp;
    ll ans=0;
    FOR(i,1,n) {
        string s;
        cin >> s;
        FOR(i,0,25)
            cnt[i]=0;
        for (int i=0;i<s.size();i++)
            cnt[s[i]-'a']^=1;
        ll state=0;
        FOR(i,0,25)
            if (cnt[i])
                state+=1<<i;
        ans+=mp[state];
        FOR(i,0,25) {
            int tstate=state^(1<<i);
            ans+=mp[tstate];
        }
        mp[state]++;
    }
    cout << ans;
}
