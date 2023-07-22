#include <bits/stdc++.h>
#define TASK "1348C"
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
int main() {
    freopen(TASK".INP","r",stdin);
    freopen(TASK".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        vector<int> a(26,0);
        FOr(i, 0, n)
            a[s[i]-'a']++;
        int fir=-1;
        for (int i=0;fir==-1;i++)
            if (a[i]) fir=i;
        if (a[fir] < k) {
            k-=a[fir];
            int ans;
            for (int i=fir+1;k>0;i++) {
                k-=a[i];
                if (k<=0) ans=i;
            }
            cout<<char(ans+'a') << "\n";
            continue;
        }
        int soloai=0;
        FOr(i,0,26)
            if (a[i]) soloai++;
        if (soloai >= 3) {
            a[fir]-=k;
            cout<<char(fir+'a');
            for (int i=fir;i<26;i++)
                for (int j=0;j<a[i];j++)
                    cout<<char(i+'a');
            cout << "\n";
            continue;
        }

        if (soloai==1) {
            for (int i=0;i*k+1 <= a[fir];i++)
                cout << char(fir+'a');
            cout<<"\n";
            continue;
        }

        int sec;
        for (int i=fir+1;i<26;i++)
            if (a[i]) sec=i;
        a[fir]-=k;

        for (int i=0; i<=a[fir];i++)
            cout<<char('a'+fir);

        if (a[fir]!=0) {
            for (int i=0;i<a[sec];i++)
                cout << char(sec+'a');
            cout << "\n";
            continue;
        }

        for (int i=0;i*k+1 <= a[sec];i++)
                cout << char(sec+'a');
        cout<<"\n";
    }
}
