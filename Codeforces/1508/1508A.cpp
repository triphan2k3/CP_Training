#include <bits/stdc++.h>
#define TASK "1508A"
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
ii cnt[3];
int main() {
    freopen(TASK".INP","r",stdin);
    freopen(TASK".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        string s[3];
        cin >> n;
        cin >> s[0] >> s[1] >> s[2];
        cnt[0].F=cnt[1].F=cnt[2].F=0;
        cnt[0].S=0;
        cnt[1].S=1;
        cnt[2].S=2;

        FOr(i,0,2*n) {
            cnt[0].F+=s[0][i]-'0';
            cnt[1].F+=s[1][i]-'0';
            cnt[2].F+=s[2][i]-'0';
        }
        // case zero bigger
        sort(cnt,cnt+3);
        if (cnt[1].F <= n) {
            int couting=0;
            vector<int> p;
            int id=cnt[1].S;
            FOr(i,0,2*n)
                if (s[id][i]=='1')
                    p.push_back(couting);
                else
                    couting++;
            reverse(p.begin(),p.end());
            couting=0;
            id=cnt[0].S;
            FOr(i,0,2*n) {
                while (p.size() && p.back()==couting)
                    {
                        cout << 1;
                        p.pop_back();
                    }
                cout << s[id][i];
                if (s[id][i]=='0')
                    couting++ ;
            }
            while (p.size() && p.back()==couting)
                {
                    cout << 1;
                    p.pop_back();
                }
            cout << "\n";
            continue;
        }

        reverse(cnt,cnt+3);
        int couting=0;
            vector<int> p;
            int id=cnt[1].S;
            FOr(i,0,2*n)
                if (s[id][i]=='0')
                    p.push_back(couting);
                else
                    couting++;
            reverse(p.begin(),p.end());
            couting=0;
            id=cnt[0].S;
            FOr(i,0,2*n) {
                while (p.size() && p.back()==couting) {
                        cout << 0;
                        p.pop_back();
                    }
                cout << s[id][i];
                if (s[id][i]=='1')
                    couting++ ;
            }
            while (p.size() && p.back()==couting) {
                        cout << 0;
                        p.pop_back();
                    }
            cout << "\n";
    }
}
