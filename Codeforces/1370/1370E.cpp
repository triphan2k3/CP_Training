#include <bits/stdc++.h>

using namespace std;

int n;
string s, t;

int main() {
    freopen("1370E.INP","r",stdin);
    freopen("1370E.OUT","w",stdout);
    cin >> n >> s >> t;
    if (count(s.begin(), s.end(), '0') != count(t.begin(), t.end(), '0')) {
        puts("-1");
        return 0;
    }
    int c[2];
    c[0] = c[1] = 0;
    for (int i = 0; i < n; i++) if (s[i] != t[i]) {
        int idx = s[i] - '0';
        c[idx]++; c[idx ^ 1]--;
        if (c[0] < 0) c[0] = 0;
        if (c[1] < 0) c[1] = 0;
    }
    cout << c[0] + c[1];
}
