#include <bits/stdc++.h>
#define TASK ""
#define pb push_back
#define F first
#define S second
#define FOR(i, a, b) for (int i=a; i<=b; i++)
#define FOr(i, a, b) for (int i=a; i<b ; i++)
#define FOD(i, a, b) for (int i=a; i>=b; i--)
#define FOd(i, a, b) for (int i=a; i>b ; i--)
#define all(a) a.begin(), a.end()
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef vector<int> vi;

const int N=1e6+7;
const int MOD=1e9+7;
const ll INF=(ll)1e18+7;

vector<string> a[26];

int main() {
    #ifdef TriPhan
        freopen("TEST.INP","r",stdin);
        freopen("TEST.OUT","w",stdout);
    #else
        ios_base::sync_with_stdio(0);
        cin.tie(0);
    #endif
    string s;
    cin >> s;
    int n = s.size();
    s = s + s;
    FOr(i, 0, n) 
        a[s[i] - 'a'].push_back(s.substr(i, n));
    
    int wins = 0;
    FOr(ch, 0, 26) { // type start character
        int win = 0;
        FOr(i, 1, n) { // position
            vector<int> cnt(26, 0);
            for (int j = 0; j < a[ch].size(); j++) // count at this position
                cnt[a[ch][j][i] - 'a']++;
            int unique = 0;
            for (int x:cnt) // count unique
                if (x == 1) ++unique;
            win = max(win, unique); // win at this position
        }
        wins += win; // add num win of this group to total win
    }
    cout<< setprecision(6) << fixed << (double)wins / n;
    

}