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
int a[300];
int main() {
    //freopen(TASK".INP","r",stdin);
    //freopen(TASK".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n=s.size();
        FOR(i,0,25)
            a[i]=0;
        s=" "+s;
        int ans=1;
        int st=0;
        FOR(i,1,n) {
            int id=s[i]-'a';
            a[id]++;
            if (s[i]=='a')
                st=i;
            if (a[id]==2)
                ans=0;
        }
        FOR(i,1,n)
            if (a[i-1]==0)
                ans=0;
        int l=st,r=st;
        s=s+" ";
        FOR(i,1,n-1) {
            int ch='a'+i;
            if (s[l-1]==ch) {
                l--;
                continue;
            }
            if (s[r+1]==ch) {
                r++;
                continue;
            }
            ans=0;
        }
        if (ans) {
            cout << "YES\n";
        }
        else
            cout << "NO\n";

    }
}
