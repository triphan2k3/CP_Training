#include <bits/stdc++.h>

using namespace std;
int t,n,a,b,c,d,l,r;
int main()
{
    cin >> t;
    while (t--) {
        cin >> n >> a >> b >> c >> d;
        l=(a-b)*n;
        r=(a+b)*n;
        if (l > (c+d) || r < (c-d)) cout<<"No\n";
        else cout<<"Yes\n";
    }
}
