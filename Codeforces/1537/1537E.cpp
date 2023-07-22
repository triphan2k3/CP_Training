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
int n,k;
int F[N];
string s;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> k >> s;
    if (s.size() > k)
        s = s.substr(0, k);
    n = s.size();
    int Left=0;
    int Right=0;
    FOR(i,1,n-1) {
        if (i>Right) {
            Left=Right=i;
            while (Right<n && s[Right-i]==s[Right])
                Right++;
            F[i]=Right-i;
            --Right;
        }
        else {
            int t=i-Left;
            if (F[t]<Right-i+1) F[i]=F[t];
            else {
                Left=i;
                while (Right<n && s[Right-i]==s[Right]) ++Right;
                F[i]=Right-i;
                --Right;
            }
        }
    }
    FOR(i,1,n-1) {
        int t=F[i];
        if ((t<i && s[t]<s[i+t])) {
            s=s.substr(0, i);
            while (s.size() < k)
                s += s;
            if (s.size()> k) s=s.substr(0, k);
            cout << s;
            return 0;
        }

    }
    while (s.size() < k)
        s+=s;
    if (s.size() > k) s = s.substr(0, k);
    cout << s;
}
